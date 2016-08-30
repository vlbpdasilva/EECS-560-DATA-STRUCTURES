/**
*	@file : Node.h
*	@author :  Victor Berger da Silva
*	@date : Aug 26 2016
*	Purpose: header file for Node class
	Single Linked List --- EECS 560 -- prof. Kong/TA: Hajiarbabi
*/

#ifndef NODE_H
#define NODE_H
 
class Node   // specific documentation for Node class on Node.cpp
{
	public:

	Node();	
	void setValue(int val);	
	void setNext(Node* next);	
	int getValue();	
	Node* getNext();

        
        private:
	
	int m_value;	
	Node* m_next;
        Node* m_prev;
	

};


#endif
