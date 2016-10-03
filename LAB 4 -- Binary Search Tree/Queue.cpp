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
        m_back = n;
    }
    
    else
    {   
        m_back->setNext(n);      
        m_back = n;
    }
}

Node* Queue::pop()
{
    Node* temp = new Node();
    if(m_front)
    {
        temp = m_front;
        m_front= m_front->getNext();
        return temp;
    }    
}

bool Queue::isEmpty()
{
    if (m_front) return 0; return 1;
}

void Queue::print()
{   
    if(!m_front) return;

    Node* temp = new Node();
    
    temp = m_front;
        while(temp->getNext())
        {
            std::cout << temp->getValue() << " " << std::endl;
            temp = temp->getNext();
        }
        std::cout << m_back->getValue() << " " << std::endl;    
}
