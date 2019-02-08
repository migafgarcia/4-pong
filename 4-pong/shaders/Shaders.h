
#ifndef INC_4_PONG_SHADERS_H
#define INC_4_PONG_SHADERS_H

#include <iostream>

class Shaders {
public:
    static unsigned int program_shader;

    static void load_shader_from_file(std::string &filename, std::string &fragment_filename);

    static void load_built_in_shaders();

private:
    Shaders() {};

    static const char *vertex_shader_source;
    static const char *fragment_shader_source;

    static void compile_shader(unsigned int shader_type, unsigned int &shader, const char *shader_source);

    static void link_shaders(const unsigned int &vertex_shader, const unsigned int &fragment_shader, unsigned int &shader_program);

};


#endif //INC_4_PONG_SHADERS_H
