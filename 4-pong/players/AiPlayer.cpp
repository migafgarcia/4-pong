//
// Created by migafgarcia on 10-02-2019.
//

#include "AiPlayer.h"
#include <iostream>
AiPlayer::AiPlayer(int player_id) : Player(player_id) {}

int AiPlayer::next_move(std::map<int, glm::highp_dvec2*> &positions) {
    double ball_y = positions[0]->y;
    double my_y = positions[player_id]->y;

    std::cout << ball_y << std::endl;

    if(my_y < ball_y) {
        return 1;
    }
    else if (my_y > ball_y) {
        return -1;
    }
    else
        return 0;
}
