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
	this->PointsTree = P.PointsTree;
	this->LinesTree = P.LinesTree;
}
void Shape::setPointinPointTree(Point * P)
{
	this->PointsTree->insert(P);
}
void Shape::setLineinLineArray(StraightLine * S)
{
	this->LinesTree->insert(S);
}
void Shape::work(Point& Centre)
{
	int name = 65;
	char status = 'y';
	Point *P=new Point;
	Point *Q=new Point;
	int i = 1;
	cout << "|                        Enter Point " << i << "                         |" << endl;
	i++;
	cin >> *P;
	*P += Centre;
	P->setname(name);
	name++;
	this->PointsTree->insert(P);
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
	
}
void Shape::show(Point *Centre)
{
	glPointSize(6);
	this->PointsTree->show(Centre);
	this->LinesTree->show();
	
}

void Shape::setline(StraightLine & L)
{
}
/*
void Shape::save(ofstream& o, string filename)
{
	o << "Shape";
	o << endl;
	this->Points_Array.save(o, filename);
	o << "End";
	o << endl;
}

Point Shape::getpoint(int index)
{
	Point P =this->PointsTree.getindexpoint(index);
	return P;
}
}*/

AVLTree<Point>* Shape::getpointsTree()
{
	return this->PointsTree;
}

AVLTree<StraightLine>* Shape::getLinesTree()
{
	return this->LinesTree;
}

Shape& Shape::operator=(Shape & P)
{
	this->total = P.total;
	this->count = P.count;
	this->PointsTree = P.PointsTree;
	this->LinesTree = P.LinesTree;
	return *this;
}

Shape Shape::operator+=(int add)
{

	this->PointsTree += add;
	this->LinesTree += add;
	return *this;
}

void Shape::deleteShape()
{
	this->LinesTree->deleteTree();
	this->PointsTree->deleteTree();
}
/*
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
*/

