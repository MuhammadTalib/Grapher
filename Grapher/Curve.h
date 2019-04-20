#pragma once
#include "Shape.h"
#include"StraightLine.h"
#include"Coordinate_System.h"
class Curve:public Shape
{
public:
	Curve(Coordinate_System *C);
	void show(Point* Centre);
	void work(Point& Centre);
	void setline(StraightLine &line);
	void drawlinesInCurve(AVLTree<Point>* tree);
	void save(ofstream& o, string filename);
	~Curve();
private:
	Coordinate_System *c;
	LinkedList<char> Equation;
};

