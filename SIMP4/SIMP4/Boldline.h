#pragma once
#include "Shape.h"

class Boldline : public Shape {
private:
	int i0, j0,i1,j1;
	int line_width;


public:
	Boldline(const int& i0, const int& j0, const int& i1, const int& j1, const int line_width,const float& red, const float& green, const float& blue, float *& pixels);

	void draw(int xpos, int ypos);
};