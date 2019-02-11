//
// Created by migafgarcia on 10-02-2019.
//

#ifndef INC_4_PONG_HUMANPLAYER_H
#define INC_4_PONG_HUMANPLAYER_H


#include "Player.h"

#include <GLFW/glfw3.h>

class HumanPlayer: public Player {

private:
    GLFWwindow *window;
    int positive_key;
    int negative_key;

    int process_input();

public:
    HumanPlayer(int player_id, GLFWwindow *window, int positive_key, int negative_key);

    int next_move(std::map<int, glm::highp_dvec2> &positions) override;

};


#endif //INC_4_PONG_HUMANPLAYER_H
