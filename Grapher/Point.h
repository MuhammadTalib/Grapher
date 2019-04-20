#pragma once
#include"Graphics.h"
class Point
{
public:
	Point();
	Point(float x, float y);
	Point(char name, float x, float y);
	Point(const Point& P);

	float getx();
	float gety();
	void set(float x, float y);
	void setx(float x);
	void sety(float y);
	void setname(char name);
	void show(Point *Centre);
	void show();
	void showCircledPoint(Point *Centre);
	void save(ofstream& o,string filename);
	Point readfromfile(ifstream& i);
	void deletePoint();

	friend ostream& operator <<(ostream& o,Point& P);
	friend istream& operator >>(istream& in, Point& P);
	friend Point operator +=(Point& O,Point& X);
	friend bool operator <(Point& O, Point& P);
	friend bool operator >(Point& O, Point& P);
	friend bool operator <=(Point& O, Point& P);
	friend bool operator >=(Point& O, Point& P);
	friend bool operator ==(Point& O, Point& P);

	void operator = (Point& P);
	Point operator += (int add);

	~Point();
private:
	float x;
	float y;
	char name;
};

