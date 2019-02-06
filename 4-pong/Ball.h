
#pragma once

#include <glm/gtc/type_ptr.hpp>

#include "GameObject.h"
#include <glad/glad.h>
#include "static.h"

class Ball: public GameObject {

public:

    Ball(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, float speed, unsigned int PROGRAM);

    void init_buffer_data() override;

    void delete_buffer_data() override;

    void update_position(double, double) override;

    void update_position(double &d) override;

    void update_direction(double, double) override;

    void update_speed(double s) override;

    void draw() override;

    ~Ball() override;
};
