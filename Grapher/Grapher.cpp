#pragma once
#include <stdlib.h>
#include"Graphics.h"
#include<iostream>
#include<fstream>
using namespace std;
#include<stdlib.h>
#include"Grapher.h"
#include"Sheet.h"
#include"Graph.h"
#include<GL/glut.h>
#include"Point.h"
#include"StraightLine.h"
#include"Graph_Array.h"
#include"Polygon.h"
void display(void);
Grapher::Grapher()
{
	const char* FILENAME="Record.txt";
	Graphics G("Grapher 1.0", 500, 500);
	Point A(1, 1), B(199, 199), C(1, 199), D(199, 1);
	StraightLine S1(A, C), S2(A, D), S3(C, B), S4(D, B);
	G.setline_width(3);
	G.setcolor(0.0, 0.0, 1.0);
	S1.show();
	S2.show();
	S3.show();
	S4.show();

	Sheet Graph_Sheet;
	Graph_Sheet.show();
	int status;
	cout << "|**************************************************************|" << endl;
	cout << "|**************************************************************|" << endl;
	cout << "|******************          Grapher          *****************|" << endl;
	do
	{
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
			Graph* graph=new Graph;
			graph->work();
			graph->show();
			this->GraphArray.addgraph(graph);
		}
		else
		{
			Graph* graph = new Polygon;
			graph->work();
			graph->show();
			this->GraphArray.addgraph(graph);
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
		cout << "|                  2:Save and Exit                             |" << endl;
		cout << "|                  3:Show Sheet                                |" << endl;
		cout << "|                  4:Exit                                      |" << endl;
		cout << "|*                                                            *|" << endl;
		cout << "|**                                                          **|" << endl;
		cout << "|**************************************************************|" << endl;
		cin >> status;
	}
	while (status == 1);
	if (status == 2)
	{
		exit(0);
	}
	else if (status == 3)
	{
		this->GraphArray.show();
	}
	else if (status == 4)
	{
		exit(0);
	}
	
	G.setcolor(0.0, 1.0, 0.0);
	G.setline_width(1);
	Point P2(190,240);
	P2.show();
	glutDisplayFunc(display);
}

void display(void)
{
	glEnd();
	glFlush();
}

