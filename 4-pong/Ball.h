
#pragma once

#include <glm/gtc/type_ptr.hpp>

#include "GameObject.h"
#include <glad/glad.h>
#include "static.h"

class Ball: public GameObject {

public:

    Ball(glm::highp_dvec2 &position, glm::highp_dvec2 &direction, float speed);

    ~Ball() override;
};
