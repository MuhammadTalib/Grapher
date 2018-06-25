
#include<stdlib.h>
#include<GL/glut.h>
#include "Point.h"
#include"Graphics.h"

Point::Point()
{
	this->x = 0;
	this->name = "";
	this->y = 0;
}
Point::Point(int x, int y)
{
	this->x = x;
	this->name = "";
	this->y = y;
}
Point::Point(string name, int x, int y)
{
	this->x = x;
	this->name = name;
	this->y = y;
}
Point::Point(const Point & P)
{
	this->x = P.x;
	this->y = P.y;
	this->name = P.name;
}

int Point::getx()
{
	return this->x;
}
int Point::gety()
{
	return this->y;
}

void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::setx(int x)
{
	this->x = x;
}

void Point::sety(int y)
{
	this->y = y;
}


void Point::show()
{
	Graphics G;
	G.drawpoint(this->x, this->y);
}

void Point::operator=(Point P)
{
	this->x = P.x;
	this->y = P.y;
	this->name = P.name;
}
ostream & operator<<(ostream & o, Point& P)
{
	Graphics G;
	G.drawpoint(P.x, P.y);
	return o << "Point "<<P.name<<endl<<"X is ="<<P.x<<endl << "Y is =" << P.y;
	
}
istream& operator>>(istream & in, Point &P)
{
	cout<< "                        X Coordinate:";
	in >> P.x;
	P.x += 100;
	cout<<"                        Y Coordinate:";
	in >> P.y;
	cout << endl;
	P.y += 100;
	return in;
}
Point::~Point()
{
}

