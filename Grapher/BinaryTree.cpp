#pragma once
#include<iostream>
#include"BinaryTree.h"
using namespace std;
template<class NODE> BinaryTree<NODE> * BinaryTree<NODE>::getRightChild()
{
	return this->RightChild;
}

template<class NODE> BinaryTree<NODE> * BinaryTree<NODE>::getLeftChild()
{
	return this->LeftChild;
}

template<class NODE> NODE * BinaryTree<NODE>::getValue()
{
	if(this!=NULL)
	return this->value;
}

template<class NODE>
void BinaryTree<NODE>::InOrder()
{
	if (this != NULL)
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->InOrder();
		}
		cout << *(this->value) << endl;
		this->RightChild->InOrder();
	}
}

template<class NODE>
void BinaryTree<NODE>::PostOrder()
{
	if (this != NULL)
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->PostOrder();
		}
		this->RightChild->PostOrder();
		cout << *(this->value) << endl;
	}
}

template<class NODE>
void BinaryTree<NODE>::PreOrder()
{
	if (this != NULL)
	{
		cout << *(this->value) << endl;
		if (this->LeftChild != NULL)
		{
			this->LeftChild->PreOrder();
		}
		this->RightChild->PreOrder();
	}
}

template<class NODE> void BinaryTree<NODE>::insert(NODE * ptr)
{
	BinaryTree<NODE> *ptr1 = new BinaryTree<NODE>;
	ptr1->value = ptr;
	ptr1->LeftChild = NULL;
	ptr1->RightChild = NULL;

	if (this->value == NULL)
	{
		this->value = ptr;
		this->LeftChild = NULL;
		this->RightChild = NULL;
	}
	else
	{
		BinaryTree<NODE> *CURR = this;
		while (CURR != NULL)
		{
			if (*(ptr1->value) >= *(CURR->value))
			{
		
				if (CURR->RightChild == NULL)
				{
					CURR->RightChild = ptr1;
					break;
				}
				else if (CURR->RightChild != NULL)
				{
					CURR = CURR->RightChild;
				}
			}
			else if (*(ptr1->value) < *(CURR->value))
			{
	
				if (CURR->LeftChild == NULL)
				{
					CURR->LeftChild = ptr1;
					break;
				}
				else if (CURR->LeftChild != NULL)
				{
					CURR = CURR->LeftChild;
				}
			}


		}
	}
}

template<class NODE> bool BinaryTree<NODE>::empty()
{
	return false;
}
