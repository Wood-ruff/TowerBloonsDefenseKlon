#pragma once
#include "Object.h"
#include "Globals.h"
#include "MoB.h"
#include "Timer.h"
#include "Game.h"
#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:
	Game();
	void draw();
	void gameloop();

private:
	unsigned int VAO, VBO, EBO, texture;
	float* boardVertices;
	Shader* shader;	
	unsigned int* indices;
	GLFWwindow* window;
	void init();
	void processInput();

	// TODO add a list with the objects(Mobs, etc...)
};

