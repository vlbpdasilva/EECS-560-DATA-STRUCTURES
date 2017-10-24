/**
*	@file :	Node.h
*	@author :  Victor Berger da Silva
*	@date :	Nov 06 2016
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
        void setRank(int r);
        int getRank();

        //FOR THE QUEUE:
        void setNext(Node* n);
        Node* getNext();

	private:
        int m_value;
        Node* m_left;
        Node* m_right;

        int m_rank; // FOR LEFTIST HEAP
        Node* next; // FOR THE QUEUE

};

#endif
