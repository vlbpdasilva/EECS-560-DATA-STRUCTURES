/**
*	@file : main.cpp
*	@author :  Victor Berger da Silva
*	@date : Nov 06 2016

*/

#include "LeftistHeap.h"
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
*	Helper method, prints menu. On a loop called from main().
*/
void print()
{
    cout << "\n------------------------\n";
    cout << "Please choose one of the following commands:\n1. Insert\n2. DeleteMin\n3. Pre-Order Traversal\n";
    cout << "4. In-Order Traversal\n5. Level-Order Traversal\n6. Exit\nSelection: ";
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

	    LeftistHeap* myLeftistHeap = new LeftistHeap();

	    std::ifstream myFile;
	    myFile.open("data.txt");
	    while(myFile >> number)
	        myLeftistHeap->insert(number);

	    do
	    {
	        print();
	        cin >> selection;

	        switch(selection)
	        {
	            case 1:
	                cout << "Please enter the number that you want inserted to the heap:\nSelection: ";
	                cin >> toInsert;
	                myLeftistHeap->insert(toInsert);
	                break;
                    case 2:
                        myLeftistHeap->deleteMin();
                        break;
                    case 3:
                        myLeftistHeap->preOrder();
                        break;
                    case 4:
                        myLeftistHeap->inOrder();
                        break;
                    case 5:
                        myLeftistHeap->levelOrder();
                        break;
                    case 6:
                        cout <<"Bye bye!" << endl;
                        break;
	            default:
	                cout <<"Invalid input, try again.\n";
	                break;
	        }
	    }
	    while(selection != 6);

	    myFile.close();
	    delete myLeftistHeap;

	    return 0;
}
