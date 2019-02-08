
#include "Player.h"
#include "shaders/Shaders.h"
#include <iostream>

Player::Player(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, Gravity gravity, float speed)
        : GameObject(position,
                     glm::highp_dvec2(0.03f, 0.25f),
                     direction,
                     speed), gravity{gravity}{}

Player::~Player() {

}

