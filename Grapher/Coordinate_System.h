#pragma once
#include"StraightLine.h"
class Coordinate_System
{
public:
	Coordinate_System(float x_points, float y_pointsfloat ,float No_of_x_bigboxes,float No_of_y_bigboxes);
	Coordinate_System();

	void setquadrant(int quad);
	void drawscale();
	int getquadrant();
	float getx_points();
	float gety_points();
	float getx_smallboxes();
	float gety_smallboxes();
	float getNo_of_x_bigboxes();
	float getNo_of_y_bigboxes();
	float getupperarea_y();
	void show();

	~Coordinate_System();

private:
	float upperarea_y;
	float x_smallboxes;
	float y_smallboxes;
	float No_of_x_bigboxes;
	float No_of_y_bigboxes;
	StraightLine x_axis;
	StraightLine y_axis;
	int Quadrants;

};