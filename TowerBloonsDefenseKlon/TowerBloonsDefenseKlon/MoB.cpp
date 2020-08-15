#include "MoB.h";

void MoB::move(Vector2D* vector) {
	double x = vector->getX();
	double y = vector->getY();

	this->x += x;
	this->y += y;
	this->update();
}