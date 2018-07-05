#include"Shape.h"
#include<iostream>
#include<fstream>
using namespace std;
Shape::Shape()
{
	this->total=6;
	this->count=0;
}
Shape::Shape(Shape & P)
{
	this->total =P.total;
	this->count = P.count;
	this->Points_Array = P.Points_Array;
	this->Line_Array = P.Line_Array;
}
void Shape::setPointinPointArray(Point & P)
{
	this->Points_Array.addpoint(P);
}
void Shape::setLineinLineArray(StraightLine & S)
{
	this->Line_Array.addline(S);
}
void Shape::work()
{

	char status = 'y';
	Point P;
	Point Q;
	Point R(36, 54);
	Point S(35, 35);
	int i = 1;
	cout << "|                        Enter Point " << i << "                         |" << endl;
	i++;
	cin >> P;
	this->Points_Array.addpoint(P);
	do
	{
		cout << "|                        Enter Point " << i << "                         |"<<endl;
		i++;
		cin >> Q;
		this->Points_Array.addpoint(Q);
		StraightLine S(P, Q);
		this->Line_Array.addline(S);
		P = Q;

		cout << "|                  1:Enter More Points(Y/N)";
		cin >> status;
		cout << "|**************************************************************|" << endl;

	} while (status == 'y' || status == 'Y');
	
}
void Shape::show()
{
	this->Points_Array.show();
	this->Line_Array.show();
}

void Shape::save(ofstream& o, string filename)
{
	this->Line_Array.save(o, filename);
}

Shape& Shape::operator=(Shape & P)
{
	this->total = P.total;
	this->count = P.count;
	this->Points_Array = P.Points_Array;
	this->Line_Array = P.Line_Array;
	return *this;
}

Shape Shape::operator+=(int add)
{

	this->Points_Array += add;
	this->Line_Array += add;
	return *this;
}


Point Shape::getpointfromPoint_Array(int x)
{
	Point P;
	P =(Point&)this->Points_Array.getindexpoint(x);
	return P;

}
void Shape::deleteShape()
{
	this->Line_Array.deleteLineArray();
	this->Points_Array.deletePointArray();
}

void Shape::deleteLine(int j)
{
	this->Line_Array.deleteLine(j);
}
void Shape::deletePoint(int j)
{
	this->Points_Array.deletePoint(j);
	if (j == 0)
	{
		this->Line_Array.deleteLine(j);
	}
	else if (j==this->Points_Array.getcount())
		this->Line_Array.deleteLine(j - 1);
	else
	{
		this->Line_Array.deleteLine(j - 1);
		this->Line_Array.deleteLine(j);
		//doing work
		this->Points_Array.getindexpoint(j - 1);
		this->Points_Array.getindexpoint(j + 1);
		StraightLine S(this->Points_Array.getindexpoint(j - 1),this->Points_Array.getindexpoint(j + 1));
		S.show();
	}
}


