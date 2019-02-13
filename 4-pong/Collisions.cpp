

#include "Collisions.h"




void Collisions::handle_collision(PaddleController *paddle, BallController *ball) {

    double paddle_x_max = paddle->gameObject->position.x + paddle->gameObject->size.x;
    double paddle_y_max = paddle->gameObject->position.y + paddle->gameObject->size.y;
    double paddle_x_min = paddle->gameObject->position.x - paddle->gameObject->size.x;
    double paddle_y_min = paddle->gameObject->position.y - paddle->gameObject->size.y;

    double ball_x_max = ball->gameObject->position.x + ball->gameObject->size.x;
    double ball_y_max = ball->gameObject->position.y + ball->gameObject->size.y;
    double ball_x_min = ball->gameObject->position.x - ball->gameObject->size.x;
    double ball_y_min = ball->gameObject->position.y - ball->gameObject->size.y;

    bool collision_x = ball_x_min >= paddle_x_min && ball_x_min <= paddle_x_max;
    bool collision_x_2 = ball_x_max >= paddle_x_min && ball_x_max <= paddle_x_max;

    bool collision_y = ball_y_min >= paddle_y_min && ball_y_min <= paddle_y_max;
    bool collision_y_2 = ball_y_max >= paddle_y_min && ball_y_max <= paddle_y_max;

    bool collision = (collision_x || collision_x_2) && (collision_y || collision_y_2);

    if(collision) {
        double max_x_diff = paddle->gameObject->size.x + ball->gameObject->size.x;
        double x_diff = (paddle->gameObject->position.x - ball->gameObject->position.x) / max_x_diff;

        double max_y_diff = paddle->gameObject->size.y + ball->gameObject->size.y;
        double y_diff = (paddle->gameObject->position.y - ball->gameObject->position.y) / max_y_diff;

        if(paddle->id == 1) {
            ball->gameObject->position.x = paddle->gameObject->position.x + paddle->gameObject->size.x + ball->gameObject->size.x;
            ball->direction = M_PI - ball->direction;
            ball->direction -= y_diff * (M_PI_2);
        }
        else if(paddle->id == 2) {
            ball->gameObject->position.x = paddle->gameObject->position.x - paddle->gameObject->size.x - ball->gameObject->size.x;
            ball->direction = M_PI - ball->direction;
            ball->direction -= y_diff * (M_PI_2);
        }
        else if(paddle->id == 3) {
            ball->gameObject->position.y = paddle->gameObject->position.y - paddle->gameObject->size.y - ball->gameObject->size.y;
            ball->direction = -ball->direction;
            ball->direction -= x_diff * (M_PI_2);
        }
        else if(paddle->id == 4) {
            ball->gameObject->position.y = paddle->gameObject->position.y + paddle->gameObject->size.y + ball->gameObject->size.y;
            ball->direction = -ball->direction;
            ball->direction -= x_diff * (M_PI_2);
        }

    }

}

bool Collisions::handle_x_bounds(Controller *controller) {
    double x = controller->gameObject->position.x;
    double max_x = 1.0f - controller->gameObject->size.x;

    if(x > max_x) {
        controller->gameObject->position.x = max_x;
        return true;
    }
    else if(x < -max_x) {
        controller->gameObject->position.x = -max_x;
        return true;
    }

    return false;
}

bool Collisions::handle_y_bounds(Controller *controller) {
    double y = controller->gameObject->position.y;
    double max_y = 1.0f - controller->gameObject->size.y;

    if(y < -max_y) {
        controller->gameObject->position.y = -max_y;
        return true;
    }
    else if(y > max_y) {
        controller->gameObject->position.y = max_y;
        return true;
    }
    return false;
}

bool Collisions::handle_bounds(BallController *controller) {


    if(handle_x_bounds(controller)) {
        controller->direction = M_PI - controller->direction;
        controller->gameObject->position.x = 0;
        controller->gameObject->position.y = 0;
        controller->speed = 1.0f;
        return true;
    }

    if(handle_y_bounds(controller))
        controller->direction = - controller->direction;

    return false;
}

void Collisions::handle_bounds(PaddleController *controller) {
    handle_x_bounds(controller);
    handle_y_bounds(controller);
}

