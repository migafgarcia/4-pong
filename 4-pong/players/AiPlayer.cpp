//
// Created by migafgarcia on 10-02-2019.
//

#include "AiPlayer.h"
#include <iostream>
AiPlayer::AiPlayer(int player_id) : Player(player_id) {}

int AiPlayer::next_move(std::map<int, glm::highp_dvec2*> &positions) {
    if(player_id == 1 || player_id == 2) {
        double ball_y = positions[0]->y;
        double my_y = positions[player_id]->y;

        if (my_y < ball_y) {
            return 1;
        } else if (my_y > ball_y) {
            return -1;
        }
    }
    else {
        double ball_x = positions[0]->x;
        double my_x = positions[player_id]->x;

        if (my_x < ball_x) {
            return -1;
        } else if (my_x > ball_x) {
            return 1;
        }
    }
    return 0;
}
