#pragma once
#include"Point.h"
#include "Polygon.h"
#include<iostream>
#include<fstream>
Polygon::Polygon():Shape()
{
}
void Polygon::work(Point& Centre)
{
	int name = 65;
	char status = 'y';
	Point *P=new Point;
	Point *Q = new Point;
	int i = 1;
	cout << "|                        Enter Point " << i << "                         |" << endl;
	i++;
	cin >> *P;
	*P += Centre;
	P->setname(name);
	name++;
	this->PointsTree->insert(P);

	cout << "|                        Enter Point " << i << "                         |" << endl;
	i++;
	cin >> *Q;
	*Q += Centre;
	Q->setname(name);
	name++;
	this->PointsTree->insert(Q);
	StraightLine *T=new StraightLine(*P, *Q);
	this->LinesTree->insert(T);
	P = Q;
	do
	{
		Q = new Point;
		cout << "|                        Enter Point " << i << "                         |"<<endl;
		i++;
		cin >> *Q;
		*Q += Centre;
		Q->setname(name);
		name++;
		this->PointsTree->insert(Q);
		StraightLine *S=new StraightLine(*P, *Q);
		this->LinesTree->insert(S);
		P = Q;

		cout << "|                  1:Enter More Points(Y/N)";
		cin >> status;
		cout << "|**************************************************************|" << endl;

	} while (status == 'y' || status == 'Y');


	Point *U = this->getpointsTree()->getFirstNode();
	Point *V= this->getpointsTree()->getLastNode();
	StraightLine M(*U, *V);
	this->line = M;

}

void Polygon::setline(StraightLine & line)
{
	this->line = line;
}

void Polygon::show(Point* Centre)
{
	glPointSize(6);
	this->line.show();
	this->PointsTree->showWithCircle(Centre);
	this->LinesTree->show();

}

void Polygon::save(ofstream& o, string filename)
{
	o << "Polygon";
	o << endl;
	//this->Points_Array.save(o, filename);
	o << "End";
	o << endl;
}
Polygon::~Polygon()
{
}
