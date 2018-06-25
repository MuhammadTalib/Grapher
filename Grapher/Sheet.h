#pragma once
#include"StraightLine.h"
class Sheet
{
public:
	Sheet();
	Sheet(int Quad);

	void setquadrant(int quad);
	int getquadrant();
	void show();

	~Sheet();

private:
	StraightLine x_axis;
	StraightLine y_axis;
	int Quadrants;

};