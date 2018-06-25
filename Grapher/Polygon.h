#pragma once
#include "Graph.h"
#include"StraightLine.h"
class Polygon :public Graph
{
public:
	Polygon();
	void show();
	void work();
	~Polygon();
private:
	StraightLine line;
};

