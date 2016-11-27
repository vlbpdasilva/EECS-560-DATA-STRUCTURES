/**
*	@file : 
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "MST.h"
#include "LeftistHeap.h"
#include <iostream>
using namespace std;

MST::MST(int size)
{
    _size = size;
    _array = new int*[size];
	
    for(int a = 0; a < _size; ++a)
    {
        _array[a] = new int[_size];
        for(int b = 0; b < _size; ++b)
            _array[a][b] = 0;
    }
}

MST::~MST()
{
    for(int a = _size; a > 0; a--)
        delete[] _array;
    delete[] _array;
}

void MST::build(int a, int b, int copy)
{
    _array[a][b] = copy;
}

void MST::Kruskal()
{
    int sizeAcc = 0;
    Edge set[_size];
    _disjSet = new Element[_size];
	
}

void MST::Prim()
{
    int sizeAcc = 0;
    Edge set[_size];
    
    int VTarray[_size];
    VTarray[0] = 1;
    
    int VTsize = 1;
    
    for(int i = 0; i < _size; i++)
        VTarray[i] = 0;
    
	LeftistHeap<Edge>* edgeSet = new LeftistHeap<Edge>(); // DOESNT WORK
    
    
}


