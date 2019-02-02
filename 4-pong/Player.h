
#include "Gravity.h"
#include "glad/glad.h"
#include "static.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>



class Player
{
	std::string name;
	glm::vec3 speed;
	glm::mat4 trans;
	unsigned int VBO, VAO, EBO, PROGRAM;
	const float* vertices;
	
	double last_time;

	void init_buffer_data();

public:

	Player(std::string, const float *, unsigned int &);

	~Player();

	void draw(const double&, const int&);

};