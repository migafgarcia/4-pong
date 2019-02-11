// 4-pong.cpp : Defines the entry point for the application.
//

#include "4-pong.h"
#include <glad/glad.h>
#include "static.h"
#include "Gravity.h"
#include "shaders/Shaders.h"
#include "game_objects/GameObject.h"
#include "controllers/HumanPlayer.h"

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

    GameObject left = GameObject(1, glm::highp_dvec2(-0.95f, 0), glm::highp_dvec2(0.03f, 0.25f));
    GameObject right = GameObject(2, glm::highp_dvec2(0.95f, 0), glm::highp_dvec2(0.03f, 0.25f));
    GameObject ball = GameObject(0, glm::highp_dvec2(0, 0), glm::highp_dvec2(0.05f, 0.05f));

    vector<GameObject *> players;

    players.push_back(&right);
    players.push_back(&left);
    players.push_back(&ball);

    for (GameObject *object: players) {
        object->init_buffer_data();
    }

    double last_time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {

        process_global_input(window);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(Shaders::program_shader);

        double time = glfwGetTime();
        double delta = time - last_time;




        for (GameObject *object: players) {
            object->draw();
        }

        last_time = time;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    for (GameObject *object: players) {
        object->delete_buffer_data();
    }

    glfwTerminate();
    return 0;
}
