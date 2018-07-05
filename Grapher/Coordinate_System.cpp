#include"Coordinate_System.h"
#include "Point.h"
#include"StraightLine.h"
Coordinate_System::Coordinate_System()
{
	Graphics G;
	G.setline_width(2);
	G.setcolor(0, 0, 0);

	Point A(0, 99),B(99,0),C(99,199),D(199,99);
	StraightLine S1(A, D),S2(B,C);

	this->x_axis = S1;
	this->y_axis = S2;
	this->Quadrants = 4;
	
	
}
Coordinate_System::Coordinate_System(int Quad)
{
	this->Quadrants = Quad;
	Point A(0, 100), B(100, 0), C(100, 200), D(200, 100);
	StraightLine S1(A, D), S2(B, C);
	S1.show();
	S2.show();
	this->Quadrants = 4;
}

void Coordinate_System::setquadrant(int quad)
{
	this->Quadrants = quad;
}

int Coordinate_System::getquadrant()
{
	return this->Quadrants;
}
void Coordinate_System::show()
{
	this->x_axis.show();
	this->y_axis.show();
}

Coordinate_System::~Coordinate_System()
{
	cout << "Coordinate System";
}