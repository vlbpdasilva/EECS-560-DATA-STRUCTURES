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
    void build(int a, int b, int copy);
    int Kruskal();
    int Prim();
        
    private:
    int _size, sizeAcc, currCost;
    Element* _disjSet;
    AdjList** _adjList;
    bool findCycle (Edge& _edge);
    int findEdge (int _edge_value);
    void performUnion(int a, int b);
};

#include "MST.hpp"
#endif
