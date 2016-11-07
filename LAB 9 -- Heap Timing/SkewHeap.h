/**
*	@file :	 SkewHeap.h
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/

#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include "Node.h"

class SkewHeap

{
	public:
	SkewHeap();
        ~SkewHeap();
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
