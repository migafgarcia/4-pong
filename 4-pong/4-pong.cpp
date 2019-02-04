// 4-pong.cpp : Defines the entry point for the application.
//

#include "4-pong.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "static.h"
#include "Player.h"
#include "Ball.h"
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


double last_time = glfwGetTime();
const glm::vec3 speed = glm::vec3(0.0f, 0.9f, 0.0f);

void compile_vertex_shader(unsigned int &vertex_shader) {
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertex_shader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

}

void compile_fragment_shader(unsigned int &fragment_shader) {
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragment_shader);

    int success;
    char infoLog[512];
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
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
        glGetShaderInfoLog(shader_program, 512, NULL, infoLog);
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


int main() {
    glfwInit();

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "4 Pong", NULL, NULL);
    if (window == NULL) {
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

    unsigned int vertex_shader;
    compile_vertex_shader(vertex_shader);

    unsigned int fragment_shader;
    compile_fragment_shader(fragment_shader);

    unsigned int shader_program;
    link_shaders(vertex_shader, fragment_shader, shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);


    Player left = Player(glm::vec2(0,0), glm::vec2(0,0), 0.0f, shader_program, LEFT_DEFAULT_VERTICES);
    Player right = Player(glm::vec2(0,0), glm::vec2(0,0), 0.0f, shader_program, RIGHT_DEFAULT_VERTICES);
    Ball ball = Ball(glm::vec2(0,0), glm::vec2(0,0), 0.0f, shader_program);

    left.init_buffer_data();
    right.init_buffer_data();
    ball.init_buffer_data();

    left.update_speed(1);

    ball.update_speed(1);
    ball.update_direction(-1.0f, 0.0f);


    double last_time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {

        processInput(window);
        int move = processMovement(window);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(shader_program);

        double time = glfwGetTime();
        double delta = time - last_time;

        left.update_direction(0.0f, move);


        ball.draw(delta);
        right.draw(delta);
        left.draw(delta);

        last_time = time;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ball.delete_buffer_data();
    left.delete_buffer_data();
    right.delete_buffer_data();

    glfwTerminate();
    return 0;
}
