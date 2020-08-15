#pragma once

class Vector2D {
public:
	Vector2D(double, double);
	void add(Vector2D);
	void divide(double);
	void multiply(double);
	double getX() { return x; }
	double getY() { return y; }


private:
	double x;
	double y;
};
