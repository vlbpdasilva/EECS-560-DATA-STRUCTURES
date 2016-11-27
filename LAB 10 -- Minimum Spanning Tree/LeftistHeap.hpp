/**
*	@file : LeftistHeap.cpp
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "LeftistHeap.h"

template <typename T>
LeftistHeap<T>::LeftistHeap()
{
    m_root = nullptr;
}

template <typename T>
LeftistHeap<T>::~LeftistHeap()
{
   if(m_root) deleteHelper(m_root);
}

template <typename T>
void LeftistHeap<T>::deleteHelper(Node<T>* n)
{
    if(!n) return;
    
    deleteHelper(n->getLeft());
    deleteHelper(n->getRight());
    delete n;    
}

template <typename T>
void LeftistHeap<T>::insert(T x)
{
    Node<T>* newNode = new Node<T>();
    newNode->setValue(x);
    m_root = merge(m_root, newNode);
}

template <typename T>
void LeftistHeap<T>::deleteMin()
{
    if(m_root)
    {
        Node<T>* temp = m_root;
        m_root = merge(m_root->getLeft(), m_root->getRight());
        delete temp;
    }
}

template <typename T>
Node<T>* LeftistHeap<T>::merge(Node<T>* leftHeap, Node<T>* rightHeap)
{
    if(!leftHeap) return rightHeap;
    if(!rightHeap) return leftHeap;
    
    if(rightHeap->getValue() < leftHeap->getValue())
    {
        Node<T>* temp = leftHeap;
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
            Node<T>* temp = leftHeap->getLeft();
            leftHeap->setLeft(leftHeap->getRight());
            leftHeap->setRight(temp);
        }
        
        leftHeap->setRank(leftHeap->getRight()->getRank() + 1);
    }
    
    return leftHeap;
}
