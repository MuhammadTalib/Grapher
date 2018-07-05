#include "Shape_Array.h"
#include"Polygon.h"
#include<fstream>
Shape_Array::Shape_Array()
{
	this->total_graphs = 6;
	this->count = 0;
	this->Array = new Shape[total_graphs];
}

Shape_Array::Shape_Array(Shape * Array, int total_graphs, int count)
{
	this->total_graphs = total_graphs;
	this->count = count;
	this->Array = new Shape[total_graphs];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

Shape_Array::Shape_Array(Shape_Array & P)
{
	this->total_graphs = P.total_graphs;
	this->count = P.count;
	this->Array = new Shape[total_graphs];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = P.Array[i];
	}
}

int Shape_Array::gettotal_graphs()
{
	return this->total_graphs;
}

int Shape_Array::getcount()
{
	return this->count;
}

Shape Shape_Array::getGraphfromindex(int index)
{
	return this->Array[index];
}

void Shape_Array::set(Shape * Array, int total_graphs, int count)
{
	this->total_graphs = total_graphs;
	this->count = count;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

void Shape_Array::settotal_graphs(int total_graphs)
{
	this->total_graphs = total_graphs;
}

void Shape_Array::setcount(int count)
{
	this->count = count;
}

void Shape_Array::setArray(Shape * Array)
{
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

Shape_Array Shape_Array::getArray()
{
	return *this;
}

void Shape_Array::addgraph(Shape *P)
{
	if (this->count < 6)
	{
		this->Array[this->count] = *P;
		this->count++;
	}
	else
	{
		this->increasesize();
	}
}
void Shape_Array::addgraph(Shape P)
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
void Shape_Array::show()
{
	Graphics G;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i].show();
	}
}

void Shape_Array::save(string filename)
{
	ofstream o(filename, ios::binary);
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i].save(o, filename);
	}
	o.close();
}


Shape_Array Shape_Array::operator=(Shape_Array P)
{
	this->total_graphs = P.total_graphs;
	this->count = P.count;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = P.Array[i];
	}
	return *this;
}

Shape_Array Shape_Array::operator+=(int add)
{
	for (int i=0; i < this->count; i++)
	{
		this->Array[i] += add;
	}
	return *this;
}

Shape_Array::~Shape_Array()
{
	delete[]Array;
}

Shape_Array Shape_Array::increasesize()
{
	this->total_graphs = this->total_graphs * 2;
	Shape_Array Graph_Array(this->Array, this->total_graphs, this->count);
	return Graph_Array;
}

ostream & operator<<(ostream & o, Shape_Array & P)
{
	return o << "s";
	// TODO: insert return statement here
}

istream & operator>>(istream & in, Shape_Array & P)
{
	int s;
	return in >> s;
}
void Shape_Array::deleteShapeArray()
{
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i].deleteShape();
	}
}
void Shape_Array::deleteLine(int i)
{
	int j;
	cout << "Which Line"<<endl;
	cin >> j;
	this->Array[i].deleteLine(j);
}
void Shape_Array::deletePoint(int i)
{
	int j;
	cout << "Which Point" << endl;
	cin >> j;
	this->Array[i].deletePoint(j);
}
void Shape_Array::deleteShapeArray(int i)
{
	this->Array[i].deleteShape();
}
