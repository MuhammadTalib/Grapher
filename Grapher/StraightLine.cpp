#include "Point.h"
#include "StraightLine.h"
#include<fstream>
StraightLine::StraightLine()
{
	Point P(0, 0);
	this->name="";
	this->startpoint=P;
	this->endpoint=P;
}

StraightLine::StraightLine(Point& P)
{
	Point Q(0, 0);
	this->name = "";
	this->startpoint =Q;
	this->endpoint = P;
}
StraightLine::StraightLine(Point startpoint, Point endpoint)
{
	this->name = "";
	this->startpoint = startpoint;
	this->endpoint = endpoint;
}


StraightLine::StraightLine(Point& startpoint, Point& endpoint, string name)
{
	this->name = name;
	this->startpoint = startpoint;
	this->endpoint = endpoint;
}

StraightLine::StraightLine(int x1, int y1, int x2, int y2)
{
	Point Q(x1, y1);
	Point P(x2, y2);
	this->name = "";
	this->startpoint = Q;
	this->endpoint = P;
}

StraightLine::StraightLine(const StraightLine& S)
{
	this->name = S.name;
	this->startpoint = (Point&)S.startpoint;
	this->endpoint = (Point&)S.endpoint;
}

void StraightLine::set(Point& p, Point& q)
{
	this->startpoint = p;
	this->endpoint = q;
}

void StraightLine::show()
{
	Graphics G;
	G.drawline(this->startpoint.getx(),this->startpoint.gety(),this->endpoint.getx(), this->endpoint.gety());
}

void StraightLine::save(ofstream& o,string filename)
{
	this->startpoint.save(o, filename);
	this->endpoint.save(o, filename);
}

StraightLine StraightLine::operator=(StraightLine & S)
{
	this->name = S.name;
	this->startpoint = S.startpoint;
	this->endpoint = S.endpoint;
	return *this;
}

StraightLine StraightLine::operator+=(int add)
{
	this->endpoint += add;
	this->startpoint += add;
	return *this;
}

ostream & operator<<(ostream & o, StraightLine& S)
{
	return o <<"Straight Line"<<endl<<"Start Point:"<<S.startpoint<<"End Point:"<<S.endpoint<<endl;
}

istream & operator>>(istream & o, StraightLine& S)
{
	cout << "Enter Straight Line" << endl << "StartPoint:";
	cin >> S.startpoint;
	cout << "End Point:";
	return o >> S.endpoint;
}
void StraightLine::deleteLine()
{
	this->endpoint.deletePoint();
	this->startpoint.deletePoint();
}

StraightLine::~StraightLine()
{
}


