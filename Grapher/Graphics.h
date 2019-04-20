#pragma once
#include<stdlib.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
#include"Point.h"
#include<string>
class Graphics
{
public:
	Graphics();
	Graphics(const char *name,int Win_Size_x,int Win_Size_y);
	Graphics(Graphics &G);

	void setcolor(int r, int g, int b);
	void setline_width(int width);
	void drawline(float x1, float y1, float x2, float y2);
	void drawcircle(float cx, float cy, float r);
	void drawpoint(float x, float y);
	void drawrectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void displaystring(float x, float y, string text, void* font);
	void displaychar(float x, float y, char text);
	void Colourfulrectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

	~Graphics();

private:
	string name;
	int line_width;
	int R;
	int G;
	int B;
	int Win_Pos_x; 
	int Win_Pos_y;
	int Win_Size_x;
	int Win_Size_y;


};