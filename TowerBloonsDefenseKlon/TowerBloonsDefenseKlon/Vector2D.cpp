#include "Vector2D.h";
#include "MathUtils.h";
#include "Globals.h";

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vector2D::normalize() {
	this->y = MathUtils::getNormalizedCoord(this->y, SCR_HEIGHT);
	this->x = MathUtils::getNormalizedCoord(this->x, SCR_WIDTH);
}

void Vector2D::add(Vector2D vector) {
	this->x += vector.getX();
	this->y += vector.getY();
}

void Vector2D::divide(double value) {
	this->x = (float) this->x / value;
	this->y = (float) this->y / value;
}

void Vector2D::multiply(double value) {
	this->x = (float)this->x * value;
	this->y = (float)this->y * value;
}

void Vector2D::addToStdVertex(float* vertex) {
	vertex[0] += this->x;
	vertex[1] += this->y;
	vertex[8] += this->x;
	vertex[9] += this->y;
	vertex[16] += this->x;
	vertex[17] += this->y;
	vertex[24] += this->x;
	vertex[25] += this->y;
}