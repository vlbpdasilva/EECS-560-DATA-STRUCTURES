/**
*	@file : Queue.h
*	@author :  Victor Berger da Silva
*	@date : 
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
        Node* pop();
        bool isEmpty();
	
	private:
	
	Node* m_back;	
	Node* m_front;	


};

#endif
