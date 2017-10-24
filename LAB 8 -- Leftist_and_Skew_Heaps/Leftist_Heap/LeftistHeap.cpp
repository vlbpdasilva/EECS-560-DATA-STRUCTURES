/**
*	@file : LeftistHeap.cpp
*	@author :  Victor Berger da Silva
*	@date : Nov 06 2016
*
*/

#include "LeftistHeap.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
using namespace std;

LeftistHeap::LeftistHeap()
{
    m_root = nullptr;
}

LeftistHeap::~LeftistHeap()
{
   if(m_root) deleteHelper(m_root);
}

void LeftistHeap::deleteHelper(Node* n)
{
    if(!n) return;

    deleteHelper(n->getLeft());
    deleteHelper(n->getRight());
    delete n;
}

void LeftistHeap::insert(int x)
{
    Node* newNode = new Node();
    newNode->setValue(x);
    m_root = merge(m_root, newNode);
}

void LeftistHeap::deleteMin()
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

Node* LeftistHeap::merge(Node* leftHeap, Node* rightHeap)
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
        if(leftHeap->getLeft()->getRank() < leftHeap->getRight()->getRank())
        {
            Node* temp = leftHeap->getLeft();
            leftHeap->setLeft(leftHeap->getRight());
            leftHeap->setRight(temp);
        }

        leftHeap->setRank(leftHeap->getRight()->getRank() + 1);
    }

    return leftHeap;
}

void LeftistHeap::levelOrder()
{
    if(!m_root)
        cout << "Heap is empty, nothing to display.";
    else
    {
        cout << "Level Order Traversal: ";
        levelOrderHelper(m_root);
    }
}

void LeftistHeap::levelOrderHelper(Node* n)
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

void LeftistHeap::preOrder()
{
    if(!m_root)
        cout << "Heap is empty, nothing to display.";
    else
    {
        cout << "Pre Order Traversal: ";
        preOrderHelper(m_root);
    }
}

void LeftistHeap::preOrderHelper(Node* n)
{
    if(!n) return;

    cout << n->getValue() << " ";
    preOrderHelper(n->getLeft());
    preOrderHelper(n->getRight());
}

void LeftistHeap::inOrder()
{
    if(!m_root)
        cout << "Heap is empty, nothing to display.";
    else
    {
        cout << "In Order Traversal: ";
        inOrderHelper(m_root);
    }
}

void LeftistHeap::inOrderHelper(Node* n)
{
    if(!n) return;

    preOrderHelper(n->getLeft());
    cout << n->getValue() << " ";
    preOrderHelper(n->getRight());
}
