#ifndef NODE_H
#define NODE_H

class Node
{
	public:

	Node();
	
	void setValue(int val);
	
	void setNext(Node* next);
	
	int getValue();
	
	Node* getNext();
	
	int m_value;
	
	Node* m_next;
	

};


#endif