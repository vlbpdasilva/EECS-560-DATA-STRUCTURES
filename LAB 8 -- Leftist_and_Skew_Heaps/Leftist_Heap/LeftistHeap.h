/**
*	@file :	LeftistHeap.h
*	@author :  Victor Berger da Silva
*	@date :	Nov 06 2016
*
*/


#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "Node.h"

class LeftistHeap

{
	public:
	LeftistHeap();
        ~LeftistHeap();
	void insert(int x);
	void deleteMin();
	void levelOrder();
	void preOrder();
	void inOrder();

	private:
        Node* merge(Node* leftHeap, Node* rightHeap);
        void deleteHelper(Node* n);
        void preOrderHelper(Node* n);
        void inOrderHelper(Node* n);
        void levelOrderHelper(Node* n);

        Node* m_root;

};

#endif
