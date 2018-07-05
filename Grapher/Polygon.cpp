#pragma once
#include"Point.h"
#include "Polygon.h"
Polygon::Polygon():Shape()
{
}
void Polygon::work()
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

	cout << "|                        Enter Point " << i << "                         |" << endl;
	i++;
	cin >> Q;
	this->Points_Array.addpoint(Q);
	StraightLine T(P, Q);
	this->Line_Array.addline(T);
	P = Q;
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


	Point U = (Point&)this->getpointfromPoint_Array(0);
	Point V= (Point&)this->getpointfromPoint_Array(this->Points_Array.getcount() - 1);
	StraightLine M(U, V);
	this->line = M;
	
	this->Line_Array.addline(M);
	cout << this->Line_Array;

}

void Polygon::show()
{
	this->line.show();
	this->Shape::show();
}

Polygon::~Polygon()
{
}
