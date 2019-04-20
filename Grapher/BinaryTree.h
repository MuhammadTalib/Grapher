#pragma once
template <class NODE> class BinaryTree {

private:

	NODE *value = NULL;
	BinaryTree *RightChild = NULL;
	BinaryTree *LeftChild = NULL;

public:

	BinaryTree* getRightChild();
	BinaryTree* getLeftChild();
	NODE* getValue();

	void InOrder();
	void PostOrder();
	void PreOrder();


	void insert(NODE* ptr);
	bool empty();
};

