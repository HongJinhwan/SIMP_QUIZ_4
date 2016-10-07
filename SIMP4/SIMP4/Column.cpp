#include "Column.h"

Column::Column(const int & i0, const int & j0, const int & length, const float & red, const float & green, const float & blue, float *& pixels)
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

void Column::draw(int xpos, int ypos)
{
	for (int j = j0+length; j >= j0-length; j--)
	{
		drawPixel(i0-1, j, red, green, blue);
		drawPixel(i0+1, j, red, green, blue);
		drawPixel(i0, j, red, green, blue);
	}
	drawAroundCircle(xpos, ypos);
}
