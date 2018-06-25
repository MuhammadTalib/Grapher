#pragma once
#include "Point_Array.h"

Point_Array::Point_Array()
{
	this->total_points = 6;
	this->count=0;
	this->Array=new Point[total_points];
}

Point_Array::Point_Array(Point * ArRray, int total_points, int count)
{
	this->total_points = total_points;
	this->count = count;
	this->Array = new Point[total_points];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = ArRray[i];
	}
	
}

Point_Array::Point_Array(Point_Array & P)
{
	this->total_points =P.total_points;
	this->count = P.count;
	this->Array = new Point[total_points];
	this->Array = P.Array;
}

int Point_Array::gettotal_points()
{
	return this->total_points;
}

int Point_Array::getcount()
{
	return this->count;
}

Point Point_Array::getindexpoint(int index)
{
	
	return this->Array[index];
}

Point Point_Array::getedgepoint()
{
	return this->Array[0];
}

void Point_Array::set(Point * Array, int total_points, int count)
{
	this->total_points = total_points;
	this->count = count;
	this->Array = Array;
}

void Point_Array::settotal_points(int total_points)
{
	this->total_points = total_points;
}

void Point_Array::setcount(int count)
{
	this->count = count;
}

void Point_Array::setArray(Point * Array)
{
	this->Array = Array;
}

void Point_Array::addpoint(Point P)
{
	if (this->count < 6)
	{
		this->Array[this->count] = P;
		this->count++;
	}
	else
	{
		this->increasesize();
	}
}

void Point_Array::show()
{
	
	for (int i=0; i < this->count; i++)
	{
		this->Array[i].show();
	}
}

Point_Array Point_Array::operator=(Point_Array& P)
{
	this->total_points = P.total_points;
	this->count = P.count;
	this->Array = P.Array;
	return *this;
}


Point_Array::~Point_Array()
{
}

Point_Array Point_Array::increasesize()
{
	this->total_points = this->total_points * 2;
	Point_Array Point_Array(this->Array, this->total_points, this->count);
	*this = Point_Array;
	return *this;
	
}

ostream & operator<<(ostream & o, Point_Array & P)
{
	for (int i = 0; i < P.count; i++)
	{
		cout << endl << "Point " << i << "is" << P.Array[i]<<endl;
	}
	return o << "";
}

istream & operator>>(istream & in, Point_Array & P)
{
	int s;
	return in >> s;
}