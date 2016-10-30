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
    bool minNode, has_gc;
    int ChildOne_index, ChildTwo_index;
    int granchildren_index[4];
    int min_gc_index, max_gc_index;
    
    while(NonLeaf_index >= 1)
    {    
        minNode = ((int)(floor(log2(NonLeaf_index))) % 2 == 0) ? 1 : 0;
        has_gc = 0;
        
        for(int i = 0; i <= 3; i++) granchildren_index[i] = -1;
                
        if(2 * NonLeaf_index + 1 <= size) 
            ChildOne_index = 2 * NonLeaf_index;
        else ChildOne_index = -1;
                
        if(2 * NonLeaf_index + 2 <= size)
            ChildTwo_index = 2 * NonLeaf_index + 1;
        else ChildTwo_index = -1;
        
        if(ChildOne_index != -1)
        {
            if(2 * ChildOne_index + 1 <= size) 
                granchildren_index[0] = 2 * ChildOne_index;
            if(2 * ChildOne_index + 2 <= size) 
                granchildren_index[1] = 2 * ChildOne_index + 1;
        }
        if(ChildTwo_index != -1)
        {
            if(2 * ChildTwo_index + 1 <= size) 
                granchildren_index[2] = 2 * ChildTwo_index;
            if(2 * ChildTwo_index + 2 <= size) 
                granchildren_index[3] = 2 * ChildTwo_index + 1;
        }
 
        if(granchildren_index[0] != -1) has_gc = 1;
        
        if(has_gc)
        {
            min_gc_index =  granchildren_index[0];
            for(int j = 0; j < 3; j++)
                if(granchildren_index[j] != -1 && array[granchildren_index[j]] < array[granchildren_index[j+1]])
                    min_gc_index = j;
            if(granchildren_index[3] != -1 && array[granchildren_index[3]] < array[granchildren_index[min_gc_index]])
                min_gc_index = 3;
            
            max_gc_index = granchildren_index[0];
            for(int o = 0; o < 3; o++)
                if(granchildren_index[o] != -1 && array[granchildren_index[o]] > array[granchildren_index[o+1]])
                    max_gc_index = o;
            if(granchildren_index[3] != -1 && array[granchildren_index[3]] > array[granchildren_index[max_gc_index]])
                max_gc_index = 3;
        }

        if(minNode)
        {
            if(ChildOne_index != -1 && ChildTwo_index == -1 && array[ChildOne_index] < array[NonLeaf_index])            
                swap(array[ChildOne_index], array[NonLeaf_index]);
            if(ChildOne_index != -1 && ChildTwo_index != -1)
            {
                if(array[ChildOne_index] < array[ChildTwo_index] && array[ChildOne_index] < array[NonLeaf_index])
                    swap (array[ChildOne_index], array[NonLeaf_index]);
                if(array[ChildTwo_index] < array[ChildOne_index] && array[ChildTwo_index] < array[NonLeaf_index])
                    swap (array[ChildTwo_index], array[NonLeaf_index]);
            }       
            
            if(has_gc)
                if(array[granchildren_index[min_gc_index]] < array[NonLeaf_index])
                    swap(array[granchildren_index[min_gc_index]], array[NonLeaf_index]);
        }
        else
        {
            if(ChildOne_index != -1 && ChildTwo_index == -1 && array[ChildOne_index] > array[NonLeaf_index])   
                swap(array[ChildOne_index], array[NonLeaf_index]);
            
            if(ChildOne_index != -1 && ChildTwo_index != -1)
            {
                if(array[ChildOne_index] > array[ChildTwo_index] && array[ChildOne_index] > array[NonLeaf_index])
                    swap (array[ChildOne_index], array[NonLeaf_index]);
                if(array[ChildTwo_index] > array[ChildOne_index] && array[ChildTwo_index] > array[NonLeaf_index])
                    swap (array[ChildTwo_index], array[NonLeaf_index]);
            }
            
            if(has_gc)
                if(array[granchildren_index[max_gc_index]] > array[NonLeaf_index])
                    swap(array[granchildren_index[max_gc_index]], array[NonLeaf_index]);
        }

        NonLeaf_index--;
    }
}

void MinMaxHeap::levelOrder()
{    
    int counter = 1;
    
    for(int i = 1; i < size; i++)
    {  
        if(i == counter) 
        {
            cout << endl;
            counter = 2 * counter;
        }
        cout << array[i] << " ";
    }
}
