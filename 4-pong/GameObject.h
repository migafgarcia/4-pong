#pragma once

#include <glm/glm.hpp>

class GameObject {

protected:
	glm::vec2 position;
	glm::vec2 direction;
	float speed;

    unsigned int VBO, VAO, EBO, PROGRAM;

public:
    GameObject(glm::vec2 &position, glm::vec2 &direction, float speed, unsigned int PROGRAM) : position(
            position), direction(direction), speed(speed), PROGRAM(PROGRAM) {}

    virtual void init_buffer_data() = 0;
    virtual void delete_buffer_data() = 0;
    virtual void update_position(float, float) = 0;
    virtual void update_direction(float, float) = 0;
    virtual void update_speed(float) = 0;
    virtual void draw(double &) = 0;
    virtual ~GameObject() {};
};