
#pragma once
#include <glm/glm.hpp>

const unsigned int SCR_WIDTH = 200;
const unsigned int SCR_HEIGHT = 200;

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