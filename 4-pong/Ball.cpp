
#include "Ball.h"
#include "shaders/Shaders.h"

Ball::Ball(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, float speed) : GameObject(
        position,
        glm::highp_dvec2(0.05f, 0.05f),
        direction, speed) {}

Ball::~Ball() {

}



