
#include "Ball.h"

void Ball::init_buffer_data() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Ball::delete_buffer_data() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Ball::update_position(float x, float y) {
    position.x = x;
    position.y = y;
}

void Ball::update_direction(float x, float y) {
    direction.x = x;
    direction.y = y;
}

void Ball::update_speed(float s) {
    speed = s;
}

void Ball::draw(double &delta) {

    position.x += direction.x * speed * delta;
    position.y += direction.y * speed * delta;

    position.y = (position.y < 0.95f) ? position.y : 0.95f;
    position.y = (position.y > -0.95f) ? position.y : -0.95f;
    position.x = (position.x > -0.95f) ? position.x : -0.95f;
    position.x = (position.x > -0.95f) ? position.x : -0.95f;

    if(position.x >= 0.95f || position.x <= -0.95f) {
        direction.x = -direction.x;
        position.x += direction.x * speed * delta;

    }

    if(position.y >= 0.95f || position.y <= -0.95f) {
        direction.y = -direction.y;
        position.y += direction.y * speed * delta;

    }

    glm::mat4 trans = glm::mat4(0.95f);
    trans = glm::translate(trans, glm::vec3(position, 0.0f));

    int transformLoc = glGetUniformLocation(PROGRAM, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Ball::Ball(glm::vec2 &position, glm::vec2 &direction, float speed, unsigned int PROGRAM) : GameObject(position,
                                                                                                      direction, speed,
                                                                                                      PROGRAM) {}

Ball::~Ball() {

}


