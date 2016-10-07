#include "Boldline.h"

Boldline::Boldline(const int& i0, const int& j0, const int& i1, const int& j1, int line_width, const float& red, const float& green, const float& blue, float *& pixels)
{
	this->i0 = i0;
	this->j0 = j0;
	this->i1 = i1;
	this->j1 = j1;
	this->line_width = line_width;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->pixels = pixels;

	this->center_i = (i0+i1)/2;
	this->center_j = (j0+j1)/2;
}

void Boldline::draw(int xpos, int ypos)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		for (int a = i - line_width; a <= i + line_width; a++) {
			for (int b = j - line_width; b <= j + line_width; b++) {
				drawPixel(a, b, red, green, blue);
			}
		}
	}
	drawAroundCircle(xpos, ypos);
}
