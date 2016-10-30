/**
*	@file : 
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "MinMaxHeap.h"
#include <iostream>
#include <math.h>   
#include <cmath>

using namespace std;

MinMaxHeap::MinMaxHeap()
{
    array[0] = -1;
    size = 0;
}

MinMaxHeap::~MinMaxHeap()
{
}

void MinMaxHeap::build(int values[], int sizeBuilder)
{

    for(int i = 1; i < sizeBuilder+2; i++)
    {
        array[i] = values[i-1];
        size++;
    }
    
    trickleDown();

}

void MinMaxHeap::trickleDown()
{
    int NonLeaf_index = (size - 1) / 2;    
    bool minNode = ((int)(floor(log2(NonLeaf_index))) % 2 == 0) ? 1 : 0;
    
    int ChildOne_index, ChildTwo_index;
    while(NonLeaf_index >= 1)
    {    
        minNode = ((int)(floor(log2(NonLeaf_index))) % 2 == 0) ? 1 : 0;
                
        if(2 * NonLeaf_index + 1 <= size) 
            ChildOne_index = 2 * NonLeaf_index;
        else ChildOne_index = -1;
                
        if(2 * NonLeaf_index + 2 <= size)
            ChildTwo_index = 2 * NonLeaf_index + 1;
        else ChildTwo_index = -1;

        if(minNode)
        {
            cout <<"Min Node is " << array[NonLeaf_index] << endl;
            if(ChildOne_index != -1 && ChildTwo_index == -1 && array[ChildOne_index] < array[NonLeaf_index])            
                swap(array[ChildOne_index], array[NonLeaf_index]);
            if(ChildOne_index != -1 && ChildTwo_index != -1)
            {
                if(array[ChildOne_index] < array[ChildTwo_index] && array[ChildOne_index] < array[NonLeaf_index])
                    swap (array[ChildOne_index], array[NonLeaf_index]);
                if(array[ChildTwo_index] < array[ChildOne_index] && array[ChildTwo_index] < array[NonLeaf_index])
                    swap (array[ChildTwo_index], array[NonLeaf_index]);
            }         
        }
        else
        {
            cout <<"Max Node is " << array[NonLeaf_index] << endl;
            if(ChildOne_index != -1 && ChildTwo_index == -1 && array[ChildOne_index] > array[NonLeaf_index])   
                swap(array[ChildOne_index], array[NonLeaf_index]);
            
            if(ChildOne_index != -1 && ChildTwo_index != -1)
            {
                if(array[ChildOne_index] > array[ChildTwo_index] && array[ChildOne_index] > array[NonLeaf_index])
                    swap (array[ChildOne_index], array[NonLeaf_index]);
                if(array[ChildTwo_index] > array[ChildOne_index] && array[ChildTwo_index] > array[NonLeaf_index])
                    swap (array[ChildTwo_index], array[NonLeaf_index]);
            }
        }
        
        levelOrder(); cout << endl << endl;
        NonLeaf_index--;
    }
}

void MinMaxHeap::levelOrder()
{
    for(int i = 1; i < size; i++)
        cout << array[i] << " ";    
}