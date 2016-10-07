#include "Shape.h"

Shape::Shape() {
}

void Shape::drawPixel(const int & i, const int & j, const float & red, const float & green, const float & blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void Shape::drawAroundCircle(int xpos, int ypos)
{
	const int bold = 400;
	int jw = height - center_j;
	for (int i = center_i - shape_radius; i <= center_i + shape_radius; i++) {
		for (int j = center_j - shape_radius; j <= center_j + shape_radius; j++) {
			int f = (i - center_i)*(i - center_i) + (j - center_j)*(j - center_j) - shape_radius*shape_radius;
			int f2 = (xpos - center_i)*(xpos - center_i) + (ypos - jw)*(ypos - jw) - shape_radius*shape_radius;	
			if (f <= 0 && f >= -bold) {
				if (f2<=0) {
					drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				}
				else
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			}
		}
	}
}

void Shape::drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}