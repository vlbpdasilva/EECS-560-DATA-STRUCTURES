/**
*	@file : List.cpp
*	@author :  Victor Berger da Silva
*	@date : Aug 26 2016
*	Purpose: cpp file for List class
	Single Linked List --- EECS 560 -- prof. Kong/TA: Hajiarbabi
*/

#include "List.h"
#include "Node.h"

#include <iostream>

/*
 * Constructor for List class
 * @PRE: none
 * @POST: sets m_back and m_front pointers to null, isEmpty bool to true
 */
List::List()
{
		this -> m_back = nullptr;
		this -> m_front = nullptr;
		this -> isEmpty = 1;
}

/*
 * Destructor for List class. Calls memdelete()
 * @PRE: existing instance of List
 * @POST: deallocates memory
 */
List::~List()
{
	memdelete();
}

/*
 * Used in the destructor. Deletes all nodes in list 
 * @POST: empty list, deallocated memory
 */ 
void List::memdelete()
{
	Node* temp4 = m_front;
	while(!(temp4 == nullptr))
	{
		m_front = m_front->getNext();
		delete temp4;
		temp4 = m_front;	
	}
	
	m_front = m_back = nullptr;

}

/*
 * Inserts a value to the back of list. Requires int argument
 * @PRE: existing instance of list
 * @POST: value is inserted to back of list
 * @RETURN: void
 */
void List::insert(int n)
{
	
	if(isEmpty)
	{
		m_front = new Node();
		m_front->setValue(n);
		m_front -> setNext(nullptr);
		m_back = m_front;
		isEmpty = 0;
	
	}
	else
	{
		Node* temp = m_back;
		m_back = new Node();
		temp->setNext(m_back);
		m_back -> setValue(n);

	}
}

/*
 * Prints values of all nodes in list, starting from the m_front
 * @PRE: existing instance of list
 * @POST: prints values
 * @RETURN: void
 */
void List::print()
{

	Node* temp2 = m_front;

	while(!(temp2->getNext()==nullptr))
	{
		std::cout<<temp2->getValue()<<" ";
		temp2 = temp2->getNext();	
	}
			
	std::cout<< m_back->getValue() << std::endl;

}

/* Searches list for existing values
 * @PRE: existing instance of list
 * @POST: none
 * @RETURN: bool, 1 if value is found, 0 otherwise
 */
bool List::search(int f)
{
	Node* temp3 = m_front;
	
	while(!(temp3->getNext()==nullptr))
	{
		if(temp3->getValue()==f)
			return true;
		
		temp3 = temp3->getNext();
	}
	
	if(m_back->getValue()==f)
		return true;
	return false;

}

