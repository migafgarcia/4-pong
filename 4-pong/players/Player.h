#pragma once

#ifndef INC_4_PONG_CONTROLLER_H
#define INC_4_PONG_CONTROLLER_H


#include <glm/glm.hpp>
#include <map>
#include "../game_objects/GameObject.h"

class Player {

public:
    int player_id;
    virtual int next_move(std::map<int, glm::highp_dvec2> &positions) = 0;

    Player(int player_id) : player_id(player_id) {};
    ~Player() {};
};


#endif
