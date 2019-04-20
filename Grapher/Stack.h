#pragma once
template <class NODE> class Stack {

private:

	


public:
	NODE *value = NULL;
	Stack *Next = NULL;

	Stack* getNext();
	NODE* getValue();
	NODE* pop();
	void push(NODE* ptr);
	bool empty();
};

