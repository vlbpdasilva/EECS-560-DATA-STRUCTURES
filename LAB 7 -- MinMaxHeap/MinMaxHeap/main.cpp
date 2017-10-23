/**
*	@file : main.cpp
*	@author :  Victor Berger da Silva
*	@date : Oct 30 2016
*/

#include "MinMaxHeap.h"
#include <iostream>
#include <fstream>

/*
*	Helper method, prints menu.
*/
void print()
{
    std::cout << "\n----------------\nPlease choose one of the following commands: \n1 - Insert\n2 - DeleteMin\n3 - DeleteMax";
    std::cout << "\n4 - Level Order Traversal\n5 - Exit\nSelection: ";
}

/*
 * Operates menu using print() method.
 * Inserts values from data.txt
 */
int main()
{
	int selection, insertValue, size, number, counter;

	std::ifstream myFile;
	myFile.open("data.txt");
    	while(myFile >> number)
            size++;

	int values[size];

	myFile.clear();
    	myFile.seekg(0, myFile.beg);

    	while (myFile >> number)
	{
            values[counter] = number;
            counter++;
    	}

	myFile.close();

	MinMaxHeap* myMinMaxHeap = new MinMaxHeap();
        myMinMaxHeap->build(values, size);

	do
	{
            print();
            std::cin >> selection;

            switch(selection)
            {
                case 1:
                    std::cout << "Enter value to insert: ";
                    std::cin >> insertValue;
                    myMinMaxHeap->insert(insertValue);
                    break;
                case 2:
                    myMinMaxHeap->deleteMin();
                    break;
                case 3:
                    myMinMaxHeap->deleteMax();
                    break;
                case 4:
                    std::cout << "Level order:";
                    myMinMaxHeap->levelOrder();
                    break;
                case 5:
                    std::cout<< "Program exit\n";
                    break;
                default:
                    std::cout << "Invalid input, try again\n";
                    break;
            }

	}
	while(selection!=5);
        delete myMinMaxHeap;
	return 0;
}
