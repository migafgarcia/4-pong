
#include "Ball.h"
#include "shaders/Shaders.h"

void Ball::init_buffer_data() {
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

void Ball::delete_buffer_data() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Ball::update_position(double x, double y) {
    position.x = x;
    position.y = y;
}

void Ball::update_direction(double x, double y) {
    direction.x = x;
    direction.y = y;
}

void Ball::update_speed(double s) {
    speed = s;
}

void Ball::draw() {
    glm::mat4 trans = glm::mat4(0.95f);
    trans = glm::translate(trans, glm::vec3(position, 0.0f));
    trans = glm::scale(trans, glm::vec3(size, 1.0f));

    int transformLoc = glGetUniformLocation(Shaders::program_shader, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Ball::Ball(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, float speed) : GameObject(
        position,
        glm::highp_dvec2(0.05f, 0.05f),
        direction, speed) {}

Ball::~Ball() {

}

void Ball::update_position(double &d) {
    position.x += direction.x * speed * d;
    position.y += direction.y * speed * d;
}


