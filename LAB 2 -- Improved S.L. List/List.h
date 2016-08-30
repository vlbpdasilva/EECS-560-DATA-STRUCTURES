/**
*	@file : List.h
*	@author :  Victor Berger da Silva
*	@date : Aug 26 2016
*	Purpose: header file for List class
	Single Linked List --- EECS 560 -- prof. Kong/TA: Hajiarbabi
*/


#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List      // specific documentation for List class on List.cpp

{
	public:
	
	List();
	~List();	
	void insert(int n);
	void print();
	Node* search(int f);
        bool erase(int f);
	void memdelete();
        Node* reverseHelper(Node* node);
        void reverse();
        void concatenate(List* l);
        Node* concatenateHelper(Node* n);
        void insertNode(Node* n);

	private:
	
	Node* m_back;	
	Node* m_front;	
	bool isEmpty;

};

#endif
