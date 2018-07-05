#pragma once
#include "Shape_Array.h"
#include"Coordinate_System.h"
class Grapher {
public:
	Grapher();
	~Grapher();
	void deleteGrapher();
	
private:
	void UserInput();
	void FileInput();
	Shape_Array ShapeArray;
	Coordinate_System Graph_Sheet;
	Line_Array BorderLines;
protected:
};