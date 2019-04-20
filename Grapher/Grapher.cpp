#pragma once

#include"Graphics.h"
#include<iostream>
#include<fstream>
using namespace std;
#include"Grapher.h"
#include"Coordinate_System.h"
#include"Shape.h"
#include<stdlib.h>
#include<GL/glut.h>
#include"Point.h"
#include"StraightLine.h"
#include"Shape_Array.h"
#include"Polygon.h"
#include"Curve.h"
#include <sstream> 
void display(void);
void readShapeFromGraph(ifstream& myfile, Shape **S);
Grapher::Grapher()
{
	Graphics G("Grapher 1.0", 500, 500);
	G.setcolor(0.0, 1.0, 0.0);
	
	int status=1,state;
	cout << "|**************************************************************|" << endl;
	cout << "|**************************************************************|" << endl;
	cout << "|******************          Grapher          *****************|" << endl;
	cout << "|**************************************************************|"<<endl;
	cout << "|**                                                          **|" << endl;
	cout << "|*                                                            *|" << endl;
	cout << "|                  What do you want to draw:                   |" << endl;
	cout << "|                  1:New                                       |" << endl;
	cout << "|                  2:Open Existing                             |" << endl;
	cout << "|*                                                            *|" << endl;
	cout << "|**                                                          **|" << endl;
	cout << "|**************************************************************|" << endl;
	cout << "|                  Please Enter Your Option:";
	cin >> state;
	
	if (status == 1)
	{
		if (state == 1)
		{
			system("CLS");
			this->UserInput();
		}
		else if (state == 2)
		{
			this->FileInput();
			state = 1;
		}
	}
		do
		{
			system("CLS");
			cout << "|**************************************************************|" << endl;
			cout << "|**************************************************************|" << endl;
			cout << "|******************          Grapher          *****************|" << endl;
			cout << "|**************************************************************|" << endl;
			cout << "|**                                                          **|" << endl;
			cout << "|*                                                            *|" << endl;
			cout << "|                  What do you want to do???                   |" << endl;
			cout << "|                  1:Add More Graph to same sheet              |" << endl;
			cout << "|                  2:Search Something??                        |" << endl;
			cout << "|                  3:Delete Something??                        |" << endl;
			cout << "|                  4:Save and Exit                             |" << endl;
			cout << "|                  5:Show Sheet                                |" << endl;
			cout << "|                  6:Exit                                      |" << endl;
			cout << "|                  7:Add Copy Of Existing                                      |" << endl;
			cout << "|*                                                            *|" << endl;
			cout << "|**                                                          **|" << endl;
			cout << "|**************************************************************|" << endl;
			cin >> status;
			if (status == 1)
			{
				if (state == 1)
				{
					system("CLS");
					this->UserInput();
				}
				else if (state == 2)
				{
					this->FileInput();
					state = 1;
				}
			}
			Point Centre('o',this->Graph_Sheet->getx_points() , this->Graph_Sheet->gety_points());
			glPointSize(8);
			Centre.show(&Centre);
			
			if (status == 2)
			{

			}
			else if (status == 3)
			{
				int c;
				system("CLS");
				cout << "|**************************************************************|" << endl;
				cout << "|**************************************************************|" << endl;
				cout << "|******************          Grapher          *****************|" << endl;
				cout << "|**************************************************************|" << endl;
				cout << "|                  What do you want to delete??                |" << endl;
				cout << "|                  1:Grapher                                   |" << endl;
				cout << "|                  2:Graph                                     |" << endl;
				cout << "|                  3:StraightLine                              |" << endl;
				cout << "|                  4:Point                                     |" << endl;
				cout << "|**************************************************************|" << endl;
				cin >> c;
				if (c == 1)
				{
					this->ShapeArray.deleteShapeArray();
				}
				else if (c == 2)
				{	//this->ShapeArray.deleteShapeArray(1);
				}
				else if (c == 3)
				{
					int i;
					Shape A;
					cout << "Which Shape??" << endl;
					cin >> i;
					i--;
					//this->ShapeArray.deleteLine(i);
				}
				else if (c == 4)
				{
					int i;
					Shape A;
					cout << "Which Shape??" << endl;
					cin >> i;
					i--;
					//this->ShapeArray.deletePoint(i);
				}
				this->ShapeArray.show(&Centre);
			}
			else if (status == 4)
			{
				string filename;
				cout << "Please enter a file name to write: ";
				cin>> filename;

				ofstream o(filename);

				o << this->Graph_Sheet->getx_points();
				o << endl;
				o << this->Graph_Sheet->gety_points();
				o << endl;

				this->ShapeArray.save(o,filename);
				this->ShapeArray.show(&Centre);
				break;
			}
			else if (status == 5)
			{
				this->ShapeArray.show(&Centre);
			}
			else if(status == 6)
			{
				exit(0);
			}
			else if (status == 7)
			{
				cout << "Copy of which shape??" << endl;
				int i;
				cin >> i;
				i--;
				//Shape S((Shape&)this->ShapeArray.getGraphfromindex(i));
				glColor3f(1, 0, 1);
				//S += 10;
			//	this->ShapeArray.addgraph(&S);
			}

		} while (status!=5);
		
		G.setcolor(5.0, 1, 0);
		G.Colourfulrectangle(0, this->Graph_Sheet->gety_points()*2, 0, this->Graph_Sheet->gety_points()*2 + this->Graph_Sheet->getupperarea_y(), this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2, this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2 + this->Graph_Sheet->getupperarea_y()*2);
		glLineWidth(10);
		G.setcolor(1, 0, 0);

		G.drawline(0, this->Graph_Sheet->gety_points()*2 + this->Graph_Sheet->getupperarea_y(), this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2 + this->Graph_Sheet->getupperarea_y());
		G.drawline(0, this->Graph_Sheet->gety_points()*2, this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2);
		G.drawline(0, this->Graph_Sheet->gety_points()*2, 0, this->Graph_Sheet->gety_points()*2 + this->Graph_Sheet->getupperarea_y());
		G.drawline(this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2, this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2 + this->Graph_Sheet->getupperarea_y());
		G.setcolor(1, 0, 0);
		glLineWidth(7);
		G.setcolor(1, 0, 0);
		this->BorderLines.settotal_lines(4);

		glLineWidth(10);
		this->BorderLines.addline(StraightLine(Point(0, 0), Point(0, this->Graph_Sheet->gety_points()*2)), StraightLine(Point(0, 0), Point(this->Graph_Sheet->getx_points()*2, 0)), StraightLine(Point(0, this->Graph_Sheet->gety_points()*2), Point(this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2)), StraightLine(Point(this->Graph_Sheet->getx_points()*2, 0), Point(this->Graph_Sheet->getx_points()*2, this->Graph_Sheet->gety_points()*2)));
		this->BorderLines.show();
		G.displaystring((this->Graph_Sheet->getx_points() )- this->Graph_Sheet->getx_points()/10, this->Graph_Sheet->gety_points()*2 +(this->Graph_Sheet->getupperarea_y()/2), "Grapher", GLUT_BITMAP_TIMES_ROMAN_24);


	glutDisplayFunc(display);
	glutSwapBuffers();
	glFlush();
	glutMainLoop();
}

void Grapher::UserInput()
{
	Graphics G;
	this->Graph_Sheet = new Coordinate_System(100.00, 100.00, 6.00, 6.00);
	G.setline_width(2);
	G.setcolor(0.0, 0.0, 1.0);
	this->Graph_Sheet->show();
	int status;
	cout << "|**************************************************************|" << endl;
	cout << "|**                                                          **|" << endl;
	cout << "|*                                                            *|" << endl;
	cout << "|                  What do you want to draw:                   |" << endl;
	cout << "|                  1:Graph                                     |" << endl;
	cout << "|                  2:Polygon                                   |" << endl;
	cout << "|                  3:Curve                                     |" << endl;
	cout << "|*                                                            *|" << endl;
	cout << "|**                                                          **|" << endl;
	cout << "|**************************************************************|" << endl;
	cout << "|                  Please Enter Your Option:";
	cin >> status;
	cout << "                   |" << endl;
	while (status != 1 && status != 2 && status != 3)
	{
		cout << "|                  Wrong Input! Please Re-enter:" << endl;
		cout << "|                  ";
		cin >> status;
	}
	Point Centre(this->Graph_Sheet->getx_points(), this->Graph_Sheet->gety_points());
	if (status == 1)
	{
		Shape* graph = new Shape;
		graph->work(Centre);
		this->ShapeArray.addgraph(graph);
	}
	else if(status == 2)
	{
		Shape* graph = new Polygon;
		graph->work(Centre);
		this->ShapeArray.addgraph(graph);
	}
	else
	{
		Shape* graph = new Curve(this->Graph_Sheet);
		graph->work(Centre);
		this->ShapeArray.addgraph(graph);
	}
}

void Grapher::FileInput()
{
	StraightLine L;
	string line;

	string filename;
	cout << "Enter Saved File Name:";
	cin >> filename;
	
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		Graphics G;

		int vertex;
		getline(myfile, line);
		stringstream geeks(line);
		geeks >> vertex;

		int vertey;
		getline(myfile, line);
		stringstream geek(line);
		geek >> vertey;

		this->Graph_Sheet = new Coordinate_System(vertex, vertey,4,4);
		G.setline_width(2);
		G.setcolor(0.0, 0.0, 1.0);
		this->Graph_Sheet->show();

		Shape *S;
		while (getline(myfile, line))
		{
			if (line == "Shape")
			{
				S = new Shape;
				readShapeFromGraph(myfile, &S);
				this->ShapeArray.addgraph(S);
			}
			else if(line == "Polygon")
			{
				S = new Polygon;
				/*
				same as readshapefromgraph();
				L.set(R,Q);
				S->setline(L);*/

				readShapeFromGraph(myfile, &S);
				Point *T=S->getpointsTree()->getFirstNode();
				Point *W = S->getpointsTree()->getLastNode();
				L.set(*T,*W);
				S->setline(L);
				this->ShapeArray.addgraph(S);
				
			}
		}
		
		myfile.close();
		
	}

	else cout << "Unable to open file";
}
void readShapeFromGraph(ifstream& myfile,Shape **S)
{
	Point *P=new Point, *Q = new Point;
	StraightLine *L=new StraightLine;
	string line;
	float vertex;
	char name;

	getline(myfile, line);
	stringstream geeek(line);
	geeek >> name;
	P->setname(name);
	cout << name;

	getline(myfile, line);
	stringstream geek(line);
	geek >> vertex;
	P->setx(vertex);

	getline(myfile, line);
	stringstream y(line);
	y >> vertex;
	P->sety(vertex);

	(*S)->getpointsTree()->insert(P);
	getline(myfile, line);
	while (line != "End")
	{
		stringstream geeeks(line);
		geeeks >> name;
		Q->setname(name);
		cout << name;

		getline(myfile, line);
		stringstream geek(line);
		geek >> vertex;
		Q->setx(vertex);

		getline(myfile, line);
		stringstream y(line);
		y >> vertex;
		Q->sety(vertex);

		(*S)->getpointsTree()->insert(Q);
		L->set(*P, *Q);
		(*S)->getLinesTree()->insert(L);
		P = Q;
		getline(myfile, line);
	}
}
void display(void)
{
	glEnd();
	glFlush();
}
Grapher::~Grapher()
{
}

void Grapher::deleteGrapher()
{
	//this->ShapeArray.deleteShapeArray();
}
