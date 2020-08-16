#include "Vector2D.h";
#include "MathUtils.h";
#include "Globals.h";

Vector2D::Vector2D(double x, double y) {
	this->x = x;
	this->y = y;
}


void Vector2D::operator+=(Vector2D vector) {
	this->x += vector.getX();
	this->y += vector.getY();
}

void Vector2D::operator/=(double value) {
	this->x = (double) this->x / value;
	this->y = (double) this->y / value;
}

void Vector2D::operator*=(double value) {
	this->x = this->x * value;
	this->y = this->y * value;
}
