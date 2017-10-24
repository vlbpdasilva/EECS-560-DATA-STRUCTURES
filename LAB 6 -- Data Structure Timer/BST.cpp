/**
*	@file : BST.cpp
*	@author :  Victor Berger da Silva
*	@date : Oct 17 2016
*
*/

#include "BST.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
using namespace std;

BST::BST()
{
    this->root = nullptr;
}

BST::~BST()
{
    memdelete(root);
}

void BST::memdelete(Node* n)
{
        if(!n)
        return;

    if(n->getRight()) memdelete(n->getRight());
    if(n->getLeft()) (n->getLeft());
    delete n;

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

Node* BST::search(int x)
{
    search(x, root);
}

Node* BST::search(int x, Node* subtree)
{
    if(!subtree)
        return nullptr;

    else
    {
        if(x == root->getValue())
            return root;
        else if(x < subtree->getValue())
            search(x, subtree->getLeft());
        else if(x > subtree->getValue())
            search(x, subtree->getRight());
        else
            return subtree;
    }
}

Node* BST::getMin(Node* n)
{

    while(n->getLeft())
        n = n->getLeft();
    return n;
}

int BST::getMinValue()
{
    return(getMin(root)->getValue());
}

Node* BST::getMax(Node* n)
{
    while(n->getRight())
        n = n->getRight();
    return n;
}

int BST::getMaxValue()
{
    return(getMax(root)->getValue());
}

void BST::remove(int a)
{
    if(!root) return;
    else if(!search(a)) return;
    else removeHelper(a, search(a));
}

void BST::deleteMin()
{
    removeHelper(getMinValue(), getMin(root));
}

void BST::deleteMax()
{
    removeHelper(getMaxValue(), getMax(root));
}


Node* BST::removeHelper(int a, Node* n)
{
    while(root != n)
    {
        if(a < root->getValue())
        {
            if (root->getLeft() == n || root->getRight() == n) break;
            root = root->getLeft();
            if (root->getLeft() == n || root->getRight() == n) break;
        }
        else
        {
            if (root->getLeft() == n || root->getRight() == n) break;
            root = root->getRight();
            if(root->getLeft() == n || root->getRight() == n) break;
        }
    }

    // Removing a leaf node:
    if(!n->getLeft() && !n->getRight())
    {
        if(root->getRight() == n)
            root->setRight(nullptr);
        if(root->getLeft() == n)
            root->setLeft(nullptr);
    }

    // Removing node with exactly one child:
    else if(!n->getLeft() != !n->getRight())
    {
        Node* temp2 = new Node();
        if(n->getRight())
            temp2 = n->getRight();

        else
            temp2 = n->getLeft();

        n = temp2;

        if(root->getLeft() == n)
            root->setLeft(temp2);
        else
            root->setRight(temp2);

        temp2 = nullptr;
        delete temp2;
    }

    // Removing node with 2 children:
    else if(n->getLeft() && n->getRight())
    {
        Node* temp3 = new Node();
        temp3 = getMin(n->getRight());

        n->setValue(temp3->getValue());

        n->setRight(removeHelper(temp3->getValue(), n->getRight()));

        temp3 = nullptr;
        delete temp3;
    }
    return n;
}

void BST::preOrder()
{
    cout << "PreOrder:  ";
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
    cout << "InOrder:  ";
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

void BST::levelOrder()
{
    cout << "LevelOrder:  ";
    levelOrderHelper(root);
}

void BST::levelOrderHelper(Node* subtree)
{
    Queue* myQueue = new Queue();

    Node* temp = new Node();

    if(subtree)
        myQueue->add(root);

    while(!myQueue->isEmpty())
    {
        temp = myQueue->pop();
        cout << temp->getValue() << " " ;
        if(temp->getLeft())
            myQueue->add(temp->getLeft());
        if(temp->getRight())
            myQueue->add(temp->getRight());
    }
}
