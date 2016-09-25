/**
*	@file :	BST.h
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/


#ifndef BST_H
#define BST_H

#include "Node.h"

enum Order
{
    pre_order, in_order, level_order
};

class BST

{
	public:
	BST();
        void insert(int x);
        void remove(int x);
        void search(int x);
        void preOrder();
        void inOrder();
	

	private:
        Node* root;
        void insertHelper(int x, Node* subtree);
        void preOrderHelper(Node* subtree);
        void inOrderHelper(Node* subtree);
	void remove(Node* n);
        Node* search(int x, Node* subtree);


};

#endif
