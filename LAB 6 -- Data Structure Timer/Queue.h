/**
*	@file : Queue.h
*	@author :  Victor Berger da Silva
*	@date : Oct 17 2016
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue

{
	public:

	Queue();
	~Queue();
	void add (Node* n);
	void pop (Node* n);
        void print();
        Node* pop();
        bool isEmpty();

	private:

	Node* m_back;
	Node* m_front;


};

#endif
