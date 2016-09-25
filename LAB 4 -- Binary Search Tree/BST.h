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
        void insert(int x);
        void remove(int x);
        void search(int x);
        void preOrder();
        void inOrder();
        void levelOrder();
	

	private:
        Node* root;
        void insertHelper(int x, Node* subtree);
        void preOrderHelper(Node* subtree);
        void inOrderHelper(Node* subtree);
        void levelOrderHelper(Node* subtree);
	void remove(Node* n);
        Node* search(int x, Node* subtree);


};

#endif
