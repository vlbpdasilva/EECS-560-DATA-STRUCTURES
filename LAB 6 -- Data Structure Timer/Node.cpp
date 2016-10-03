/**
*	@file : Node.cpp
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "Node.h"
#include <iostream>

Node::Node()
{
    this->m_left = nullptr;
    this->m_right = nullptr;
    this->next = nullptr;
}

void Node::setValue(int i)
{
    this->m_value = i;
}

int Node::getValue()
{
    return this->m_value;
}

void Node::setLeft(Node* left)
{
    this->m_left = left;
}

Node* Node::getLeft()
{
    return this->m_left;
}

void Node::setRight(Node* right)
{
    this->m_right = right;
}

Node* Node::getRight()
{
    return this->m_right;
}

void Node::setNext(Node* n)
{
    this->next = n;
}

Node* Node::getNext()
{
    return this->next;
}
