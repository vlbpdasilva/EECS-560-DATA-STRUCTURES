#include "Node.h"


Node::Node()
{
	this->m_next = nullptr;
}


void Node::setValue (int val)
{
	this->m_value = val;
}


int Node::getValue ()
{
	return this->m_value;
}

void Node::setNext (Node* next)
{
	this->m_next = next;
}

Node* Node::getNext()
{
	return this->m_next;
}