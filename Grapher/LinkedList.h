#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class NODE> class LinkedList {

private:

	


public:
	NODE *value = NULL;
	LinkedList *Next = NULL;

	void AddNode(NODE*  ptr);
	LinkedList* getNext();
	NODE* getValue();
	void display();

	bool empty() const {
		return value.empty();
	}
};
