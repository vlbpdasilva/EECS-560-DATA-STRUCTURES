/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/

#ifndef ADJLIST_H
#define ADJLIST_H

struct AdjListNode {int b = 0; int copy = 0;};

class AdjList
{    
    public:
   	 AdjList();
   	 ~AdjList();
   	 AdjListNode _node;
  	 	 AdjList* _next;
};

#endif