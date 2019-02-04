
#ifndef INC_4_PONG_BALL_H
#define INC_4_PONG_BALL_H

#include <glm/gtc/type_ptr.hpp>

#include "GameObject.h"
#include "glad/glad.h"
#include "static.h"

class Ball: public GameObject {

private:
    const float vertices[12] = {
            0.05f, 0.05f, 0.0f,  // top right
            0.05f, -0.05f, 0.0f,  // bottom right
            -0.05f, -0.05f, 0.0f,  // bottom left
            -0.05f,  0.05f, 0.0f   // top left
    };

public:

    Ball(glm::vec2 &position, glm::vec2 &direction, float speed, unsigned int PROGRAM);

    void init_buffer_data() override;

    void delete_buffer_data() override;

    void update_position(float, float) override;

    void update_direction(float, float) override;

    void update_speed(float s) override;

    void draw(double &delta) override;

    ~Ball() override;
};


#endif //INC_4_PONG_BALL_H
