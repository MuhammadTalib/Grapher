#pragma once
#include "Shape.h"
#include"StraightLine.h"
class Polygon :public Shape
{
public:
	Polygon();
	void show();
	void work();
	~Polygon();
private:
	StraightLine line;
};

