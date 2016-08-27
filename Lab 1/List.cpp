#include "List.h"
#include "Node.h"

#include <iostream>

List::List()
{
		this -> m_back = nullptr;
		this -> m_front = nullptr;
		this -> isEmpty = 1;
}

List::~List()
{
	memdelete();
}

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
