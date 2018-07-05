#pragma once
#include"StraightLine.h"
class Coordinate_System
{
public:
	Coordinate_System();
	Coordinate_System(int Quad);

	void setquadrant(int quad);
	int getquadrant();
	void show();

	~Coordinate_System();

private:
	StraightLine x_axis;
	StraightLine y_axis;
	int Quadrants;

};