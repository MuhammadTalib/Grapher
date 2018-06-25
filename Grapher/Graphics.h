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
	void drawline(int x1,int y1,int x2,int y2);
	void drawcircle(int c, int r);
	void drawpoint(int x, int y);
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