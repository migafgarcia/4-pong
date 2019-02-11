#pragma once

#ifndef INC_4_PONG_BALLCONTROLLER_H
#define INC_4_PONG_BALLCONTROLLER_H


#include "Controller.h"

class BallController: public Controller {
public:
    explicit BallController(int id);
    void move(double delta);

};


#endif //INC_4_PONG_BALLCONTROLLER_H
