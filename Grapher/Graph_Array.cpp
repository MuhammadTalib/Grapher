#include "Graph_Array.h"
#include"Polygon.h"
Graph_Array::Graph_Array()
{
	this->total_graphs = 6;
	this->count = 0;
	this->Array = new Graph[total_graphs];
}

Graph_Array::Graph_Array(Graph * Array, int total_graphs, int count)
{
	this->total_graphs = total_graphs;
	this->count = count;
	this->Array = new Graph[total_graphs];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

Graph_Array::Graph_Array(Graph_Array & P)
{
	this->total_graphs = P.total_graphs;
	this->count = P.count;
	this->Array = new Graph[total_graphs];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = P.Array[i];
	}
}

int Graph_Array::gettotal_graphs()
{
	return this->total_graphs;
}

int Graph_Array::getcount()
{
	return this->count;
}

void Graph_Array::set(Graph * Array, int total_graphs, int count)
{
	this->total_graphs = total_graphs;
	this->count = count;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

void Graph_Array::settotal_graphs(int total_graphs)
{
	this->total_graphs = total_graphs;
}

void Graph_Array::setcount(int count)
{
	this->count = count;
}

void Graph_Array::setArray(Graph * Array)
{
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

void Graph_Array::addgraph(Graph *P)
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
void Graph_Array::addgraph(Graph P)
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
void Graph_Array::show()
{
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i].show();
	}
}


Graph_Array Graph_Array::operator=(Graph_Array & P)
{
	this->total_graphs = P.total_graphs;
	this->count = P.count;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = P.Array[i];
	}
	return *this;
}

Graph_Array::~Graph_Array()
{
}

Graph_Array Graph_Array::increasesize()
{
	this->total_graphs = this->total_graphs * 2;
	Graph_Array Graph_Array(this->Array, this->total_graphs, this->count);
	*this = Graph_Array;
	return *this;
}

ostream & operator<<(ostream & o, Graph_Array & P)
{
	return o << "s";
	// TODO: insert return statement here
}

istream & operator>>(istream & in, Graph_Array & P)
{
	int s;
	return in >> s;
}
