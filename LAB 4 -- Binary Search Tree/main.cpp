/**
*	@file : main.cpp
*	@author :  Victor Berger da Silva
*	@date : 
 
*/

#include "BST.h"
#include "Node.h"
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
    cout << "Please choose one of the following commands:\n1. Insert\n2. Remove\n3. DeleteMin\n4. DeleteMax\n";
    cout << "5. Pre-Order Traversal\n6. In-order Traversal\n7. Level-Order Traversal\n8. Exit\nSelection: ";
}

/*
 * Operates menu using print() method.
 * Inserts values from data.txt
 */
int main(int argc, char** argv)
{
    int number;
    int selection;
    int toInsert;
    int toRemove;
	
    BST* myBST = new BST();
    
    std::ifstream myFile;	
    myFile.open("data.txt");
    while(myFile >> number)    
        myBST->insert(number);
    
    do
    {
        print();
        cin >> selection;
        
        switch(selection)
        {
            case 1: 
                cout << "Please insert the number that you want to be inserted in the tree:\nSelection: ";
                cin >> toInsert;
                myBST->insert(toInsert);
                break;
            case 5: 
                myBST->preOrder();
                break;
            case 6:
                myBST->inOrder();
                break;
        }
    }
    while(selection != 8);
}
