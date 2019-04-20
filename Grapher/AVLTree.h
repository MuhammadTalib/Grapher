#pragma once
#include"BinaryTree.h"
template <class NODE> class AVLTree
{
public:

	NODE* getFirstNode();
	NODE* getLastNode();

	void insert(NODE *data);
	void show(NODE *Centre);
	void showWithCircle(NODE *Centre);
	void show();
	NODE* getValue();
	AVLTree<NODE> * getRightChild();
	AVLTree<NODE> * getLeftChild();
	void deleteTree();
	void deleteNode(NODE *ptr);

	AVLTree<NODE>* FindParent(AVLTree<NODE>* child);
	AVLTree<NODE>* FindMax();

	void InOrder();
	void PostOrder();
	void PreOrder();
	
private:
	int height;
	AVLTree *RightChild = NULL;
	AVLTree *LeftChild = NULL;
	NODE *value = NULL;

	int getheight();
	int abs(int a);
	void shiftleft();
	void ShiftRight();
	AVLTree<NODE>* findparent(AVLTree<NODE> *CURR);

};