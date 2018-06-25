#pragma once
#include"Point.h"
class StraightLine
{
public:
	StraightLine();
	StraightLine(Point P);
	StraightLine(Point startpoint,Point endpoint);
	StraightLine(Point startpoint, Point endpoint, string name);
	StraightLine(int x1, int y1, int x2, int y2);
	StraightLine(StraightLine& S);

	void set(Point p, Point q);
	void show();

	friend ostream& operator <<(ostream& o, StraightLine& S);
	friend istream& operator >>(istream& o, StraightLine& S);
	StraightLine operator = (StraightLine& S);

	~StraightLine();
private:
	string name;
	Point startpoint;
	Point endpoint;
};

