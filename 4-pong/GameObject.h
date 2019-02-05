#pragma once

#include <glm/glm.hpp>

class GameObject {

protected:
	glm::highp_dvec2 position;
	glm::highp_dvec2 size;

	glm::highp_dvec2 direction;
	double speed;

    unsigned int VBO, VAO, EBO, PROGRAM;

public:
    GameObject(glm::highp_dvec2 &position, glm::highp_dvec2 &size, glm::highp_dvec2 &direction, float speed, unsigned int PROGRAM) : position(
            position), size(size), direction(direction), speed(speed), PROGRAM(PROGRAM) {}

    virtual void init_buffer_data() = 0;
    virtual void delete_buffer_data() = 0;
    virtual void update_position(double, double) = 0;
    virtual void update_position(double &) = 0;
    virtual void update_direction(double, double) = 0;
    virtual void update_speed(double) = 0;
    bool check_x_bounds();
    bool check_y_bounds();
    bool check_collision(GameObject &other);
    void invert_x_direction();
    void invert_y_direction();
    virtual void draw() = 0;
    virtual ~GameObject() {};
};

