#pragma once

class Vector2D {
public:
	Vector2D(int x,int y);
	void normalize();
	void add(Vector2D);
	int getX() { return x; }
	int getY() { return y; }


private:
	int x;
	int y;
};
