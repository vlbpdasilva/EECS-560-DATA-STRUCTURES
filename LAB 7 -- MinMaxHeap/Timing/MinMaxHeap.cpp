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

#define _MAX_SIZE 500000

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
    for(int i = 1; i <= sizeBuilder; i++)
    {
        array[i] = values[i-1];
        size++;
    }
    size++;

    trickleDown();
}

void MinMaxHeap::insert(int a)
{
    if(size >= _MAX_SIZE) 
        return;
    
    if(size - 2 == 0)
        array[1] = a;
    else
    {
        int node = size - 1;
        int parent = size/2;
        bool minNode = ((int)(floor(log2(parent))) % 2 == 0) ? 1 : 0;

        array[size] = a;
        
        if(minNode)
        {   
            if(array[parent] > a)
                swap(array[parent], array[size]);
        }
        else if(array[parent] < a)
                swap(array[parent], array[size]);  
    }
    size++;
    bubbleUp(size - 1);
}

void MinMaxHeap::trickleDown()
{    
    int NonLeaf_index = size / 2;    
    bool minNode, has_gc;
    int ChildOne_index, ChildTwo_index, min_gc_index, max_gc_index;
    int granchildren_index[4];
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

void MinMaxHeap::deleteMin()
{
    if(size-2 == 0) 
        return;
    else if(size-1 == 1)        
        size--;
    else if(size-1 == 2)
    {
        swap(array[1], array[2]);
        size--;
    }
    else if(size-1 == 3)
    {
    
        if(array[2] < array[3])
            swap(array[1], array[2]);
        else swap(array[1], array[3]);        
        size--;
    }
    else
    {        
        int last_element = array[size-1];
        int second_smallest_index = 4;
        int second_smallest_value = array[4];
        
        for(int i = 5; i <= 7 && i < size; i++)
            if(array[i] < second_smallest_value)
            {
                second_smallest_value = array[i];
                second_smallest_index = i;
            }
        
        if(last_element <= second_smallest_value)
            array[1] = last_element;
        else
        {
            swap(array[1], array[second_smallest_index]);
            swap(array[second_smallest_index], array[size-1]);
        }
        size--;
    }   
}

void MinMaxHeap::deleteMax()
{
    if(size == 0) 
        return;
    else if(size < 4)
        size--;
    else
    {
        int max_index = 2;
        int second_largest_index = 8;
        int second_largest_value = array[8];

        if(array[3] > array[2]) max_index = 3;
        
        for(int i = 8; i <= 15 && i < size; i++)
            if(array[i] > second_largest_index)
            {
                second_largest_value = array[i];
                second_largest_index = i;
            }
            
        swap(array[max_index], array[second_largest_index]);
        swap(array[second_largest_index], array[size-1]);
        size--;
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

void MinMaxHeap::bubbleUp(int index)
{
    if(index < 4) return;
    int parent = size/2;
    int grandparent = index/4;    
    bool minNode = ((int)(floor(log2(index))) % 2 == 0) ? 1 : 0;
    
    if(minNode)
    {    
        if(array[index] < array[grandparent])
            swap(array[index], array[grandparent]);
    }
    else
        if(array[index] > array[grandparent])
            swap(array[index], array[grandparent]);
        
    bubbleUp((index - 1)/2);
}
