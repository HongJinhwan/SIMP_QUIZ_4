#include <GLFW/glfw3.h>
#include <thread>         // std::this_thread::sleep_for
#include <vector>

#include "Circle.h"
#include "Shape.h"
#include "Boldline.h"
#include "Square.h"
#include "Cross.h"
#include "Arrow.h"
#include "AlphabetA.h"
#include "Column.h"

using namespace std;

const int width = 1000;
const int height = 800;
const int line_width = 2;
const int circle_number = 20;
float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
void drawOnPixelBuffer();

int main(void)
{
	GLFWwindow* window;
	double xpos, ypos;

	if (!glfwInit())
		return -1;
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1);

	vector<Shape *> shape_list;
	for (int i = 0; i < 2; i++) {
		shape_list.push_back(new Circle(100, 700-400*i, 40, 450, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Cross(300, 700 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Boldline(470, 670 - 400 * i, 530, 730 - 400 * i, 2, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Square(700, 700 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Arrow('d', 900, 700 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Arrow('r', 100, 500 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new AlphabetA(300, 500 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Column(500, 500 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Arrow('l', 700, 500 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
		shape_list.push_back(new Arrow('u', 900, 500 - 400 * i, 60, 1.0f, 0.0f, 0.0f, pixels));
	}
	while (!glfwWindowShouldClose(window))
	{
		drawOnPixelBuffer();
		glfwGetCursorPos(window, &xpos, &ypos);

		for (int i = 0; i < shape_list.size(); i++) {
			shape_list[i]->draw(xpos,ypos);
		}

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		glfwSwapBuffers(window);
		glfwPollEvents();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();
	delete[] pixels; // or you may reuse pixels array 
	return 0;
}


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}


void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;

	//TODO: try moving object
}