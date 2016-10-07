#include "Cross.h"

Cross::Cross(const int & i0, const int & j0, const int & length, const float & red, const float & green, const float & blue, float *& pixels)
{
	this->i0 = i0;
	this->j0 = j0;
	this->length = length;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->pixels = pixels;

	this->center_i = i0;
	this->center_j = j0;
}

void Cross::draw(int xpos, int ypos)
{
	drawLine(i0 - length / 2, j0 - length / 2, i0 + length / 2, j0 + length / 2, red, green, blue);
	drawLine(i0 - length / 2, j0 + length / 2, i0 + length / 2, j0 - length / 2, red, green, blue);
	drawAroundCircle(xpos, ypos);
}
