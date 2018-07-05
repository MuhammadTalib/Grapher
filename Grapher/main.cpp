#include<iostream>
using namespace std;
#include<string>
#include <fstream>
#include"Graphics.h"
#include"Point.h"
#include"Point_Array.h"
#include"StraightLine.h"
#include"Line_Array.h"
#include"Shape_Array.h"
#include"Grapher.h"
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	Grapher G;
	glFlush();

	glutMainLoop();
	cout << endl;
	system("pause");
	return 0;
}
