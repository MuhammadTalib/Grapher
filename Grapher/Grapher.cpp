#pragma once
#include <stdlib.h>
#include"Graphics.h"
#include<iostream>
#include<fstream>
using namespace std;
#include<stdlib.h>
#include"Grapher.h"
#include"Coordinate_System.h"
#include"Shape.h"
#include<GL/glut.h>
#include"Point.h"
#include"StraightLine.h"
#include"Shape_Array.h"
#include"Polygon.h"
void display(void);
Grapher::Grapher()
{
	Graphics G("Grapher 1.0", 500, 500);
	glPointSize(6);
	glLineWidth(5);
	G.setcolor(1, 0, 0);
	this->BorderLines.settotal_lines(4);
	this->BorderLines.addline(StraightLine(Point(1, 1), Point(1, 199)), StraightLine(Point(1, 1), Point(199, 1)), StraightLine(Point(1, 199), Point(199, 199)), StraightLine(Point(199, 1), Point(199, 199)));
	this->BorderLines.show();
	
	G.setline_width(2);
	G.setcolor(0.0, 0.0, 1.0);
	this->Graph_Sheet.show();
	int status,state;
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
	
		
		do
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
		} while (status == 1);
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
			cin >> c;
			if (c == 1)
				this->ShapeArray.deleteShapeArray();
			else if (c == 2)
				this->ShapeArray.deleteShapeArray(1);
			else if (c == 3)
			{
				int i;
				Shape A;
				cout << "Which Shape??" << endl;
				cin >> i;
				i--;
				this->ShapeArray.deleteLine(i);
			}
			else if (c == 4)
			{
				int i;
				Shape A;
				cout << "Which Shape??" << endl;
				cin >> i;
				this->ShapeArray.deletePoint(i);
			}
			this->ShapeArray.show();
		}
		else if (status == 4)
		{
			string filename;
			cout << "Please enter a file name to write: ";
			getline(cin, filename);
			cin >> filename;
			//Write File

			this->ShapeArray.save(filename);
			this->ShapeArray.show();
		}
		else if (status == 5)
		{
			this->ShapeArray.show();
		}
		else if(status == 6)
		{
			exit(0);
		}
		else if (status == 7)
		{

			this->ShapeArray.show();
			cout << "Copy of which shape??"<<endl;
			int i;
			cin >> i;
			i--;
			Shape S((Shape&)this->ShapeArray.getGraphfromindex(i));
			glColor3f(1, 0, 1);
			S += 10;
			this->ShapeArray.addgraph(S);
			S.show();

		}
	
	
	glutDisplayFunc(display);
	glutSwapBuffers();
}

void Grapher::UserInput()
{
	int status;
	cout << "|**************************************************************|" << endl;
	cout << "|**                                                          **|" << endl;
	cout << "|*                                                            *|" << endl;
	cout << "|                  What do you want to draw:                   |" << endl;
	cout << "|                  1:Graph                                     |" << endl;
	cout << "|                  2:Polygon                                   |" << endl;
	cout << "|*                                                            *|" << endl;
	cout << "|**                                                          **|" << endl;
	cout << "|**************************************************************|" << endl;
	cout << "|                  Please Enter Your Option:";
	cin >> status;
	cout << "                   |" << endl;
	while (status != 1 && status != 2)
	{
		cout << "|                  Wrong Input! Please Re-enter:" << endl;
		cin >> status;
	}

	if (status == 1)
	{
		Shape* graph = new Shape;
		graph->work();

		this->ShapeArray.addgraph(graph);
	}
	else
	{
		Shape* graph = new Polygon;
		graph = (Polygon*)graph;
		graph->work();
		this->ShapeArray.addgraph(graph);
	}
}

void Grapher::FileInput()
{

	string filename;
	cout << "Enter Saved File Name:";
	cin >> filename;
	ifstream i(filename, ios::binary);

	Shape *graph = new Shape;
	int Store;
	Point P;
	Point Q;
	i.read((char*)&Store, sizeof(Store));
	P.setx(Store);
	i.read((char*)&Store, sizeof(Store));
	P.sety(Store);
	graph->setPointinPointArray(P);
	while (i.read((char*)&Store, sizeof(Store)))                  // loop getting single characters
	{
		Q.setx(Store);
		i.read((char*)&Store, sizeof(Store));
		Q.sety(Store);
		graph->setPointinPointArray(Q);
		StraightLine S(P, Q);
		graph->setLineinLineArray(S);
		P = Q;
	}

	if (i.eof())
	{
		this->ShapeArray.addgraph(graph);
	}
	else
		std::cout << "File Doesn't Exist" << endl;
	this->ShapeArray.addgraph(graph);
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
	this->ShapeArray.deleteShapeArray();
}
