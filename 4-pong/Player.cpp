#include "Player.h"



using namespace std;

Player::Player(std::string n, const float * v, unsigned int &shader_program) : name{ n }, vertices{ v }, PROGRAM{ shader_program }
{
	speed = glm::vec3(DEFAULT_SPEED.x, DEFAULT_SPEED.y, DEFAULT_SPEED.z);
	trans = glm::mat4(1.0f);
	init_buffer_data();
}

Player::~Player()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Player::init_buffer_data()
{

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


void Player::draw(const double &current_time, const int &move)
{

	trans = glm::translate(trans, glm::vec3(0, speed.y * (current_time - last_time) * move, 0));
	last_time = current_time;

	unsigned int transformLoc = glGetUniformLocation(PROGRAM, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
