/**
*	@file : BST.cpp
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "BST.h"
#include "Node.h"
#include <iostream>
using namespace std;

BST::BST()
{
    this->root = nullptr;    
}

void BST::insert(int x)
{
    insertHelper(x, root);
}

void BST::insertHelper(int x, Node* subtree)
{
    
    if(!root)
    {
       root = new Node();
       root->setValue(x);
    }
    else if (x < subtree->getValue())
    {
        if(subtree->getLeft())
            insertHelper(x, subtree->getLeft());
        else
        {
            Node* newNode = new Node();
            newNode->setValue(x);
            subtree->setLeft(newNode);
        }
    }
    else
    {
        if(subtree->getRight())
            insertHelper(x, subtree->getRight());
        else
        {
            Node* newNode = new Node();
            newNode->setValue(x);
            subtree->setRight(newNode);
        }
    }         
}

void BST::search(int x)
{
    search(x, root);
}

Node* BST::search(int x, Node* subtree)
{
    if(!subtree)
    {
        cout << x <<" was not found on BST.\n";
        return nullptr;
    }
    
    else
    {
        if(x == root->getValue())
        {
            cout << x << " was found.\n";
            return root;
        }
        else if(x < subtree->getValue())
            search(x, subtree->getLeft());
        else if(x > subtree->getValue())
            search(x, subtree->getRight());
        else
        {
            cout << x << " was found.\n";
            return subtree;
        }
    }
}

void BST::preOrder()
{
    preOrderHelper(root);
}

void BST::preOrderHelper(Node* subtree)
{
    
    if(!subtree)
        return;
    
    std::cout<< subtree->getValue() << " " ; 
    preOrderHelper(subtree->getLeft());
    preOrderHelper(subtree->getRight()); 
}

void BST::inOrder()
{
    inOrderHelper(root);
}

void BST::inOrderHelper(Node* subtree)
{
    if(!subtree)
        return;
    
    inOrderHelper(subtree->getLeft());
    std::cout<< subtree->getValue() << " " ; 
    inOrderHelper(subtree->getRight()); 
}

    
