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
	unsigned int VAO, VBO, EBO;
	unsigned int pathVAO, pathVBO, pathEBO, pathVBO2, pathEBO2;
	unsigned int backgroundTexture, pathTexture;

	float* boardVertices;
	Shader *backgroundShader, *pathShader;	
	unsigned int* indices;
	GLFWwindow* window;
	void init();
	void processInput();

	// calculates and returns the path vertice array
	void getPathVertices(unsigned short startX, unsigned short startY, unsigned short endX, unsigned short endY, unsigned short pathWidth, unsigned short pathHeight, float* pathVertices);

	// TODO add a list with the objects(Mobs, etc...)
};

