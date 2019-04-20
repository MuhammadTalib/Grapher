#pragma once
#include<iostream>
using namespace std;
#include"Stack.h"

template <class NODE> Stack<NODE>* Stack<NODE>::getNext()
{
	return this->Next;
}
template<class NODE> NODE* Stack<NODE>::getValue()
{
	if(this!=NULL)
		return this->value;
}

template <class NODE> void Stack<NODE>::push(NODE* ptr)
{
	Stack *ptr1 = new Stack<NODE>;
	ptr1->value = ptr;
	ptr1->Next = NULL;

	if (this->value == NULL)
	{
		this->value = ptr1->value;
		this->Next = ptr1->Next;
	}
	else
	{
		if (this != NULL)
		{
			ptr1->Next = new Stack<NODE>;
			ptr1->Next->value = this->value;
			ptr1->Next->Next = this->Next;
		}
		else
		{
			ptr1->Next = NULL;
		}
		this->value = ptr1->value;
		this->Next = ptr1->Next;
	}
}
template<class NODE>
bool Stack<NODE>::empty()
{
	if(this->value==00)
		return 1;
	else
		return 0;
}
template <class NODE> NODE* Stack<NODE>::pop()
{
	if (this != NULL)
	{
		NODE* CURR = this->value;
		Stack *hold = this, *toDelete = this->Next;

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
