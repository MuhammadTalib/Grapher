#pragma once
#include<iostream>
using namespace std;
#include"AVLTree.h"

template<class NODE>
NODE* AVLTree<NODE>::getFirstNode() //means the least node
{
	AVLTree<NODE> *CURR = this;
	while (CURR->LeftChild != NULL)
	{
		CURR = CURR->LeftChild;
	}
	return CURR->value;
}

template<class NODE>
NODE* AVLTree<NODE>::getLastNode()
{
	AVLTree<NODE> *CURR =this;
	while (CURR->RightChild != NULL)
	{
		CURR = CURR->RightChild;
	}
	return CURR->value;
}


template<class NODE> void AVLTree<NODE>::insert(NODE* data)
{
	AVLTree<NODE> *ptr = new AVLTree<NODE>;
	ptr->value = data;
	ptr->LeftChild = NULL;
	ptr->RightChild = NULL;
	if (this->value == NULL)
	{
		this->value = data;
		this->LeftChild = NULL;
		this->RightChild = NULL;
		this->height = 0;
	}
	else
	{
		AVLTree<NODE> *CURR = this;
		while (CURR != NULL && CURR->value!=NULL)
		{
			if (*(ptr->value) >= *(CURR->value))
			{
				if (CURR->RightChild == NULL)
				{
					CURR->RightChild = new AVLTree<NODE>;
					CURR->RightChild->value = data;
					CURR->RightChild->RightChild = NULL;
					CURR->RightChild->RightChild = NULL;
					CURR->RightChild->height = 0;

					break;
				}
				else if (CURR->RightChild != NULL)
				{
					CURR = CURR->RightChild;
				}
			}
			else if (*(ptr->value) < *(CURR->value))
			{
				if (CURR->LeftChild == NULL)
				{
					CURR->LeftChild = ptr;
					CURR->LeftChild->height = 0;

					break;
				}
				else if (CURR->LeftChild != NULL)
				{
					CURR = CURR->LeftChild;
				}
			}
		}
		if(CURR!=NULL)
		{
		
		}
		else
		while (1)
		{
			if ((CURR->RightChild)->getheight() > CURR->LeftChild->getheight())
			{
				CURR->height = (CURR->RightChild->height) + 1;

				if ((abs(CURR->LeftChild->getheight() - CURR->RightChild->getheight())) > 1)
				{
					if (CURR->RightChild->LeftChild->getheight() > CURR->RightChild->RightChild->getheight())
					{
						AVLTree<NODE> *nodeparent = this->findparent( CURR->RightChild);
						(CURR->RightChild)->ShiftRight();
					}
					if (CURR->RightChild->getheight() > CURR->LeftChild->getheight())
					{

						if (CURR == this)
						{
							this->shiftleft();
							CURR = (this);
						}
						else
						{
							AVLTree<NODE> *nodeparent = this->findparent( CURR);
							if(nodeparent->LeftChild!=NULL)
							if (*(CURR->value) == *(nodeparent->LeftChild->value))
							{
								CURR->shiftleft();
								nodeparent->LeftChild = CURR;
							}
							else if (CURR->value == nodeparent->RightChild->value)
							{
								CURR->shiftleft();
								nodeparent->RightChild = CURR;
							}
							break;
						}
					}
				}
				if (CURR != this)
				{
					CURR = this->findparent(CURR);
				}
				else
				{
					break;
				}
			}
			else
			{
				CURR->height = (CURR->LeftChild->height) + 1;

				if ((abs(CURR->LeftChild->getheight() - CURR->RightChild->getheight())) > 1)
				{
		
					if (CURR->LeftChild->RightChild->getheight() > CURR->LeftChild->LeftChild->getheight())
					{
						(CURR->LeftChild)->shiftleft();
					}
					if (CURR->RightChild->getheight() < CURR->LeftChild->getheight())
					{
						if (CURR == this)
						{
							CURR->ShiftRight();
							CURR->InOrder();
						}
						else
						{
							AVLTree<NODE> *nodeparent = this->findparent( CURR);
							if(nodeparent->LeftChild!=NULL)
							if (CURR->value == nodeparent->LeftChild->value)
							{
								CURR->ShiftRight();
								nodeparent->LeftChild = CURR;
							}
							else if (CURR->value == nodeparent->RightChild->value)
							{
								CURR->ShiftRight();
								nodeparent->RightChild = CURR;
							}
							break;
						}
					}
				}
				if (CURR != this)
				{
					CURR = this->findparent(CURR);
				}
				else
				{
					break;
				}
			}
		}
	}
}
template<class NODE>
void AVLTree<NODE>::show(NODE *Centre)
{
	if (this != NULL && this->value != NULL )
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->show(Centre);
		}
		(*(this->value)).show(Centre);
		this->RightChild->show(Centre);
	}
}
template<class NODE>
void AVLTree<NODE>::showWithCircle(NODE * Centre)
{
	if (this != NULL && this->value != NULL)
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->showWithCircle(Centre);
		}
		(*(this->value)).showCircledPoint(Centre);
		this->RightChild->showWithCircle(Centre);
	}
}
template<class NODE>
void AVLTree<NODE>::show()
{
	if (this != NULL)
	{
		if (this->LeftChild != NULL)
		{
			this->LeftChild->show();
		}
		(*(this->value)).show();
		this->RightChild->show();
	}
}
template<class NODE>
NODE * AVLTree<NODE>::getValue()
{
	return this->value;
}
template<class NODE>
AVLTree<NODE>* AVLTree<NODE>::getRightChild()
{
	return this->RightChild;
}
template<class NODE>
AVLTree<NODE>* AVLTree<NODE>::getLeftChild()
{
	return this->LeftChild;
}
template<class NODE>
void AVLTree<NODE>::deleteTree()
{
	AVLTree<NODE> *CURR = this;
	this->value = NULL;
	this->RightChild = NULL;
	this->LeftChild = NULL;
	free(CURR);
}
template<class NODE>
void AVLTree<NODE>::deleteNode(NODE * ptr)
{
	AVLTree<NODE> *CURR = this, *parent = new AVLTree<NODE>;

	while (CURR != NULL && CURR->value != NULL)
	{
		if (ptr < CURR->value)
		{
			parent = CURR;
			CURR = CURR->LeftChild;
		}
		else if (ptr > CURR->value)
		{
			parent = CURR;
			CURR = CURR->RightChild;
		}
		if (CURR->value == ptr)
		{
			break;
		}

	}
	if (CURR->RightChild == NULL && CURR->LeftChild == NULL)
	{
		if (CURR == this)
		{
			this->value = NULL;
		}
		else if (CURR == parent->LeftChild)
		{
			parent->LeftChild = NULL;
			free(CURR);
		}
		else if (CURR == parent->RightChild)
		{
			parent->RightChild = NULL;
			free(CURR);
		}
	}
	else if (CURR->RightChild == NULL && CURR->LeftChild != NULL)
	{
		if (CURR == this)
		{
			this->value = CURR->LeftChild->value;
			this->RightChild = CURR->LeftChild->RightChild;
			this->LeftChild = CURR->LeftChild->LeftChild;
		}
		else if (CURR == parent->LeftChild)
		{
			parent->LeftChild = CURR->LeftChild;
			free(CURR);
		}
		else if (CURR == parent->RightChild)
		{
			parent->RightChild = CURR->LeftChild;
			free(CURR);
		}
	}
	else if (CURR->RightChild != NULL && CURR->LeftChild == NULL)
	{
		if (CURR->value == this->value)
		{
			this->value = CURR->RightChild->value;
			this->RightChild = CURR->RightChild->RightChild;
			this->LeftChild = CURR->RightChild->LeftChild;
		}
		else if (CURR->value == parent->LeftChild->value)
		{
			parent->LeftChild = CURR->RightChild;
			free(CURR);
		}
		else if (CURR->value == parent->RightChild->value)
		{
			parent->RightChild = CURR->RightChild;
			free(CURR);
		}
	}
	else if (CURR->RightChild != NULL && CURR->LeftChild != NULL)
	{
		AVLTree<NODE> *Max = FindMax(CURR->RightChild);
		if (CURR == parent->LeftChild)
		{
			Max->RightChild->LeftChild = CURR->LeftChild;
			Max->RightChild->RightChild = CURR->RightChild;
			parent->LeftChild = Max->RightChild;
			Max->RightChild = NULL;
			free(CURR);
		}
		if (CURR == parent->RightChild)
		{
			Max->RightChild->LeftChild = CURR->LeftChild;
			Max->RightChild->RightChild = CURR->RightChild;
			parent->RightChild = Max->RightChild;
			Max->RightChild = NULL;
			free(CURR);
		}
	}
}
template<class NODE>
AVLTree<NODE>* AVLTree<NODE>::FindParent(AVLTree<NODE>* child)
{
	if (this->LeftChild->value == child->value || this->RightChild->value == child->value)
	{
		return this;
	}
	if (this->value > child->value)
	{
		this->LeftChild->FindParent( child);
	}
	if (this->value < child->value)
	{
		this->RightChild->FindParent( child);
	}
}
template<class NODE>
AVLTree<NODE>* AVLTree<NODE>::FindMax()
{
	if (this->RightChild->RightChild == NULL)
	{
		return this;
	}
	else if (this->RightChild != NULL)
	{
		this->RightChild->FindMax();
	}
}
template<class NODE>
int AVLTree<NODE>::getheight()
{
	if (this == NULL)
	{
		return -1;
	}
	else
	{
		return this->height;
	}
}
template<class NODE>
int AVLTree<NODE>::abs(int a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}
template<class NODE>
void AVLTree<NODE>::shiftleft()
{
	AVLTree<NODE> *CURR = new AVLTree<NODE>;

	CURR->value = this->value;
	CURR->height = (this->RightChild->height) - 1;
	CURR->LeftChild = this->LeftChild;
	CURR->RightChild = this->RightChild->LeftChild;

	this->RightChild->LeftChild = CURR;
	this->value = this->RightChild->value;
	this->LeftChild = CURR;
	this->RightChild = this->RightChild->RightChild;
	
}
template<class NODE>
void AVLTree<NODE>::ShiftRight()
{
	AVLTree<NODE> *CURR = new AVLTree<NODE>;


	CURR->value = this->value;
	CURR->height = (this->LeftChild->height) - 1;
	CURR->LeftChild = (this)->LeftChild->RightChild;
	CURR->RightChild = this->RightChild;
	
	this->LeftChild->RightChild = CURR;
	this->value = this->LeftChild->value;
	this->LeftChild = this->LeftChild->LeftChild;
	this->RightChild = CURR;
	
}
template<class NODE>
AVLTree<NODE>* AVLTree<NODE>::findparent(AVLTree<NODE>* CURR)
{
	if (this->RightChild != NULL && (*(this->RightChild->value) == *(CURR->value)))
	{
		return this;
	}
	if (this->LeftChild != NULL && (*(this->LeftChild->value) == *(CURR->value)))
	{
		return this;
	}

	else if (*(CURR->value) > *(this->value))
	{
		this->RightChild->findparent(CURR);
	}
	else if (*(CURR->value) < *(this->value))
	{
		this->LeftChild->findparent(CURR);
	}
	
}
template<class NODE>
void AVLTree<NODE>::InOrder()
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
void AVLTree<NODE>::PostOrder()
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
void AVLTree<NODE>::PreOrder()
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

