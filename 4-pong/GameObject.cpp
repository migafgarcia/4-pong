
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

