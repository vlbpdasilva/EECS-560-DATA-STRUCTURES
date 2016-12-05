/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/

#include "AdjList.h"

AdjList::AdjList() : _next(nullptr)
{
	AdjListNode node;
	_node = node;
}

AdjList::~AdjList()
{
	delete _next;
	_next = nullptr;
}