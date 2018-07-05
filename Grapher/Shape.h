#pragma once
#include"Point.h"
#include"Point_Array.h"
#include"StraightLine.h"
#include"Line_Array.h"
class Shape {
public:
	Shape();
	Shape(Shape& P);

	void setPointinPointArray(Point &P);
	void setLineinLineArray(StraightLine &S);
	virtual void work();
	virtual void show();
	void save(ofstream& o, string filename);
	void deleteShape();
	void deleteLine(int j);
	void deletePoint(int j);

	Shape& operator = (Shape& P);
	Shape operator +=(int add);

private:
	int total;
	int count;
	
protected:
	Point_Array Points_Array;
	Line_Array Line_Array;
	Point getpointfromPoint_Array(int x);
};
