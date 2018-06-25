#include"Sheet.h"
#include "Point.h"
#include"StraightLine.h"
Sheet::Sheet()
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
Sheet::Sheet(int Quad)
{
	this->Quadrants = Quad;
	Point A(0, 100), B(100, 0), C(100, 200), D(200, 100);
	StraightLine S1(A, D), S2(B, C);
	S1.show();
	S2.show();
	this->Quadrants = 4;
}

void Sheet::setquadrant(int quad)
{
	this->Quadrants = quad;
}

int Sheet::getquadrant()
{
	return this->Quadrants;
}
void Sheet::show()
{
	this->x_axis.show();
	this->y_axis.show();
}

Sheet::~Sheet()
{
}