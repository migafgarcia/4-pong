//
// Created by migafgarcia on 10-02-2019.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int player_id, GLFWwindow *window, int positive_key, int negative_key) : Player(player_id),
                                                                                                  window(window),
                                                                                                  positive_key(
                                                                                                          positive_key),
                                                                                                  negative_key(
                                                                                                          negative_key) {}

int HumanPlayer::next_move(std::map<int, glm::highp_dvec2*> &positions) {
    return process_input();
}

int HumanPlayer::process_input() {

    if (glfwGetKey(window, positive_key) == GLFW_PRESS) {
        return 1;
    } else if (glfwGetKey(window, negative_key) == GLFW_PRESS) {
        return -1;
    } else {
        return 0;
    }

}
