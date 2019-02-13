// 4-pong.cpp : Defines the entry point for the application.
//

#include "4-pong.h"
#include <glad/glad.h>
#include "static.h"
#include "Gravity.h"
#include "shaders/Shaders.h"
#include "game_objects/GameObject.h"
#include "controllers/Controller.h"
#include "controllers/PaddleController.h"
#include "controllers/BallController.h"
#include "players/HumanPlayer.h"
#include "Collisions.h"
#include "players/AiPlayer.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <map>

using namespace std;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void process_global_input(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    glfwInit();

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "4 Pong", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shaders::load_built_in_shaders();


    map<int,Player *> players;
//    players[1] = new HumanPlayer(1, window, GLFW_KEY_UP, GLFW_KEY_DOWN);
//    players[2] = new HumanPlayer(2, window, GLFW_KEY_W, GLFW_KEY_S);

    players[1] = new AiPlayer(1);
    players[2] = new AiPlayer(2);
    players[3] = new AiPlayer(3);
    players[4] = new AiPlayer(4);


    vector<Controller *> controllers;
    controllers.push_back(new BallController(0));
    controllers.push_back(new PaddleController(1));
    controllers.push_back(new PaddleController(2));
//    controllers.push_back(new PaddleController(3));
//    controllers.push_back(new PaddleController(4));


    map<int, glm::highp_dvec2*> positionsMap;

    for (Controller *controller: controllers) {
        controller->gameObject->init_buffer_data();
        positionsMap[controller->id] = &controller->gameObject->position;
    }



    double last_time = glfwGetTime();



    while (!glfwWindowShouldClose(window)) {

        process_global_input(window);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(Shaders::program_shader);

        double time = glfwGetTime();
        double delta = time - last_time;


        for (Controller *controller: controllers) {
            if(auto * pc = dynamic_cast<PaddleController*>(controller))
            {
                int move = players[controller->id]->next_move(positionsMap);

                pc->move(move, delta);
                Collisions::handle_bounds(pc);
                Collisions::handle_collision(pc, dynamic_cast<BallController*>(controllers[0]));
            }
            else if(auto * bc = dynamic_cast<BallController*>(controller)) {
                bc->move(delta);
                Collisions::handle_bounds(bc);
            }
            else {
                throw "Error";
            }

            controller->gameObject->draw();
        }


        last_time = time;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    for (Controller *controller: controllers) {
        controller->gameObject->delete_buffer_data();
    }

    glfwTerminate();
    return 0;
}
