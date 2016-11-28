/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/

#ifndef MST_H
#define MST_H

#include "LeftistHeap.h"

struct Element {int parent = -1; int rank = 0;};

struct Edge    {int a = 0; int b = 0; int copy = 0;
bool operator < (const Edge& rhs) const { return copy < rhs.copy; }};

class MST
{    
    public:
    MST(int size);
    ~MST();
    void build(int a, int b, int copy);
    void Kruskal();
    void Prim();
        
    private:
    int _size, **_array, sizeAcc;
    Element* _disjSet;
    bool findCycle (Edge& _edge);
    int findEdge (int _edge_value);
    void performUnion(int a, int b);
    void memdelete();
};

#include "MST.hpp"
#endif
