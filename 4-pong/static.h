
#pragma once
#include <glm/glm.hpp>

const unsigned int SCR_WIDTH = 500;
const unsigned int SCR_HEIGHT = 500;

const unsigned int INDICES[] = {
		0, 1, 3,
		1, 2, 3
};

const float VERTICES[] = {
		1.0f, 1.0f, 0.0f,  // top right
		1.0f, -1.0f, 0.0f,  // bottom right
		-1.0f, -1.0f, 0.0f,  // bottom left
		-1.0f,  1.0f, 0.0f   // top left
};

#define M_PI_2 1.57079632679489661923
#define M_PI 3.14159265358979323846
#define M_2_PI 6.28318530718
