#pragma once
#include "Shader.h";
#include "stb_image.h";

using namespace std;

class Object {
public:
	Object(float* vertex, unsigned int* indices, const char* vertexShader, const char* fragmentShader, const char* texturePath);
	void draw();
	void update();

private:
	unsigned int VAO, VBO, EBO, texture;
	Shader* shader;
	float* vertex;
	unsigned int* indices;
	int vertexlength;
};
