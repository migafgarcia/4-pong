

#pragma once

#include <glm/gtc/type_ptr.hpp>

#include "GameObject.h"
#include "Ball.h"
#include "Gravity.h"
#include <glad/glad.h>
#include "static.h"

class Player: public GameObject {
private:
    Gravity gravity;


public:

    Player(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, Gravity gravity, float speed, unsigned int PROGRAM);

    void init_buffer_data() override;

    void delete_buffer_data() override;

    void update_position(double, double) override;

    void update_position(double &d) override;

    void update_direction(double, double) override;

    void update_speed(double s) override;

    void draw() override;

    ~Player() override;
};
