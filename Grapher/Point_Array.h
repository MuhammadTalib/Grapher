#pragma once
#include"Graphics.h"
#include"Point.h"
class Point_Array
{
public:
	Point_Array();
	Point_Array(Point *Array,int total_points,int count);
	Point_Array(Point_Array& P);

	int gettotal_points();
	int getcount();
	Point getindexpoint(int index);
	Point getedgepoint();
	void set(Point *Array, int total_points, int count);
	void settotal_points(int total_points);
	void setcount(int count);
	void setArray(Point *Array);
	void addpoint(Point P, Point Q, Point R, Point S);
	void addpoint(Point P);
	void show(Point *Centre);
	void showCircledPoints(Point* Centre);
    void save(ofstream& o,string filename);
	void deletePointArray();
	void deletePoint(int j);

	friend ostream& operator <<(ostream& o, Point_Array& P);
	friend istream& operator >>(istream& in, Point_Array& P);
	Point_Array operator = (Point_Array& P);
	Point_Array operator += (int add);

	~Point_Array();
private:
	int total_points=0;
	int count;
	Point *Array;
	Point_Array increasesize();

};


