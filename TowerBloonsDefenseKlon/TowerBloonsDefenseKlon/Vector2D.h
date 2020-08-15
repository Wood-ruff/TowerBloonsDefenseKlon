#pragma once

class Vector2D {
public:
	Vector2D(double, double);
	void add(Vector2D);
	void divide(double);
	void multiply(double);
	int getX() { return x; }
	int getY() { return y; }


private:
	double x;
	double y;
};
