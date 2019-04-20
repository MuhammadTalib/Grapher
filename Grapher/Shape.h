#pragma once
#include"DeclareSTL.h"
#include"Point.h"
#include"Point_Array.h"
#include"StraightLine.h"
#include"Line_Array.h"
class Shape {
public:
	Shape();
	Shape(Shape& P);

	void setPointinPointTree(Point *P);
	void setLineinLineArray(StraightLine *S);
	virtual void work(Point &Centre);
	virtual void show(Point *Centre);
	virtual void setline(StraightLine &L);
	//virtual void save(ofstream& o, string filename);
	//Point getpoint(int index);
	AVLTree<Point>* getpointsTree();
	AVLTree<StraightLine>* getLinesTree();
	void deleteShape();
	//void deleteLine(int j);
	//void deletePoint(int j);

	Shape& operator = (Shape& P);
	Shape operator +=(int add);

private:
	int total;
	int count;
	
protected:
	AVLTree<Point> *PointsTree=new AVLTree<Point>;
	AVLTree<StraightLine> *LinesTree = new AVLTree<StraightLine>;
};
