/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/

#ifndef MST_H
#define MST_H

#include "LeftistHeap.h"
#include "AdjList.h"

struct Element {int parent = -1; int rank = 0;};

struct Edge    {int a = 0; int b = 0; int copy = 0;
bool operator < (const Edge& rhs) const { return copy < rhs.copy; }};

class MST
{    
    public:
        MST(int size);
   	~MST();
    	void build(int a, int b, int c);
    	int Kruskal(), Prim(), currCost;
        
    private:
   	int _size, sizeAcc, findEdge(int _edge_value);
  	Element* _disjSet;
    	AdjList** _adjList;
    	bool findCycle (Edge& _edge);
    	void performUnion(int a, int b), resetGraph(), memdelete(), costUpdate(int _cost);
};

#include "MST.hpp"
#endif
