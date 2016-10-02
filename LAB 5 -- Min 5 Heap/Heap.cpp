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
    int array[500];
}

Heap::~Heap()
{
}

void Heap::builder(int a[], int b)
{
    for(int i = 0; i < 500; i++)
		array[i] = -1;
    
	for(int i = 0; i < b; i++)
		array[i] = a[i];    
    
	int i = std::floor(b/5) + 1;
	for(i; i <= b; i++)
		heapify(b-i); 
}   

bool Heap::hasChildren(int a)
{
	for(int i = 1; i <= 5; i++)
		if(array[(5*a+i)] != -1)
			return 1;
	return 0;
}

void Heap::deleteMax()
{
	if(array[0] == -1) return;
	
	int last_element_index = find_last_element_index();
	int first_leaf_index = floor((last_element_index-1)/5) + 1;
	int max = array[first_leaf_index];
	int max_index;
	for(int j = first_leaf_index; j <= last_element_index; j++)
		if(array[j] > max)
		{	
			max = array[j];
			max_index = j;
		}

	array[max_index] = array[last_element_index];
	array[last_element_index] = -1;
	
	for (int i = last_element_index-1; i >= 0; i--)
		heapify(i);
}

int Heap::find_last_element_index()
{
	for (int i = 0; i < 500; i++)
		if(array[i] == -1)
			return (i-1);
}

void Heap::insert(int x)
{
	for(int i = 0; i < 500; i++)
	{
		if(array[i] == -1)
		{
			array[i] = x;
			break;
		}
	}
	heapify(search(x));
}

void Heap::heapify(int x)
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
		heapify(parent_index);
	}	
}
int Heap::search(int x)
{
    for(int i = 0; i < 500; i++)
        if (array[i] == x) return i;
    return -1;
}

void Heap::levelorder()
{	
	if(array[0] == -1)
		cout << "Heap is empty, cannot traverse.\n";
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

void Heap::deleteMin()
{
	if(array[0] == -1)
		cout << "Heap is empty, cannot delete.";
	else	
		remove(array[0]);
}

void Heap::remove(int value)
{
	int value_index = search(value);
	if(value_index == -1)
	{
		cout << "Value not found on heap, cannot delete. \n";
		return;
	}
	int last_element_index = find_last_element_index();
	array[value_index] = array[last_element_index];
	array[last_element_index] = -1;
	
	goDown(value_index);	
	for (int i = last_element_index-1; i >= 0; i--)
		heapify(i);
}

void Heap::goDown(int hole_index)
{
	if(!hasChildren(hole_index)) return;
	
	int children_index[5];
	for (int i = 0; i <= 4; i++)
	{
		children_index[i] = -1;
		if(array[(5*hole_index + i + 1)] != -1)
			children_index[i] = (5*hole_index + i + 1);
	}
	
	int temp;

	for(int j = 0; j < 5; j++)
	{
		if(children_index[j] != -1 && array[children_index[j]] < array[hole_index])
		{
			temp = array[children_index[j]];
			array[children_index[j]] = array[hole_index];
			array[hole_index] = temp;
			goDown(hole_index);
		} 
	}
}