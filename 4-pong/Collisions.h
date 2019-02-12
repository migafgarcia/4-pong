#pragma once

#ifndef INC_4_PONG_COLLISIONS_H
#define INC_4_PONG_COLLISIONS_H


#include "controllers/BallController.h"
#include "controllers/PaddleController.h"

class Collisions {
public:
     static void handle_collision(PaddleController* paddle, BallController* ball);
     static bool handle_x_bounds(Controller *controller);
     static bool handle_y_bounds(Controller *controller);
     static bool handle_bounds(BallController* controller);
     static void handle_bounds(PaddleController* controller);

};


#endif //INC_4_PONG_COLLISIONS_H
