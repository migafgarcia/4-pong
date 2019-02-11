//
// Created by migafgarcia on 10-02-2019.
//

#ifndef INC_4_PONG_AIPLAYER_H
#define INC_4_PONG_AIPLAYER_H


#include "Player.h"

class AiPlayer: public Player {

public:
    AiPlayer(int player_id);

    int next_move(std::map<int, glm::highp_dvec2> &positions) override;
};


#endif //INC_4_PONG_AIPLAYER_H
