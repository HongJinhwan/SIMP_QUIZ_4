#include "Circle.h"

Circle::Circle(const int & i0, const int & j0, const float & r, const int & bold, const float & red, const float & green, const float & blue, float *& pixels)
{
	this->i0 = i0;
	this->j0 = j0;
	this->r = r;
	this->bold = bold;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->pixels = pixels;

	this->center_i = i0;
	this->center_j = j0;
}

void Circle::draw(int xpos, int ypos)
{
	for (int i = i0 - r; i <= i0 + r; i++) {
		for (int j = j0 - r; j <= j0 + r; j++) {
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;
			if (f <= 0 && f >= -bold) {
				drawPixel(i, j, red, green, blue);
			}
		}
	}
	drawAroundCircle(xpos, ypos);
}
