#pragma once
#include<iostream>
using namespace std;
#include"Queue.h"

template <class NODE> Queue<NODE>* Queue<NODE>::getNext()
{
	return this->Next;
}
template<class NODE> NODE* Queue<NODE>::getValue()
{
	if (this != NULL)
		return this->value;
}

template <class NODE> void Queue<NODE>::enQueue(NODE* ptr)
{
	if (this->value == NULL)
	{
		this->value = ptr;
		this->Next = NULL;
	}
	else
	{
		Queue<NODE> *ptr1 = new Queue<NODE>;
		ptr1->value = ptr;
		ptr1->Next = NULL;

		Queue<NODE> *CURR = this;
		while (CURR->Next != NULL)
		{
			CURR = CURR->Next;
		}
		CURR->Next = ptr1;
	}
}
template<class NODE>
bool Queue<NODE>::empty()
{
	if (this->value == 00)
		return 1;
	else
		return 0;
}
template <class NODE> NODE* Queue<NODE>::deQueue()
{
	if (this != NULL)
	{
		NODE* CURR = this->value;
		Queue<NODE> *hold = this, *toDelete = this->Next;

		if (this->Next != NULL)
		{
			hold->value = this->Next->value;
			hold->Next = this->Next->Next;
		}
		else
		{
			this->value = NULL;
		}

		free(toDelete);
		return CURR;
	}
	else
	{
		return 0;
	}
}
