#pragma once

#include "Object.h"
#include "Vector2D.h"

class MoB : public Object{
public:
	MoB(double x, double y, double width, double height, double speed, double* vertex, const char* vertexShader, const char* fragmentShader, const char* texturePath) :Object(x,y, width, height,vertex, vertexShader, fragmentShader, texturePath) { this->speed = speed; };
	void move(Vector2D*);
	double getSpeed() { return this->speed; };


protected:
	double speed;
};