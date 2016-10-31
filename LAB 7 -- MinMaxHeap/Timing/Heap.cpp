/**
*	@file : 
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "Heap.h"
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

Heap::Heap()
{
    size = 0;
}

Heap::~Heap()
{
}

void Heap::builder() /// CONSTRUCTS THE INITIAL HEAP, ONLY CALLED ONCE
{
        for(int i = 0; i < 500000; i++)
		array[i] = -1;
}   

bool Heap::hasChildren(int a)
{	
	for(int i = 1; i <= 5; i++)
		if(array[(5*a+i)] != -1){
			return 1;
		}
	return 0;
}

void Heap::deleteMax()
{    
	if(size == 0) return;       
	int first_leaf_index = (size-1)/5 + 1;
	int max = array[first_leaf_index];
	int max_index = first_leaf_index;
        
	for(first_leaf_index; first_leaf_index < size; first_leaf_index++)
            if(array[first_leaf_index] > max)
            {	
                max = array[first_leaf_index];
                max_index = first_leaf_index;
            }
		
	//array[max_index] = array[size - 1];
        size--;
	
        while(max_index > 0)
        {
            goingUp(max_index);
            max_index = (max_index - 1)/5;
        }
}

void Heap::insert(int x)
{
    if(size >= 500000) return;
    
    array[size] = x;
    size++;
}

void Heap::heapify(int x) // GOING UP
{	

	int element = array[x];           		    
	int parent_index = floor((x-1)/5);
	int parent = array[parent_index];
	
	int child_value;
	int children_index[5];
	int smallestChild;

	for(int i = 0; i < 5; i++)
	{
		children_index[i] = -1;
		child_value = array[(5*x)+i+1];
		if(child_value != -1)
			children_index[i] = child_value;
	}
	
	for(int a = 0; a < 5; a++)
		if(children_index[a+1] < children_index[a])
			smallestChild = children_index[a+1];		
	
	if(array[x] > smallestChild)
		swap(array[x], array[search(smallestChild)]);
	
}

int Heap::search(int x) // will return -1 if value not found; will only return first index if duplicate
{
    for(int i = 0; i < 500000; i++)
        if (array[i] == x) return i;
    return -1;
}

int Heap::search(int x, int beg) // will return -1 if value not found; will only return first index if duplicate
{
    for(int i = beg; i < 500000; i++)
        if (array[i] == x) return i;
    return -1;
}

void Heap::levelorder() // prints tree-like diagram
{	
	if(array[0] == -1)
            return;
	else
	{
		cout<<"\nLevel-Order Traversal:\n"<< array[0] << endl;	
		int counter = 1;
		int counterOfFive = 0;
		
		for(int i = 1; i <= 3; i++)
		{
			for(int j = 1; j <= pow(5,i); j++)
			{	
				if(array[counter] == -1) break;
				cout << array[counter] << " ";
				counter++;
				counterOfFive++;
				if(counterOfFive == 5)
				{
					cout << " - ";
					counterOfFive = 0;				
				}
			}
			cout << endl;
		}
	} 
}

void Heap::deleteMin() /// calls remove() on root, without removing duplicates
{
	if(array[0] == -1)
            return;
	else	
            remove(array[0],0,0);
}

///PRIVATE:
void Heap::remove(int value, bool all, int value_index) /// if all == 1, will remove all duplicates
{
	
	if(value_index == -1) return;

	int last_element_index = size - 1;
        if(last_element_index == -1) return;
	
	array[value_index] = array[last_element_index];
	array[last_element_index] = -1;

	size--;

    goDown(value_index);
	if(all){
			value_index = search(value, value_index);
            
            remove(value,1, value_index);
        }
}

void Heap::remove(int value) // calls private remove, with specific flag for duplicates
{
	int value_index = search(value);
	remove(value, 1, value_index);
}

void Heap::goingUp(int x) // goes up on heap, swapping if needed, all the way to root. Recursive
{
	if(x==0) return;
	int element = array[x];           		    // x --> index, element --> array[index]
	int parent_index = floor((x-1)/5);
	int parent = array[parent_index];
	
	if(element < parent)
	{
		int temp = array[x];
		array[x] = array[parent_index];
		array[parent_index] = temp;
		goingUp(parent_index);
	}
}

void Heap::goDown(int hole_index) // goes down on heap, swapping if needed, all the way to leaves. Recursive
{
	if(5 * hole_index + 1 > 500000)
		return;

	if(!hasChildren(hole_index)) return;
	
	int children_index[5];
	for (int i = 0; i <= 4; i++)
	{
		children_index[i] = -1;
		if(array[(5*hole_index + i + 1)] != -1)
			children_index[i] = (5*hole_index + i + 1);
	}

	for(int j = 0; j < 5; j++)
		if(children_index[j] != -1 && array[children_index[j]] < array[hole_index])
		{
			swap(array[children_index[j]],array[hole_index]);
			goDown(children_index[j]);
		} 
}
