#pragma once

#include "../shaders/Shaders.h"
#include "../static.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <iostream>

class GameObject {
private:
    unsigned int VBO, VAO, EBO;

public:
	glm::highp_dvec2 position;
	glm::highp_dvec2 size;

    GameObject(glm::highp_dvec2 &position, glm::highp_dvec2 &size) : position(
            position), size(size) {}

    void init_buffer_data();
    void delete_buffer_data();
	void draw();
};

