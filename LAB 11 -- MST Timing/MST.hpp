/**
*	@file : 
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "MST.h"
#include "LeftistHeap.h"
#include "AdjList.h"

MST::MST(int size)
{
    resetGraph();   
    _size = size;
    _adjList = new AdjList*[_size];
    for(int a = 0; a < _size; ++a) 
        _adjList[a] = nullptr;
}

MST::~MST()
{
    for(int a = 0; a < _size; ++a) 
        delete _adjList[a];
    delete [] _adjList;
}

void MST::resetGraph()
{
    sizeAcc = 0;
    currCost = 0;
}

void MST::build(int a, int b, int c)
{
    AdjList* myAdjList = _adjList[a];
    _adjList[a] = new AdjList();
    _adjList[a]->_node.b = b;
    _adjList[a]->_node.copy = c;
    _adjList[a]->_next = myAdjList;
}

int MST::Kruskal()
{
    resetGraph();
    Edge set[_size], myEdge, tempEdge;
    _disjSet = new Element[_size];    
    LeftistHeap<Edge>* edge_set = new LeftistHeap<Edge>();
    
    for(int i = 0; i < _size; ++i)
        for(AdjList* j = _adjList[i]; j; j = j->_next)
            if(j->_node.copy != 0)
            {
                myEdge.a = i;
                myEdge.b = j->_node.b;
                myEdge.copy = j->_node.copy;
                
                if(i < j->_node.b)
                    edge_set->insert(myEdge);
            }
            
    while(sizeAcc < _size - 1 && edge_set->m_root)
    {
        tempEdge = edge_set->m_root->getValue();
        edge_set->deleteMin();
        
        if(!findCycle(tempEdge)) 	
        {
            set[sizeAcc] = tempEdge;
            ++sizeAcc;
            currCost += tempEdge.copy;        
        }
    }

    delete[] _disjSet;
    delete edge_set;            
    edge_set = nullptr;    	
    
    return currCost; 
}

bool MST::findCycle(Edge& _edge)
{
    if(findEdge(_edge.a) != findEdge(_edge.b)) 
   	return 0;
    performUnion(findEdge(_edge.a), findEdge(_edge.b));
    return 1;
}

int MST::findEdge(int _edge_value)
{    
    if(_disjSet[_edge_value].parent == -1) 
        return _edge_value;    
    _disjSet[_edge_value].parent = findEdge(_disjSet[_edge_value].parent);
    return _disjSet[_edge_value].parent;  
}

void MST::performUnion(int a, int b)
{
    int first = findEdge(a);
    int second = findEdge(b);
    
    if(_disjSet[first].rank < _disjSet[second].rank)  
    {
        _disjSet[first].parent = second;  
        return;     
    }        
    if(_disjSet[first].rank == _disjSet[second].rank)
        ++_disjSet[first].rank;    
    _disjSet[second].parent = first;       
}

int MST::Prim()
{
    resetGraph();
    Edge set[_size], myEdge, myEdge2, myEdge3, finalEdge;
    int VTarray[_size], VTsize, i, edgeVal;
    LeftistHeap<Edge>* edge_set = new LeftistHeap<Edge>();
    VTarray[0] = 1;
    VTsize = 1;
    
    for(i = 0; i < _size; ++i) 
        VTarray[i] = 0;

    for(AdjList* k = _adjList[0]; k; k = k->_next)
        if(k->_node.copy != 0)
        {
            myEdge.a = 0;
            myEdge.b = k->_node.b;
            myEdge.copy = k->_node.copy;
            
            if(k->_node.b < 0)
            {
                myEdge.a = k->_node.b;
                myEdge.b = 0;
            }
            
            if(VTarray[myEdge.a] == 0 || VTarray[myEdge.b] == 0) 
                edge_set->insert(myEdge);
        }
      
    while(edge_set->m_root && VTsize != _size)
    {
        myEdge2 = edge_set->m_root->getValue();
        edge_set->deleteMin();
      
        if(VTarray[myEdge2.a] != 1 || VTarray[myEdge2.b] != 1)
        {
            set[sizeAcc] = myEdge2;
            ++sizeAcc;
            currCost += myEdge2.copy;
			  
            if(VTarray[myEdge2.a] == 0)
            {
                VTarray[myEdge2.a] = 1;
                edgeVal = myEdge2.a;
            }
			  
            if(VTarray[myEdge2.b] == 0)
            {
                VTarray[myEdge2.b] = 1;
                edgeVal = myEdge2.b;
            }

            for(AdjList* i = _adjList[edgeVal]; i; i=i->_next)
                if(i->_node.copy != 0)
                {
                    myEdge3.a = edgeVal;
                    myEdge3.b = i->_node.b;
                    myEdge3.copy = i->_node.copy;
	                
                    if(i->_node.b < edgeVal)
                    {
                        myEdge3.a = i->_node.b;
                        myEdge3.b = edgeVal;
                    }
	                
                    if(VTarray[myEdge3.a] == 0 || VTarray[myEdge3.b] == 0)
                        edge_set->insert(myEdge3);	                
                }
            ++VTsize;
        }
    }
    
    delete edge_set;
    edge_set = nullptr;
              
    return currCost;
}
