/**
*	@file :	Node.h
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/


#ifndef NODE_H
#define NODE_H


class Node

{
	public:
        Node();
        void setValue (int i);
        int getValue();
        void setLeft(Node* left);
        Node* getLeft();
        void setRight(Node* right);
        Node* getRight();

	private:
        int m_value;
        Node* m_left;
        Node* m_right;
	

};

#endif
