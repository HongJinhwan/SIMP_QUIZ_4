#pragma once
#include "Shape.h"

class AlphabetA : public Shape {
private:
	int i0, j0;
	int length;
	
public:
	AlphabetA(const int& i0, const int& j0, const int& length, const float& red, const float& green, const float& blue, float *& pixels);

	void draw(int xpos, int ypos);
};