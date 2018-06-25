#pragma once
#include"Point.h"
#include"Point_Array.h"
#include"StraightLine.h"
#include"Line_Array.h"
class Graph {
public:
	Graph();

	virtual void work();
	virtual void show();
private:
	int total;
	int count;
	
protected:
	Point_Array Points_Array;
	Line_Array Line_Array;
	Point getpointfromPoint_Array(int x);
};
