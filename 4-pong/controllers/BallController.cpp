

#include "BallController.h"
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

BallController::BallController(int id) : Controller(id) {

    if(id != 0)
        throw "ID of ball must be 0";

    std::uniform_real_distribution<double> unif(0, M_2_PI);
    std::default_random_engine re;
    direction = unif(re);
    speed = 1.0f;
    gameObject = new GameObject(glm::highp_dvec2(0, 0), glm::highp_dvec2(0.05f, 0.05f));
}

void BallController::move(double delta) {
    gameObject->position.x += cos(direction) * speed * delta;
    gameObject->position.y += sin(direction) * speed * delta;
}


