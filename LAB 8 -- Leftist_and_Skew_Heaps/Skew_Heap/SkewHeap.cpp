/**
*	@file : SkewHeap.cpp
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "SkewHeap.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
using namespace std;

SkewHeap::SkewHeap()
{
    m_root = nullptr;
}

SkewHeap::~SkewHeap()
{
   if(m_root) deleteHelper(m_root);
}

void SkewHeap::deleteHelper(Node* n)
{
    if(!n) return;
    
    deleteHelper(n->getLeft());
    deleteHelper(n->getRight());
    delete n;    
}

void SkewHeap::insert(int x)
{
    Node* newNode = new Node();
    newNode->setValue(x);
    m_root = merge(m_root, newNode);
}

void SkewHeap::deleteMin()
{
    if(m_root)
    {
        Node* temp = m_root;
        m_root = merge(m_root->getLeft(), m_root->getRight());
        delete temp;
        cout << "Minimum element succesfully removed.";
    }
    else
        cout << "Heap is empty, nothing to delete.";
}

Node* SkewHeap::merge(Node* leftHeap, Node* rightHeap)
{
    if(!leftHeap) return rightHeap;
    if(!rightHeap) return leftHeap;
    
    if(rightHeap->getValue() < leftHeap->getValue())
    {
        Node* temp = leftHeap;
        leftHeap = rightHeap;
        rightHeap = temp;
    }
    
    if(!leftHeap->getLeft())
        leftHeap->setLeft(rightHeap);
    else
    {
        leftHeap->setRight(merge(leftHeap->getRight(), rightHeap));
        Node* temp = leftHeap->getLeft();
        leftHeap->setLeft(leftHeap->getRight());
        leftHeap->setRight(temp);
    }
    
    return leftHeap;
}

void SkewHeap::levelOrder()
{
    if(!m_root)
        cout << "Heap is empty, nothing to display.";
    else
    {
        cout << "Level Order Traversal: ";
        levelOrderHelper(m_root);
    }
}

void SkewHeap::levelOrderHelper(Node* n)
{
    Queue* myQueue = new Queue();    
    Node* temp = new Node();
   
    if(n) myQueue->add(n);
    else return;

    while(!myQueue->isEmpty())
    {
        temp = myQueue->pop();
        cout << temp->getValue() << " " ;
        if(temp->getLeft())
            myQueue->add(temp->getLeft());
        if(temp->getRight())
            myQueue->add(temp->getRight());  
    }
    
    delete myQueue;
}

void SkewHeap::preOrder()
{
    if(!m_root)
        cout << "Heap is empty, nothing to display.";
    else
    {
        cout << "Pre Order Traversal: ";
        preOrderHelper(m_root);
    }
}

void SkewHeap::preOrderHelper(Node* n)
{
    if(!n) return;
    
    cout << n->getValue() << " ";
    preOrderHelper(n->getLeft());
    preOrderHelper(n->getRight());
}

void SkewHeap::inOrder()
{
    if(!m_root)
        cout << "Heap is empty, nothing to display.";
    else
    {
        cout << "In Order Traversal: ";
        inOrderHelper(m_root);
    }
}

void SkewHeap::inOrderHelper(Node* n)
{
    if(!n) return;
    
    preOrderHelper(n->getLeft());
    cout << n->getValue() << " ";
    preOrderHelper(n->getRight());    
}
