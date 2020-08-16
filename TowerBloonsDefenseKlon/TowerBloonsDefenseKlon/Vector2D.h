#pragma once

class Vector2D {
public:
	Vector2D(double, double);
	void operator += (Vector2D);
	void operator /=(double);
	void operator *=(double);
	double getX() { return x; }
	double getY() { return y; }


private:
	double x;
	double y;
};
