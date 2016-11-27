/**
*	@file :	Node.h
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/


#ifndef NODE_H
#define NODE_H

template <typename T>
class Node

{
	public:
        Node();
        void setValue(int i);
        int getValue();
        void setLeft(Node<T>* left);
        Node<T>* getLeft();
        void setRight(Node<T>* right);
        Node<T>* getRight();
        void setRank(int r);
        int getRank();


	private:
        int m_value;
        Node<T>* m_left;
        Node<T>* m_right;        
        int m_rank; // FOR LEFTIST HEAP

};

#endif
