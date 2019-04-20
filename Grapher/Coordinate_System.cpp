#include"Coordinate_System.h"
#include "Point.h"
#include"StraightLine.h"
#include<string>
#include<string.h>
#include <sstream>    
#include <math.h>
using namespace std;

Coordinate_System::Coordinate_System(float x_points,float y_points, float No_of_x_bigboxes, float No_of_y_bigboxes)
{
	this->No_of_x_bigboxes = No_of_x_bigboxes+0.0;
	this->No_of_y_bigboxes = No_of_y_bigboxes+0.0;

	this->x_smallboxes = x_points/2;
	this->y_smallboxes = y_points/2;
	this->upperarea_y = y_points / 4;

	Graphics G;

	gluOrtho2D(0.0, this->x_smallboxes*2, 0.0, this->y_smallboxes*2+this->upperarea_y);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0,0,0);
	
	G.setline_width(2);
	G.setcolor(0, 0, 0);

	Point A(0, (this->y_smallboxes)),B((this->x_smallboxes) ,0),C((this->x_smallboxes),this->y_smallboxes*2),D(this->x_smallboxes * 2, (this->y_smallboxes));
	StraightLine S1(A, D),S2(B,C);

	this->x_axis = S1;
	this->y_axis = S2;
	this->Quadrants = 4;
	this->drawscale();
	
	
}
Coordinate_System::Coordinate_System()
{
	Graphics G;
	G.setline_width(2);
	G.setcolor(0, 0, 0);

	Point A(0, 99), B(99, 0), C(99, 199), D(199, 99);
	StraightLine S1(A, D), S2(B, C);

	this->x_axis = S1;
	this->y_axis = S2;
	this->Quadrants = 4;
}

void Coordinate_System::setquadrant(int quad)
{
	this->Quadrants = quad;
}

void Coordinate_System::drawscale()
{
	glColor4f(1, 0, 1, 1);
	double x_box_size = (this->getx_points() / (this->No_of_x_bigboxes*10))+0.0;
	double y_box_size = this->gety_points() / (this->No_of_y_bigboxes*10);
	double focusXPoint = (this->getx_points()/ this->No_of_x_bigboxes)+0.0;
	double focusYPoint = this->gety_points() / this->No_of_y_bigboxes;

	Graphics G;
	
	double fPx = focusXPoint+0.0;
	fPx = roundf(fPx * 10) / 10;
	double fpy = focusYPoint;

	int status_i = 0;
	for (float i = x_box_size; i < this->getx_points() ;  i=i+x_box_size)
	{
		glLineWidth(1);
		if (status_i==9 )
		{
			glColor3f(0, 0, 1);
			G.drawline(i, (this->gety_points() ) - x_box_size- (x_box_size), i, (this->gety_points() ) + x_box_size + (x_box_size ));
			G.drawline(i + (this->getx_points() ), (this->gety_points() ) - x_box_size - (x_box_size ), i + (this->getx_points() ), (this->gety_points()) + x_box_size + (x_box_size ));
			float print_i = roundf(i*100)/100;
			float Negative_i = print_i - (this->getx_points());
			ostringstream ostr;
			ostr << print_i;
			string s = ostr.str();
			ostringstream ostr1;
			ostr1 << Negative_i;
			string Neg_s = ostr1.str();
			if (Neg_s != "0")
			{
				G.displaystring(i - (x_box_size * 2), (this->gety_points()) - x_box_size - (x_box_size * 3), Neg_s, GLUT_BITMAP_HELVETICA_10);
				G.displaystring(i + (this->getx_points()) - (x_box_size * 2), (this->gety_points()) - x_box_size - (x_box_size * 3), s, GLUT_BITMAP_HELVETICA_10);
			}
			focusXPoint += fPx;
			glColor4f(1, 0, 1, 1);
			status_i = 0;
		}
		else
		{
			G.drawline(i, (this->gety_points()) - x_box_size, i, (this->gety_points()) + x_box_size);
			G.drawline(i + (this->getx_points()), (this->gety_points()) - x_box_size, i + (this->getx_points()), (this->gety_points()) + x_box_size);
			status_i++;
		}
		glLineWidth(2);
	}
	status_i = 0;
	for (float i = y_box_size; i < this->gety_points() ; i += y_box_size)
	{
		glLineWidth(1);
		if (status_i == 9 )
		{
			glColor3f(0, 0, 1);
			G.drawline((this->getx_points()) - y_box_size - (y_box_size), i, (this->getx_points()) + y_box_size + (y_box_size), i);
			G.drawline((this->getx_points()) - y_box_size - (y_box_size), i + (this->gety_points()), (this->getx_points()) + y_box_size + (y_box_size), i + (this->gety_points()));
			float print_i = roundf(i * 100) / 100;
			float Negative_i = print_i - (this->gety_points());
			ostringstream ostr;
			ostr << print_i;
			string s = ostr.str();
			ostringstream ostr1;
			ostr1 << Negative_i;
			string Neg_s = ostr1.str();
			if (Neg_s != "0")
			{
				G.displaystring((this->getx_points()) - y_box_size - (y_box_size * 7), i - y_box_size, Neg_s, GLUT_BITMAP_8_BY_13);
				G.displaystring((this->getx_points()) - y_box_size - (y_box_size * 5), i + (this->gety_points()) - y_box_size, s, GLUT_BITMAP_HELVETICA_10);
			}
			focusYPoint += fpy;
			glColor4f(1, 0, 1, 1);
			status_i = 0;
		}
		else
		{
			G.drawline((this->getx_points() ) - y_box_size, i, (this->getx_points() ) + y_box_size, i);
			G.drawline((this->getx_points() ) - y_box_size, i + (this->gety_points()), (this->getx_points()) + y_box_size, i + (this->gety_points()));
			status_i++;
		}
		glLineWidth(2);
	}

	
}

int Coordinate_System::getquadrant()
{
	return this->Quadrants;
}
float Coordinate_System::getx_points()
{
	return this->x_smallboxes;
}
float Coordinate_System::gety_points()
{
	return this->y_smallboxes;
}
float Coordinate_System::getx_smallboxes()
{
	return this->x_smallboxes;
}
float Coordinate_System::gety_smallboxes()
{
	return this->y_smallboxes;
}
float Coordinate_System::getNo_of_x_bigboxes()
{
	return this->No_of_x_bigboxes;
}
float Coordinate_System::getNo_of_y_bigboxes()
{
	return this->No_of_y_bigboxes;
}
float Coordinate_System::getupperarea_y()
{
	return this->upperarea_y;
}
void Coordinate_System::show()
{
	this->x_axis.show();
	this->y_axis.show();
}

Coordinate_System::~Coordinate_System()
{
	cout << "Coordinate System";
}
