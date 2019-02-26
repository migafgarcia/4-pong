
#include "Shaders.h"

#include <fstream>
#include <sstream>
#include <../glad/glad.h>

using namespace std;

unsigned int Shaders::program_shader;

const char *Shaders::vertex_shader_source = "#version 140\n"
                                            "in vec3 aPos;\n"
                                            "in vec2 aTexCoord;\n"
                                            "uniform mat4 transform;\n"
                                            "void main()\n"
                                            "{\n"
                                            "   gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                            "}\0";

const char *Shaders::fragment_shader_source = "#version 140\n"
                                              "out vec4 FragColor;\n"
                                              "void main()\n"
                                              "{\n"
                                              "   FragColor = vec4(0.5f, 0.75f, 0.25f, 1.0f);\n"
                                              "}\n\0";

void Shaders::load_shader_from_file(string &vertex_filename, string &fragment_filename) {

    string vertex_source;
    string fragment_source;

    try {
        stringstream stream;

        ifstream vertex_file(vertex_filename, ifstream::in);


        stream << vertex_file.rdbuf();

        vertex_source = stream.str();

        vertex_file.close();

        stream.clear();

        ifstream fragment_file(fragment_filename, ifstream::in);

        stream << fragment_file.rdbuf();

        fragment_source = stream.str();

        fragment_file.close();
    }
    catch (exception e) {
        cout << "ERROR::SHADER: Failed to read shader files" << endl;
    }

    cout << vertex_source << endl;
    cout << fragment_source << endl;


}


void Shaders::load_built_in_shaders() {
    unsigned int vertex_shader;
    compile_shader(GL_VERTEX_SHADER, vertex_shader, Shaders::vertex_shader_source);

    unsigned int fragment_shader;
    compile_shader(GL_FRAGMENT_SHADER, fragment_shader, Shaders::fragment_shader_source);

    link_shaders(vertex_shader, fragment_shader, Shaders::program_shader);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void Shaders::compile_shader(unsigned int shader_type, unsigned int &shader, const char *shader_source) {
    shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_source, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void
Shaders::link_shaders(const unsigned int &vertex_shader, const unsigned int &fragment_shader,
                      unsigned int &shader_program) {

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
