#include "Arrow.h"

Arrow::Arrow(const char & direction, const int & i0, const int & j0, const int & length, const float & red, const float & green, const float & blue, float *& pixels)
{
	this->direction = direction;
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

void Arrow::draw(int xpos, int ypos)
{
	if (direction == 'L' || direction == 'l') {
		drawLine(i0 - length, j0, i0+length, j0, red, green, blue);
		drawLine(i0 - length, j0, i0 - length + 30, j0 + 30, red, green, blue);
		drawLine(i0 - length, j0, i0 - length + 30, j0 - 30, red, green, blue);
	}
	else if (direction == 'R' || direction == 'r') {
		drawLine(i0-length, j0, i0 + length, j0, red, green, blue);
		drawLine(i0 + length - 30, j0 + 30, i0 + length, j0, red, green, blue);
		drawLine(i0 + length - 30, j0 - 30, i0 + length, j0, red, green, blue);
	}
	else if (direction == 'U' || direction == 'u') {
		for (int j = j0-length; j <= j0 + length; j++)
		{
			drawPixel(i0, j, red, green, blue);
		}
		drawLine(i0 - 30, j0 + length - 30, i0, j0 + length, red, green, blue);
		drawLine(i0, j0 + length, i0 + 30, j0 + length - 30, red, green, blue);
	}
	else if (direction == 'D' || direction == 'd') {
		for (int j = j0+length; j >= j0-length; j--)
		{
			drawPixel(i0, j, red, green, blue);
		}
		drawLine(i0 - 30, j0 - length + 30, i0, j0 - length, red, green, blue);
		drawLine(i0, j0 - length, i0 + 30, j0 - length + 30, red, green, blue);
	}
	drawAroundCircle(xpos,ypos);
}
