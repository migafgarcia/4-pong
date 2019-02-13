

#include "BallController.h"
#include <random>

BallController::BallController(int id) : Controller(id) {

    if(id != 0)
        throw "ID of ball must be 0";
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> unif(0, M_PI_2);
    direction = unif(rng) ;
//    direction = 0;
    speed = 1.0f;
    gameObject = new GameObject(glm::highp_dvec2(0, 0), glm::highp_dvec2(0.05f, 0.05f));
}

void BallController::move(double delta) {
    gameObject->position.x += cos(direction) * speed * delta;
    gameObject->position.y += sin(direction) * speed * delta;
}


