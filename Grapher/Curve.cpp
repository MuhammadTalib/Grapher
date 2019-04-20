#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Point.h"
#include "Curve.h"
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
Curve::Curve(Coordinate_System *C) :Shape()
{
	this->c = C;
}
void Curve::work(Point& Centre)
{
	Graphics G;

	glPointSize(1);
	int name = 65;
	char status = 'y';
	string equa = "";
	
	Point *Q=new Point;
	int i = 1;
	cout << "|                        Enter Equation:Y= ";
	


	LinkedList<char> *infix = new LinkedList<char>;
	string val;
	cin >> val;
	G.setcolor(1, 0, 0);
	G.displaystring(this->c->getx_points()/2, this->c->gety_points() + (this->c->gety_points()/2) , val, GLUT_BITMAP_TIMES_ROMAN_24);

	char *value = new char;
	*value = val[0];
	int j = 1;
	while (*value != '$')
	{
		infix->AddNode(value);
		value = new char;
		*value = val[j];
		j++;
	}
	ExpressionTree *equatree = new ExpressionTree(infix);
	equatree->Infix_ToPostfixConversion();

	equatree->postfix->display();
	float c = (this->c->getx_smallboxes() / (this->c->getNo_of_x_bigboxes() * 50.00));
	for (float l = c; l < this->c->getx_smallboxes(); l =l+ c)
	{
		float *x_value = new float;
		*x_value = l;


		Point *P = new Point(l, equatree->Evaluate(x_value));
		*P += Centre;
		this->PointsTree->insert(P);

		float *Minusx_value = new float;
		*Minusx_value = l*(-1.0);

		Point *O = new Point(l*(-1.0),equatree->Evaluate(Minusx_value));
		*O += Centre;
		this->PointsTree->insert(O);

	}
	this->drawlinesInCurve(this->PointsTree);

	
	
}

void Curve::setline(StraightLine & line)
{
	//this->line = line;
}

void Curve::drawlinesInCurve(AVLTree<Point>* tree)
{
	if (tree != NULL)
	{
		if (tree->getLeftChild() != NULL)
		{
			this->drawlinesInCurve(tree->getLeftChild());
		}
		if(tree->getLeftChild()!=NULL)
			this->LinesTree->insert(new StraightLine(*(tree->getLeftChild()->getValue()), *(tree->getValue())));
		this->drawlinesInCurve(tree->getRightChild());
		if (tree->getRightChild() != NULL)
			this->LinesTree->insert(new StraightLine(*(tree->getRightChild()->getValue()), *(tree->getValue())));

	}
}

void Curve::show(Point* Centre)
{
	this->PointsTree->show();
	this->LinesTree->show();
}

void Curve::save(ofstream& o, string filename)
{
	o << "Polygon";
	o << endl;
	//this->Points_Array.save(o, filename);
	o << "End";
	o << endl;
}
Curve::~Curve()
{
}
