#include<stdlib.h>
#include<GL\glut.h>
#include"Point.h"
#include"Graphics.h"
#include<string.h>
#include<string>
Graphics::Graphics()
{
}

Graphics::Graphics(const char * name, int Win_Size_x, int Win_Size_y)
{
	this->R = 0.0;
	this->G = 0.0;
	this->B = 0.0;
	this->line_width = 1;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650, 750);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(name);
	glClearColor(1.0, 1.0, 1.0, 1.0); //Background Colour
	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(0.0, 200.0, 0.0, 245);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(this->R,this->G,this->B);  //Foreground Colour

}
Graphics::Graphics(Graphics & G)
{
}
Graphics::~Graphics()
{
}
void Graphics::setcolor(int r, int g, int b)
{
	this->R = r;
	this->G = g;
	this->B = b;
	glColor3f(this->R, this->G, this->B);
}
void Graphics::setline_width(int width)
{
	glLineWidth(width);
}
void Graphics::drawline(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}
void Graphics::drawcircle(float cx,float cy, float r)
{
	glPointSize(2);
	 int num_segments = 1000;
	glBegin(GL_POINTS);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); //get the current angle

		float x = r * cosf(theta); //calculate the x component
		float y = r * sinf(theta); //calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void Graphics::drawpoint(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void Graphics::drawrectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x3, y3, 0.0);
	glVertex3f(x4, y4, 0.0);
	glEnd();
}
void Graphics::Colourfulrectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x4, y4, 0.0);
	glVertex3f(x3, y3, 0.0);
	
	glColor3f(0, 1, 1);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x4, y4, 0.0);
	glVertex3f(x3, y3, 0.0);
	glVertex3f(x1, y1, 0.0);
	
	glEnd();

}
void Graphics::displaychar(float x, float y, char text)
{
	glRasterPos2f(x, y);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
	glEnd();
}
void Graphics::displaystring(float x, float y,string text,void* font)
{

	int n = text.length();
	char char_array[50];
	strcpy_s(char_array, text.c_str());
	glRasterPos2f(x, y);
	for (int i = 0; char_array[i] != '\0'; i++)
	{	
		glutBitmapCharacter(font, char_array[i]);
	}
	glEnd();
}
