#pragma once

#include "shaders/Shaders.h"
#include "static.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

class GameObject {

protected:
	glm::highp_dvec2 position;
	glm::highp_dvec2 size;

	glm::highp_dvec2 direction;
	double speed;

    unsigned int VBO, VAO, EBO;

public:
    GameObject(glm::highp_dvec2 &position, glm::highp_dvec2 &size, glm::highp_dvec2 &direction, float speed) : position(
            position), size(size), direction(direction), speed(speed) {}

    void init_buffer_data();
    void delete_buffer_data();
    void update_position(double x, double y);
    void update_position(double &delta);
    void update_direction(double x, double y);
    void update_speed(double s);
	void draw();
	virtual ~GameObject() {};

    bool check_x_bounds();
    bool check_y_bounds();
    bool check_collision(GameObject &other);
    void invert_x_direction();
    void invert_y_direction();

};

