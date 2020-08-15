#pragma once

class Vector2D {
public:
	Vector2D(float,float);
	void normalize();
	void add(Vector2D);
	void divide(double);
	void multiply(double);
	void addToStdVertex(float*);
	int getX() { return x; }
	int getY() { return y; }


private:
	double x;
	double y;
};
