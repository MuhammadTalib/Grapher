
#include<stdlib.h>
#include<GL/glut.h>
#include "Point.h"
#include"Graphics.h"
#include<fstream>
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

void Point::save(ofstream& o,string filename)
{
	o.write((char*)&this->x, sizeof(this->x));
	o.write((char*)&this->y, sizeof(this->y));
}

void Point::operator=(Point& P)
{
	this->x = P.x;
	this->y = P.y;
	this->name = P.name;
}
Point Point::operator+=(int add)
{
	this->x += add;
	return *this;
}
ostream & operator<<(ostream & o, Point& P)
{
	return o << "Point "<<P.name<<endl<<"X is ="<<P.x-100<<endl << "Y is =" << P.y-100;
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
void Point::deletePoint()
{
	this->x = 0;
	this->y = 0;
}
Point::~Point()
{
}

