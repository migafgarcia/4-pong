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
    int id;
	glm::highp_dvec2 position;
	glm::highp_dvec2 size;

    GameObject(int player_id, glm::highp_dvec2 &position, glm::highp_dvec2 &size) : id(player_id), position(
            position), size(size) {}

    void init_buffer_data();
    void delete_buffer_data();
	void draw();
};

