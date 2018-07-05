#pragma once
#include"Graphics.h"
#include"Shape.h"
#include"Polygon.h"
class Shape_Array
{
public:
	Shape_Array();
	Shape_Array(Shape *Array, int total_graphs, int count);
	Shape_Array(Shape_Array& P);

	int gettotal_graphs();
	int getcount();
	Shape getGraphfromindex(int index);
	void set(Shape *Array, int total_graphs, int count);
	void settotal_graphs(int total_graphs);
	void setcount(int count);
	void setArray(Shape *Array);
	Shape_Array getArray();
	void addgraph(Shape P);
	void addgraph(Shape *P);
	void show();
	void save(string filename);
	void deleteShapeArray(int i);
	void deleteShapeArray();
	void deleteLine(int i);
	void deletePoint(int i);
	

	friend ostream& operator <<(ostream& o, Shape_Array& P);
	friend istream& operator >>(istream& in, Shape_Array& P);
	Shape_Array operator = (Shape_Array P);
	Shape_Array operator+=(int add);

	~Shape_Array();

private:

	int total_graphs = 0;
	int count;
	Shape *Array;
	Shape_Array increasesize();
};
