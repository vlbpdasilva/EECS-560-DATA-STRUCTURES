/**
*	@file :	BST.h
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/


#ifndef BST_H
#define BST_H

#include "Node.h"

class BST

{
	public:
	BST();
        ~BST();
        void memdelete(Node* n);
        void insert(int x);
        Node* search(int x);
        Node* getMin(Node* n);
        Node* getMax(Node* n);
        int getMinValue();
        int getMaxValue();
        void preOrder();
        void inOrder();
        void levelOrder();
        void remove(int a);
        void deleteMin();
        void deleteMax();


	private:
        Node* root;
        void insertHelper(int x, Node* subtree);
        void preOrderHelper(Node* subtree);
        void inOrderHelper(Node* subtree);
        void levelOrderHelper(Node* subtree);
        Node* search(int x, Node* subtree);
        Node* removeHelper(int a, Node* n);


};

#endif
