#pragma once

#include "Object.h"
#include "Vector2D.h"

class MoB : public Object{
public:
	MoB(double x, double y, double width, double height, double speed, float* vertex, unsigned int* indices, const char* vertexShader, const char* fragmentShader, const char* texturePath) :Object(x,y, width, height,vertex, indices, vertexShader, fragmentShader, texturePath) { this->speed = speed; };
	void move(Vector2D*);
	double getSpeed() { return this->speed; };


protected:
	double speed;
};