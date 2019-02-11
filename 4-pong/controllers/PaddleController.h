//
// Created by migafgarcia on 11-02-2019.
//

#ifndef INC_4_PONG_PADDLECONTROLLER_H
#define INC_4_PONG_PADDLECONTROLLER_H


#include "Controller.h"
#include "../Gravity.h"

class PlayerController : public Controller {

public:
    explicit PlayerController(int id);
    void move(int move, double delta);

};


#endif //INC_4_PONG_PADDLECONTROLLER_H
