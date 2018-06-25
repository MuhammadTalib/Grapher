#pragma once
#include"Point.h"
#include "Polygon.h"
Polygon::Polygon():Graph()
{
}
void Polygon::work()
{
	this->Graph::work();
	Point P;
	P = this->getpointfromPoint_Array(0);
	Point Q;
	Q = this->getpointfromPoint_Array(this->Points_Array.getcount() - 1);
	cout << this->Points_Array.getcount();
	StraightLine S(P, Q);
	this->line = S;
}

void Polygon::show()
{
	cout << "sded";
	this->line.show();
	this->Graph::show();
}

Polygon::~Polygon()
{
}
