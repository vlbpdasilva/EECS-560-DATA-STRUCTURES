/**
*	@file : main.cpp
*	@author :  Victor Berger da Silva
*	@date :
*	Purpose:
*/

#include "Hash.h"
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
	cout << "Please choose one of the following commands:\n1. Insert\n2. Delete\n3. Print\n4. Exit\n";
}

/*
 * Operates menu using print() method.
 * Inserts values from data.txt
 */
int main()
{
	int selection;
	int number;
	int headOfInput;
	int toInsert;
	int toDelete;

	ifstream myFile;	
	myFile.open("data.txt");
	myFile >> headOfInput;
	Hash myHash(headOfInput);

	while(myFile >> number)
		myHash.insert(number);

	do
	{
		print();
		cout << "Selection: ";
		cin >> selection;

		switch(selection)
		{
			case 1: // INSERT
			cout << "Which number do you want to insert into the hash table?\nSelection: ";
			cin >> toInsert;
			myHash.insert(toInsert);
			break;
/* 			
			case 2: // DELETE/REMOVE
			cout << "Which number do you want to remove from the hash table?\nSelection: ";
			cin >> toDelete;
			myHash.remove(toDelete);
			break; */
			
			case 3: // PRINT
	    	myHash.print();
			break;

			case 4: // EXIT
			cout << "Program exit.\n";
			break;
			
			case 5: 
			cout << "CONTAINS: 5" << myHash.contains(5) << endl;
			cout << "CONTAINS: 56" << myHash.contains(56) << endl;
			cout << "CONTAINS: 10" << myHash.contains(10) << endl;
			cout << "CONTAINS: 42" << myHash.contains(42) << endl;
			break;
			
			default: // USER ENTERED INTEGER OTHER THAN 1, 2, 3, 4
			cout << "Invalid input, try again.\n";
			break;  
		}
	}
	while(selection != 4);

	myFile.close();
	return 0;

}
