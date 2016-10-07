#pragma once
#include "Shape.h"

class Circle : public Shape{
private:
	int i0, j0;
	float r;
	int bold;


public:
	Circle(const int& i0, const int& j0, const float& r, const int& bold, const float& red, const float& green, const float& blue, float* &pixels);

	void draw(int xpos, int ypos);
};