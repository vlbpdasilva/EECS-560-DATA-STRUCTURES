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
	bool search(int f);
	void memdelete();
	
	private:
	
	Node* m_back;	
	Node* m_front;	
	bool isEmpty;

};

#endif
