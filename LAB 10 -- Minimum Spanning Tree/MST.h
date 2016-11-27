/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
* 
*/


#ifndef MST_H
#define MST_H

#include "Node.h"

#define ROOT -1

struct Element {int parent = -1; int rank = 0;};
struct Edge    {int a = 0; int b = 0; int copy = 0;};

class MST
{
    
    public:
    MST(int size);
    ~MST();
    void build(int a, int b, int copy);
    void Kruskal();
    void Prim();
        
    private:
    int _size, **_array;
    Element* _disjSet;

    bool findCycle (Edge& _edge);
    int findEdge (int _edge_value);
    void performUnion(int a, int b);
    
};

#endif
