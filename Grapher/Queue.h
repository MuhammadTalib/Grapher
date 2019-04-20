#pragma once
template <class NODE> class Queue {

private:

	NODE *value = NULL;
	Queue *Next = NULL;


public:

	Queue* getNext();
	NODE* getValue();

	NODE* deQueue();
	void enQueue(NODE* ptr);
	
	bool empty();
};

