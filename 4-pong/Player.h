

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

    Player(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, Gravity gravity, float speed);

    ~Player() override;
};
