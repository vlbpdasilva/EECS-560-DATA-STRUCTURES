/**
*	@file : Node.h
*	@author :  Victor Berger da Silva
*	@date : Aug 26 2016
*	Purpose: cpp file for Node class
	Single Linked List --- EECS 560 -- prof. Kong/TA: Hajiarbabi
*/


#include "Node.h"

/*
 * Constructor
 */
Node::Node()
{
	this->m_next = nullptr;
}

/*
 * @POST: sets value of Node. takes int argument
 * @RETURN: void
 */
void Node::setValue (int val)
{
	this->m_value = val;
}

/*
 * @PRE: existing instance of Node
 * @RETURN: int (value of Node)
 */
int Node::getValue ()
{
	return this->m_value;
}

/*
 * @POST: sets m_next pointer to next Node on linked list. takes Node* argument
 * @RETURN: void
 */
void Node::setNext (Node* next)
{
	this->m_next = next;
}

/*
 * @PRE: existing instance of Node
 * @RETURN: Node* (pointer to next Node)
 */
Node* Node::getNext()
{
	return this->m_next;
}
