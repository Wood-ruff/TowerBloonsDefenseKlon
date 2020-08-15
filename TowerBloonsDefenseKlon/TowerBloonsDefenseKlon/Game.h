#pragma once
#include "Shader.h"

class Game
{
public:
	Game();
	void draw();

private:
	unsigned int VAO, VBO, EBO, texture;
	float* boardVertices;
	Shader* shader;	
	unsigned int* indices;

	// TODO add a list with the objects(Mobs, etc...)
};

