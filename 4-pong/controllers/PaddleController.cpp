
#include "PaddleController.h"

PaddleController::PaddleController(int id) : Controller(id) {
    speed = 1.0f;

    if (id == 1) {
        gameObject = new GameObject(glm::highp_dvec2(-0.95f, 0), glm::highp_dvec2(0.03f, 0.25f));
        direction = M_PI_2;
    } else if (id == 2) {
        gameObject = new GameObject(glm::highp_dvec2(0.95f, 0), glm::highp_dvec2(0.03f, 0.25f));
        direction = M_PI_2;
    } else if (id == 3) {
        gameObject = new GameObject(glm::highp_dvec2(0, 0.95f), glm::highp_dvec2(0.25f, 0.03f));
        direction = M_PI;
    } else if (id == 4) {
        gameObject = new GameObject(glm::highp_dvec2(0, -0.95f), glm::highp_dvec2(0.25f, 0.03f));
        direction = M_PI;
    } else
        throw "Invalid player id";
}

void PaddleController::move(int move, double delta) {
    gameObject->position.x += cos(direction) * speed * delta * move;
    gameObject->position.y += sin(direction) * speed * delta * move;
}
