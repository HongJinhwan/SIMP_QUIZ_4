#pragma once

using namespace std;

class Shape {
protected:
	const int width = 1000;
	const int height = 800;
	float* pixels = new float[width*height * 3];
	float red, green, blue;
	int center_i;
	int center_j;
	int xpos, ypos;


public:
	Shape();

	float shape_radius = 80;
	virtual void draw(int xpos, int ypos)=0;
	void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
	void drawAroundCircle(int xpos, int ypos);
	void drawLine(const int & i0, const int & j0, const int & i1, const int & j1, const float & red, const float & green, const float & blue);
};