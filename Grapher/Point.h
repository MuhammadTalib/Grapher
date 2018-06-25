#pragma once
#include"Graphics.h"
class Point
{
public:
	Point();
	Point(int x, int y);
	Point(string name, int x, int y);
	Point(const Point& P);

	int getx();
	int gety();
	void set(int x,int y);
	void setx(int x);
	void sety(int y);
	void show();

	friend ostream& operator <<(ostream& o,Point& P);
	friend istream& operator >>(istream& in, Point& P);

	void operator = (Point P);
	
	~Point();
private:
	int x;
	int y;
	string name;
};

