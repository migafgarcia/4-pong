
#include "Player.h"
#include <iostream>

Player::Player(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, Gravity gravity, float speed, unsigned int PROGRAM)
        : GameObject(position,
                     glm::highp_dvec2(0.03f, 0.25f),
                     direction,
                     speed,
                     PROGRAM), gravity{gravity}{}

void Player::init_buffer_data() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(VERTICES), VERTICES, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Player::delete_buffer_data() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Player::update_position(double x, double y) {
    position.x = x;
    position.y = y;
}

void Player::update_direction(double x, double y) {
    direction.x = x;
    direction.y = y;
}

void Player::update_speed(double s) {
    speed = s;
}

void Player::draw() {
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(position, 0.0f));
    trans = glm::scale(trans, glm::vec3(size, 1.0f));

    int transformLoc = glGetUniformLocation(PROGRAM, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Player::~Player() {

}

void Player::update_position(double &d) {
    position.x += direction.x * speed * d;
    position.y += direction.y * speed * d;
}

