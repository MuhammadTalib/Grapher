#pragma once
#include"Graphics.h"
#include"StraightLine.h"
class Line_Array
{
public:
	Line_Array();
	Line_Array(StraightLine *Array, int total_lines, int count);
	Line_Array(Line_Array& P);

	int gettotal_lines();
	int getcount();
	void set(StraightLine *Array, int total_lines, int count);
	void settotal_lines(int total_lines);
	void setcount(int count);
	void setArray(StraightLine *Array);
	void addline(StraightLine P);
	void show();

	friend ostream& operator <<(ostream& o, Line_Array& P);
	friend istream& operator >>(istream& in, Line_Array& P);
	Line_Array operator = (Line_Array& P);

	~Line_Array();
private:
	int total_lines = 0;
	int count;
	StraightLine *Array;
	Line_Array increasesize();

};
