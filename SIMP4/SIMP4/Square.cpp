#include "Square.h"

Square::Square(const int & i0, const int & j0, const int & length, const float & red, const float & green, const float & blue, float *& pixels)
{
	this->i0 = i0;
	this->j0 = j0;
	this->length = length;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->pixels = pixels;

	this->center_i = i0 ;
	this->center_j = j0 ;
}

void Square::draw(int xpos, int ypos)
{
	for (int i = i0 - length / 2; i <= i0 + length / 2; i++)
	{
		drawPixel(i, j0 + length / 2, red, green, blue);
	}
	for (int i = i0 - length / 2; i <= i0 + length / 2; i++)
	{
		drawPixel(i, j0 - length / 2, red, green, blue);
	}
	for (int j = j0 - length / 2; j <= j0 + length / 2; j++)
	{
		drawPixel(i0 - length / 2, j, red, green, blue);
	}
	for (int j = j0 - length / 2; j <= j0 + length / 2; j++)
	{
		drawPixel(i0 + length / 2, j, red, green, blue);
	}
	drawAroundCircle(xpos, ypos);
}
