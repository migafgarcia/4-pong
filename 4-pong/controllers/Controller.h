#pragma once

#ifndef INC_4_PONG_CONTROLLER_H
#define INC_4_PONG_CONTROLLER_H


#include "../game_objects/GameObject.h"
class Controller {

public:
    int id;
    double direction;
    double speed;
    GameObject *gameObject;


public:

    Controller(int id);

    virtual ~Controller() {};

};


#endif
