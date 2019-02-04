//
// Created by migafgarcia on 04-02-2019.
//

#ifndef INC_4_PONG_PLAYER_H
#define INC_4_PONG_PLAYER_H

#include <glm/gtc/type_ptr.hpp>

#include "GameObject.h"
#include "Gravity.h"
#include "glad/glad.h"
#include "static.h"




class Player: public GameObject {
private:
    const float* vertices;
    Gravity gravity;

public:

    Player(glm::vec2 &position, glm::vec2 &direction, float speed, unsigned int PROGRAM, const float* vertices);

    void init_buffer_data() override;

    void delete_buffer_data() override;

    void update_position(float, float) override;

    void update_direction(float, float) override;

    void update_speed(float s) override;

    void draw(double& delta) override;

    ~Player() override;
};


#endif //INC_4_PONG_PLAYER_H
