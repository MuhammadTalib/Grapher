#include "Line_Array.h"


Line_Array::Line_Array()
{
	this->total_lines = 6;
	this->count = 0;
	this->Array = new StraightLine[total_lines];
}

Line_Array::Line_Array(StraightLine * Array, int total_lines, int count)
{
	this->total_lines = total_lines;
	this->count = count;
	this->Array = new StraightLine[total_lines];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

Line_Array::Line_Array(Line_Array & P)
{
	this->total_lines =P.total_lines;
	this->count = P.count;
	this->Array = new StraightLine[total_lines];
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] =P.Array[i];
	}
}

int Line_Array::gettotal_lines()
{
	return this->total_lines;
}

int Line_Array::getcount()
{
	return this->count;
}

void Line_Array::set(StraightLine * Array, int total_lines, int count)
{
	this->total_lines = total_lines;
	this->count = count;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

void Line_Array::settotal_lines(int total_lines)
{
	this->total_lines = total_lines;
}

void Line_Array::setcount(int count)
{
	this->count = count;
}

void Line_Array::setArray(StraightLine * Array)
{
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = Array[i];
	}
}

void Line_Array::addline(StraightLine P)
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

void Line_Array::show()
{
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i].show();
	}
}


Line_Array Line_Array::operator=(Line_Array & P)
{
	this->total_lines = P.total_lines;
	this->count = P.count;
	for (int i = 0; i < this->count; i++)
	{
		this->Array[i] = P.Array[i];
	}
	return *this;
}

Line_Array::~Line_Array()
{
}

Line_Array Line_Array::increasesize()
{
	this->total_lines = this->total_lines * 2;
	Line_Array Line_Array(this->Array, this->total_lines, this->count);
	*this = Line_Array;
	return *this;
}

ostream & operator<<(ostream & o, Line_Array & P)
{
	return o << "s";
	// TODO: insert return statement here
}

istream & operator>>(istream & in, Line_Array & P)
{
	int s;
	return in >> s;
}