#include<stdlib.h>

#include<GL/glut.h>
#include "Point.h"
#include"Graphics.h"
#include<fstream>
int myrandom(int m);
Point::Point()
{
	this->x = 0;
	this->name = 'A';
	this->y = 0;
}
Point::Point(float x, float y)
{
	this->x = x;
	this->name = 'A';
	this->y = y;
}
Point::Point(char name, float x, float y)
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

float Point::getx()
{
	return this->x;
}
float Point::gety()
{
	return this->y;
}

void Point::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::setx(float x)
{
	this->x = x;
}

void Point::sety(float y)
{
	this->y = y;
}

void Point::setname(char name)
{
	this->name = name;
}

void Point::show()
{
	Graphics G;
	glPointSize(2);
	glColor3f(0, 1, 0);
	G.drawpoint(this->x, this->y);
	G.setcolor(0, 1, 0);
}

void Point::show(Point *Centre)
{
	Graphics G;
	glColor3f(0, 1, 0);
	G.drawpoint(this->x, this->y);
	G.setcolor(1.0, 0.0, 0.0);
	G.displaychar(this->x - (Centre->getx() / 100) * 6, this->y - (Centre->gety() / 100) * 6, this->name);
	G.setcolor(0, 1, 0);
}
void Point::showCircledPoint(Point *Centre)
{
	Graphics G;
	glPointSize(5);
	G.drawpoint(this->x, this->y);
	G.setcolor(1.0, 0.0, 1.0);
	G.drawcircle(this->x, this->y, (Centre->getx() / 100) * 2);
	glPointSize(5);
	G.setcolor(1.0, 0.0, 0.0);
	G.displaychar(this->x - (Centre->getx() / 100) * 6, this->y - (Centre->gety() / 100) * 6, this->name);
	G.setcolor(0, 1, 0);
}

void Point::save(ofstream& o,string filename)
{
	//o.write((char*)&this->x, sizeof(this->x));
	//o.write((char*)&this->y, sizeof(this->y));
	
	o << this->name;
	o << endl;
	o << this->x;
	o << endl;
	o << this->y;
	o << endl;
}

Point Point::readfromfile(ifstream & i)
{
	
	Point P;
	/*
	int Store;
	i.read((char*)&Store, sizeof(Store));
	P.setx(Store);
	i.read((char*)&Store, sizeof(Store));
	P.sety(Store);
	*/
	return P;
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
	return o << "Point "<<P.name<<endl<<"X is ="<<P.x<<endl << "Y is =" << P.y;
}
istream& operator>>(istream & in, Point &P)
{
	cout<< "                        X Coordinate:";
	in >> P.x;
	//P.x += 100;
	cout<<"                        Y Coordinate:";
	in >> P.y;
	cout << endl;
	//P.y += 100;
	return in;
}

Point operator+=(Point& O, Point& X)
{
	O.x += X.x;
	O.y += X.y;
	return O;
}
bool operator<(Point & O, Point & P)
{
	if (O.x < P.x)
		return true;
	else
		return false;
}
bool operator>(Point & O, Point & P)
{
	if (O.x > P.x)
		return true;
	else
		return false;
}
bool operator<=(Point & O, Point & P)
{
	if (O.x <= P.x)
		return true;
	else
		return false;
}
bool operator>=(Point & O, Point & P)
{
	if (O.x >= P.x)
		return true;
	else
		return false;
}
bool operator==(Point & O, Point & P)
{
	if (O.x == P.x && O.y == P.y)
		return true;
	else
		return false;
}
void Point::deletePoint()
{
	this->x = 0;
	this->y = 0;
}
Point::~Point()
{
}
int myrandom(int m) 
{
	return rand() % m;
}

