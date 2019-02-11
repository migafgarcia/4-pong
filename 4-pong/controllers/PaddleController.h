//
// Created by migafgarcia on 11-02-2019.
//

#ifndef INC_4_PONG_PADDLECONTROLLER_H
#define INC_4_PONG_PADDLECONTROLLER_H


#include "Controller.h"
#include "../Gravity.h"

class PaddleController : public Controller {

public:
    explicit PaddleController(int id);
    void move(int move, double delta);

};


#endif //INC_4_PONG_PADDLECONTROLLER_H
