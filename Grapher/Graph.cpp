#include"Graph.h"
#include<iostream>
using namespace std;
Graph::Graph()
{
	this->total=6;
	this->count=0;
	
}
void Graph::work()
{
	char status = 'y';
	Point P;
	Point Q;
	Point R(36, 54);
	Point S(35, 35);
	int i = 1;
	cout << "|                        Enter Point";
	cout << " " << i << "                         |" << endl;
	i++;
	cin >> P;
	this->Points_Array.addpoint(P);
	do
	{
		cout << "|                        Enter Point " << i << "                         |";
		i++;
		cin >> Q;
		this->Points_Array.addpoint(Q);
		StraightLine S(P, Q);
		this->Line_Array.addline(S);
		P = Q;

		cout << "|                  1:Enter More Points(Y/N)";
		cin >> status;
		cout << "|**************************************************************|" << endl;

	} while (status == 'y' || status == 'Y');
	cout << this->Points_Array;
	
}
void Graph::show()
{
	cout << "dede";
	this->Points_Array.show();
	this->Line_Array.show();
}


Point Graph::getpointfromPoint_Array(int x)
{
	Point P;
	P =this->Points_Array.getindexpoint(x);
	return P;

}
