#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List

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