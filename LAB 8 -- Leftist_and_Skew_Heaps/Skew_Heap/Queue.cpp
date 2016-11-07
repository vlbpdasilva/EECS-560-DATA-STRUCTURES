/**
*	@file : 
*	@author :  Victor Berger da Silva
*	@date :
*/	

#include "Queue.h"
#include "Node.h"

#include <iostream>

using namespace std;

Queue::Queue()
{
    m_front = nullptr;
    m_back = nullptr;
}

Queue::~Queue()
{
}

void Queue::add (Node* n)
{    
    if(!m_front)
    {
        m_front = n;
        m_front->setNext(nullptr);
        m_back = n;
        m_back->setNext(nullptr);
    }    
    else
    {
        m_back->setNext(n);      
        m_back = n;
        m_back->setNext(nullptr);
    }
}

Node* Queue::pop()
{
    Node* temp = new Node();
    if(m_front)
    {
        temp = m_front;
        m_front= temp->getNext();
        return temp;
    } 
    return nullptr;
}

bool Queue::isEmpty()
{
    if (m_front) return 0; return 1;
}

