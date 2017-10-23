/**
*	@file : Heap.cpp
*	@author :  Victor Berger da Silva
*	@date : Oct 02 2016
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

void Heap::builder(int a[], int b) /// CONSTRUCTS THE INITIAL HEAP, ONLY CALLED ONCE
{
    for(int i = 0; i < 500; i++)
		array[i] = -1;

	for(int i = 0; i < b; i++)
		array[i] = a[i];

	int temp;

	for (int j = 0; j < 500; j++)
		if(!hasChildren(j+1))
		{
			temp = j;
			break;
		}

	for (int a = temp; a >= 0; a--)
		heapify(a);

	for (int a = temp; a >= 0; a--)
		goDown(a);
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
		goingUp(i);
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
		if(array[i] == -1)
		{
			array[i] = x;
			goingUp(i);
			break;
		}
}

void Heap::heapify(int x) // GOING UP
{

	int element = array[x];           		    // x --> index, element --> array[index]
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
    for(int i = 0; i < 500; i++)
        if (array[i] == x) return i;
    return -1;
}

void Heap::levelorder() // prints tree-like diagram
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

void Heap::deleteMin() /// calls remove() on root, without removing duplicates
{
	if(array[0] == -1)
		cout << "Heap is empty, cannot delete.";
	else
		remove(array[0],0);
}

///PRIVATE:
void Heap::remove(int value, bool all) /// if all == 1, will remove all duplicates
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
	if(all)
		while(search(value) != -1)
			remove(value);
}

void Heap::remove(int value) // calls private remove, with specific flag for duplicates
{
	remove(value, 1);
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
