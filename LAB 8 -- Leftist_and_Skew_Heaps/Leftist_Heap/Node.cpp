/**
*	@file : Node.cpp
*	@author :  Victor Berger da Silva
*	@date : Nov 06 2016
*
*/

#include "Node.h"
#include <iostream>

Node::Node()
{
    this->m_left = nullptr;
    this->m_right = nullptr;
    this->m_rank = 0;
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

int Node::getRank()
{
    return this->m_rank;
}

void Node::setRank(int r)
{
    this->m_rank = r;
}

//FOR THE QUEUE:
void Node::setNext(Node* n)
{
    this->next = n;
}

Node* Node::getNext()
{
    return this->next;
}
