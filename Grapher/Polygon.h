#pragma once
#include "Shape.h"
#include"StraightLine.h"
class Polygon :public Shape
{
public:
	Polygon();
	void show(Point* Centre);
	void work(Point& Centre);
	void setline(StraightLine &line);
	void save(ofstream& o, string filename);
	~Polygon();
private:
	StraightLine line;
};

