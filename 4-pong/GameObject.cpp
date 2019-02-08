
#include "GameObject.h"


bool GameObject::check_x_bounds() {
    double x = position.x;
    double max_x = 1.0f - size.x;

    if(x > max_x) {
        position.x = max_x;
        return true;
    }
    else if(x < -max_x) {
        position.x = -max_x;
        return true;
    }

    return false;
}

bool GameObject::check_y_bounds() {
    double y = position.y;
    double max_y = 1.0f - size.y;

    if(y < -max_y) {
        position.y = -max_y;
        return true;
    }
    else if(y > max_y) {
        position.y = max_y;
        return true;
    }
    return false;
}

bool GameObject::check_collision(GameObject &other) {

    double x_max = position.x + size.x;
    double y_max = position.y + size.y;
    double x_min = position.x - size.x;
    double y_min = position.y - size.y;

    double other_x_max = other.position.x + other.size.x;
    double other_y_max = other.position.y + other.size.y;
    double other_x_min = other.position.x - other.size.x;
    double other_y_min = other.position.y - other.size.y;



    bool collision_x = other_x_min >= x_min && other_x_min <= x_max;
    bool collision_x_2 = other_x_max >= x_min && other_x_max <= x_max;

    bool collision_y = other_y_min >= y_min && other_y_min <= y_max;
    bool collision_y_2 = other_y_max >= y_min && other_y_max <= y_max;

    return (collision_x || collision_x_2) && (collision_y || collision_y_2);
}

void GameObject::invert_x_direction() {
    direction.x = -direction.x;
}

void GameObject::invert_y_direction() {
    direction.y = -direction.y;
}

void GameObject::draw() {
    glm::mat4 trans = glm::mat4(0.95f);
    trans = glm::translate(trans, glm::vec3(position, 0.0f));
    trans = glm::scale(trans, glm::vec3(size, 1.0f));

    int transformLoc = glGetUniformLocation(Shaders::program_shader, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void GameObject::init_buffer_data() {
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

void GameObject::delete_buffer_data() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void GameObject::update_position(double x, double y) {
    position.x = x;
    position.y = y;
}

void GameObject::update_position(double &delta) {
    position.x += direction.x * speed * delta;
    position.y += direction.y * speed * delta;
}

void GameObject::update_direction(double x, double y) {
    direction.x = x;
    direction.y = y;
}

void GameObject::update_speed(double s) {
    speed = s;
}

