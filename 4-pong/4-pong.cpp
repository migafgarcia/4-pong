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

const char *vertexShaderSource = "#version 140\n"
                                 "in vec3 aPos;\n"
                                 "in vec2 aTexCoord;\n"
                                 "uniform mat4 transform;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 140\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(0.5f, 0.75f, 0.25f, 1.0f);\n"
                                   "}\n\0";

void compile_vertex_shader(unsigned int &vertex_shader) {
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertex_shader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

}

void compile_fragment_shader(unsigned int &fragment_shader) {
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragment_shader);

    int success;
    char infoLog[512];
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void
link_shaders(const unsigned int &vertex_shader, const unsigned int &fragment_shader, unsigned int &shader_program) {

    shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);


    int success;
    char infoLog[512];
    glGetShaderiv(shader_program, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader_program, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
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


void compile_shaders() {
    unsigned int vertex_shader;
    compile_vertex_shader(vertex_shader);

    unsigned int fragment_shader;
    compile_fragment_shader(fragment_shader);

    unsigned int shader_program;
    link_shaders(vertex_shader, fragment_shader, shader_program);

    Shaders::program_shader = shader_program;

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
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

    compile_shaders();

    Player left = Player(glm::highp_dvec2(-0.95f, 0), glm::highp_dvec2(0, 0), VERTICAL, 1.0f);

    Player right = Player(glm::highp_dvec2(0.95f,0), glm::highp_dvec2(0,0), VERTICAL, 1.0f);
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
                if(collision)
                    ball.invert_x_direction();




            } else if (Ball *b = dynamic_cast<Ball *>(object)) {
                if(x_bounds)
                    b->update_position(0, 0);
                if(y_bounds)
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
