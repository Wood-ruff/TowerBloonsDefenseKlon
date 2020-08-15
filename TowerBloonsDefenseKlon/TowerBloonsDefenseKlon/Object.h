#pragma once
#include "Shader.h";
#include "stb_image.h";

using namespace std;

class Object {
public:
	Object(double x,double y, double width, double height,double* vertex, const char* vertexShader, const char* fragmentShader, const char* texturePath);
	void draw();
	void update();

protected:
	void refitVertex();
	unsigned int VAO, VBO, EBO, texture;
	double x, y;
	Shader* shader;
	double* vertex;
	double width, height;
	unsigned int* indices;
};
