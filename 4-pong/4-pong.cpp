// 4-pong.cpp : Defines the entry point for the application.
//

#include "4-pong.h"
#include <glad/glad.h>
#include "static.h"
#include "Player.h"
#include "Ball.h"
#include "Gravity.h"
#include "shaders/Shaders.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

using namespace std;


void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int processMovement(GLFWwindow *window) {

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        return 1;
    } else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        return -1;
    } else {
        return 0;
    }
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

    Player left = Player(glm::highp_dvec2(-0.95f, 0), glm::highp_dvec2(0, 0), VERTICAL, 1.0f);
    Player right = Player(glm::highp_dvec2(0.95f, 0), glm::highp_dvec2(0, 0), VERTICAL, 1.0f);
    Ball ball = Ball(glm::highp_dvec2(0, 0), glm::highp_dvec2(-1.0f, 0.9f), 1.0f);


    vector<GameObject *> objects;

    objects.push_back(&right);
    objects.push_back(&left);
    objects.push_back(&ball);

    for (GameObject *object: objects) {
        object->init_buffer_data();
    }

    double last_time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {

        processInput(window);
        int move = processMovement(window);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(Shaders::program_shader);

        double time = glfwGetTime();
        double delta = time - last_time;

        left.update_direction(0.0f, move);
        right.update_direction(0.0f, move);


        for (GameObject *object: objects) {
            object->update_position(delta);

            bool x_bounds = object->check_x_bounds();
            bool y_bounds = object->check_y_bounds();

            if (Player *p = dynamic_cast<Player *>(object)) {

                bool collision = p->check_collision(ball);
                if (collision) {
                    ball.invert_x_direction();
                }
            } else if (Ball *b = dynamic_cast<Ball *>(object)) {
                if (x_bounds)
                    b->update_position(0, 0);
                if (y_bounds)
                    b->invert_y_direction();

            }

            object->draw();
        }


        last_time = time;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    for (GameObject *object: objects) {
        object->delete_buffer_data();
    }

    glfwTerminate();
    return 0;
}
