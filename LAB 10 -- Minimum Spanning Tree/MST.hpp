/**
*	@file : 
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "MST.h"
#include "LeftistHeap.h"

MST::MST(int size)
{
    _size = size;
    _array = new int*[size];
    sizeAcc = 0;
	
    for(int a = 0; a < _size; ++a)
    {
        _array[a] = new int[_size];
        for(int b = 0; b < _size; ++b)
            _array[a][b] = 0;
    }
}

MST::~MST()
{
    memdelete();
}

void MST::memdelete()
{
	 for(int a = _size; a > 0; --a)
        delete[] _array;
    delete[] _array;
}

void MST::build(int a, int b, int copy)
{
    _array[a][b] = copy;
}

void MST::Kruskal()
{
    sizeAcc = 0;
    Edge set[_size], myEdge, tempEdge;
    _disjSet = new Element[_size];
    
    LeftistHeap<Edge>* edge_set = new LeftistHeap<Edge>();
    
    for(int i = 0; i < _size; ++i)
        for(int j = 0; j < _size; ++j)
            if(_array[i][j] != 0)
            {
                myEdge.a = i;
                myEdge.b = j;
                myEdge.copy = _array[i][j];
                
                if(i < j || _array[j][i] != myEdge.copy)
                    edge_set->insert(myEdge);
            }
            
    while(sizeAcc < _size - 1 && edge_set->m_root)
    {
        tempEdge = edge_set->m_root->getValue();
        edge_set->deleteMin();
        
        if(findCycle(tempEdge))
        {
        		performUnion(findEdge(tempEdge.a), findEdge(tempEdge.b));
            set[sizeAcc] = tempEdge;
            ++sizeAcc;
        }
    }
    
    if(sizeAcc == _size - 1)
    {
        sizeAcc = 0;
        while(sizeAcc < _size - 1)
        {
            Edge finalEdge = set[sizeAcc];
            std::cout << "(" << finalEdge.a << "," << finalEdge.b << ")";
            ++sizeAcc;
        }
    }
    else std::cout << "No solutions found.\n"; 
    
    delete[] _disjSet;
    delete edge_set;            
    edge_set = nullptr;    	
}

bool MST::findCycle(Edge& _edge)
{
    return findEdge(_edge.a) != findEdge(_edge.b);
}

int MST::findEdge(int _edge_value)
{    
    if(_disjSet[_edge_value].parent == -1) return _edge_value;    
    _disjSet[_edge_value].parent = findEdge(_disjSet[_edge_value].parent);
    return _disjSet[_edge_value].parent;  
}

void MST::performUnion(int a, int b)
{
    int first = findEdge(a);
    int second = findEdge(b);
    
    if(_disjSet[first].rank < _disjSet[second].rank)  
        _disjSet[first].parent = second;        
    else if(_disjSet[first].rank == _disjSet[second].rank)
    {
 			_disjSet[second].parent = first;
        ++_disjSet[first].rank;    
    }    
    else _disjSet[second].parent = first;       
}

void MST::Prim()
{
    sizeAcc = 0;
    Edge set[_size], myEdge, myEdge2, myEdge3, finalEdge;
    int VTarray[_size], VTsize, dummy, i;
   
    VTarray[0] = 1;
	 VTsize = 1;
    
    for(i = 0; i < _size; ++i)
        VTarray[i] = 0;
    
    LeftistHeap<Edge>* edge_set = new LeftistHeap<Edge>();
        
    for(i = 0; i < _size; ++i)
        if(_array[1][i] != 0)
        {
            myEdge.a = 1;
            myEdge.b = i;
            myEdge.copy = _array[1][i];
            
            if(i < 1 && _array[i][1] == myEdge.copy) 
            {
                myEdge.a = i;
                myEdge.b = 1;
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
	        
	        VTarray[myEdge2.a] = 1;
	        VTarray[myEdge2.b] = 1;
	        ++VTsize;
	        
	        dummy = myEdge2.b;
	        
	        for(int j = 0; j < _size; ++j)
	            if(_array[dummy][j] != 0)
	            {
	                myEdge3.a = dummy;
	                myEdge3.b = j;
	                myEdge3.copy = _array[dummy][j];
	                
	                if(j < dummy && _array[j][dummy] == myEdge3.copy)
	                {
	                    myEdge3.a = j;
	                    myEdge3.b = dummy;
	                }
	                
	                if(VTarray[myEdge3.a] == 0 || VTarray[myEdge3.b] == 0)
	                   edge_set->insert(myEdge3);	                
	           }
	      }
    }
    
	 if(sizeAcc == _size - 1)
    {
        sizeAcc = 0;
        while(sizeAcc < _size - 1)
        {
            finalEdge = set[sizeAcc];
            std::cout << "(" << finalEdge.a << "," << finalEdge.b << ")";
            ++sizeAcc;
        }
    }
    else std::cout << "No solutions found.\n"; 
    
    delete edge_set;
    edge_set = nullptr;        
}