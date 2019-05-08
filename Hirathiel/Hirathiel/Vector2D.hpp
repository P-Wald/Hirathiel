#pragma once

#include <iostream>

class Vector2D {
public:
	Vector2D(float x,float y);
	void addVector(Vector2D* vector);
	void subVector(Vector2D* vector);
	void scalar(float scalar);
	inline float getX() {return this->x;};
	inline float getY() {return this->y;};

private:
	float x;
	float y;
};

