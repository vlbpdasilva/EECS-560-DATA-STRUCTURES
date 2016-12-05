/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/


#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "Node.h"

template <typename T>
class LeftistHeap

{
    public:
    LeftistHeap();
    ~LeftistHeap();
    void insert(T x);
    void deleteMin();
    Node<T>* m_root; 
    
    private:
    void deleteHelper(Node<T>* n);
    Node<T>* merge(Node<T>* leftHeap, Node<T>* rightHeap);

};

#include "LeftistHeap.hpp"
#endif
