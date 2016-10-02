/**
*	@file : main.cpp
*	@author :  Victor Luiz Berger da Silva
*	@date : 
 
*/

#include "Heap.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
*	Helper method, prints menu. On a loop called from main().
*/
void print()
{
    cout << "\n------------------------\n";
    cout << "Please choose one of the following commands:\n1. Insert\n2. DeleteMin\n3. DeleteMax\n4. Remove\n";
    cout << "5. Level-Order Traversal\n6. Exit\nSelection: ";
}

/*
 * Operates menu using print() method.
 * Inserts values from data.txt
 */
int main(int argc, char** argv)
{
    int selection;
    int number;
    int elements;
	int toInsert;
	int toDelete;
    
    ifstream myFile;
    myFile.open("data.txt");
    
    while(myFile >> number)
        elements++;

    int array[elements];
    
    myFile.clear();
    myFile.seekg(0, ios::beg);
    
    Heap* myHeap = new Heap();
    
    for(int i = 0; i < elements; i++)
    {
        myFile >> number;
        array[i] = number;
    }

    myHeap->builder(array,elements);
    
    do
    {
        print();
        cin >> selection;
        
        switch(selection)
        {
            case 1:
				cout << "Please insert the number that you want to be inserted in the heap:\n";
				cin >> toInsert;
                myHeap->insert(toInsert);     
                break;
			case 2:
				myHeap->deleteMin();
				break;
			case 3:
				myHeap->deleteMax();
				break;
			case 4:
				cout << "Please insert the number that you want to remove from the 5-Heap\nSelection: ";
				cin >> toDelete;
				myHeap->remove(toDelete);
				break;
            case 5:
                myHeap->levelorder();
                break;
            case 6:
                cout << "Bye bye.\n";
                break;
            default:
                cout << "Invalid input, try again.\n";
                break;
        }
    }
    while(selection != 6);
	
	myFile.close();
	delete myHeap;
        
    return 0;
}