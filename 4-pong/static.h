
#pragma once
#include <glm/glm.hpp>

const unsigned int SCR_WIDTH = 200;
const unsigned int SCR_HEIGHT = 200;

const unsigned int INDICES[] = {
		0, 1, 3,
		1, 2, 3
};

const float LEFT_DEFAULT_VERTICES[] = {
		 -0.95f, 0.25f, 0.0f,  // top right
		 -0.95f, -0.25f, 0.0f,  // bottom right
		-0.90f, -0.25f, 0.0f,  // bottom left
		-0.90f,  0.25f, 0.0f   // top left 
};

const float BOTTOM_DEFAULT_VERTICES[] = {
		 0.25f, -0.95f, 0.0f,  // top right
		 -0.25f, -0.95f, 0.0f,  // bottom right
		-0.25f, -0.90f, 0.0f,  // bottom left
		0.25f, -0.90f, 0.0f   // top left 
};

const float TOP_DEFAULT_VERTICES[] = {
		 0.25f, 0.95f, 0.0f,  // top right
		 -0.25f, 0.95f, 0.0f,  // bottom right
		-0.25f, 0.90f, 0.0f,  // bottom left
		0.25f, 0.90f, 0.0f   // top left 
};

const float RIGHT_DEFAULT_VERTICES[] = {
		 0.95f, 0.25f, 0.0f,  // top right
		 0.95f, -0.25f, 0.0f,  // bottom right
		 0.90f, -0.25f, 0.0f,  // bottom left
		0.90f,  0.25f, 0.0f   // top left 
};

const float TOP_LEFT_VERTICES[] = {
		 -0.90f, 1.0f, 0.0f,  // top right
		 -0.90f, 0.90f, 0.0f,  // bottom right
		-1.0f, 0.90f, 0.0f,  // bottom left
		-1.0f,  1.0f, 0.0f   // top left 
};

const float BOTTOM_LEFT_VERTICES[] = {
		 -0.90f, -1.0f, 0.0f,  // top right
		 -0.90f, -0.90f, 0.0f,  // bottom right
		-1.0f, -0.90f, 0.0f,  // bottom left
		-1.0f,  -1.0f, 0.0f   // top left 
};

const float BOTTOM_RIGHT_VERTICES[] = {
		 0.90f, -1.0f, 0.0f,  // top right
		 0.90f, -0.90f, 0.0f,  // bottom right
		1.0f, -0.90f, 0.0f,  // bottom left
		1.0f,  -1.0f, 0.0f   // top left 
};

const float TOP_RIGHT_VERTICES[] = {
		 0.90f, 1.0f, 0.0f,  // top right
		 0.90f, 0.90f, 0.0f,  // bottom right
		1.0f, 0.90f, 0.0f,  // bottom left
		1.0f,  1.0f, 0.0f   // top left 
};

const glm::vec3 DEFAULT_SPEED = glm::vec3(0.0f, 1.0f, 0.0f);
