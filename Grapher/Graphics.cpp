#include<stdlib.h>
#include<GL\glut.h>
#include"Point.h"
#include"Graphics.h"

Graphics::Graphics()
{
}

Graphics::Graphics(const char * name, int Win_Size_x, int Win_Size_y)
{
	this->R = 0.0;
	this->G = 0.0;
	this->B = 0.0;
	this->line_width = 1;
	int Win_Pos_x=100;
	int Win_Pos_y=100;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Win_Size_x, Win_Size_y);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(name);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(this->R,this->G,this->B);

	
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
void Graphics::drawline(int x1, int y1, int x2, int y2)
{
	
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}
void Graphics::drawcircle(int c, int r)
{
}
void Graphics::drawpoint(int x, int y)
{
	
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	
}