#pragma once
#include"Graphics.h"
#include"Graph.h"
#include"Polygon.h"
class Graph_Array
{
public:
	Graph_Array();
	Graph_Array(Graph *Array, int total_graphs, int count);
	Graph_Array(Graph_Array& P);

	int gettotal_graphs();
	int getcount();
	void set(Graph *Array, int total_graphs, int count);
	void settotal_graphs(int total_graphs);
	void setcount(int count);
	void setArray(Graph *Array);
	void addgraph(Graph P);
	void addgraph(Graph *P);
	void show();

	friend ostream& operator <<(ostream& o, Graph_Array& P);
	friend istream& operator >>(istream& in, Graph_Array& P);
	Graph_Array operator = (Graph_Array& P);

	~Graph_Array();

private:

	int total_graphs = 0;
	int count;
	Graph *Array;
	Graph_Array increasesize();
};
