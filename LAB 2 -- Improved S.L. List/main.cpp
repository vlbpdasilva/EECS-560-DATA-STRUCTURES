/**
*	@file : main.cpp
*	@author :  Victor Berger da Silva
*	@date : Aug 29 2016
*	Purpose: main file, controls Node and List classes
	Single Linked List --- EECS 560 -- prof. Kong/TA: Hajiarbabi --- LAB 2
*/

#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

/*
*	Helper method, prints menu. 
*/
void print()
{
	std::cout<< "------------------" << std::endl;
	std::cout << "Please choose one of the following commands: " << std::endl;
	std::cout << "1 - insert" << std::endl;
	std::cout << "2 - delete" << std::endl;
	std::cout << "3 - reverse" << std::endl;
        std::cout << "4 - concatenate" << std::endl;
        std::cout << "5 - print" << std::endl;
        std::cout << "6 - exit" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Selection: ";
}

/*
 * Operates menu using print() method.
 * Inserts values from data.txt
 * Controls List and Node classes
 */
int main()
{  
	int number;
        int number2;     // dummy variables for contents of data.txt
	int selection;   // menu selection picked by user
	int insertValue; // value to be insert into list
	int deleteValue; // value to be deleted from list
	
	List* myList = new List();
        List* myList2 = new List();

	std::ifstream myFile;	
	myFile.open("data.txt");
        while(myFile >> number)    // inserts contents of data.txt into list
            myList -> insert(number);
        
        std::ifstream myFile2;	
	myFile2.open("data2.txt");
	while(myFile2 >> number2)    // inserts contents of data2.txt into list2
            myList2 -> insert(number2);
	
	do
	{
		print();
		std::cin >> selection;	// expects an int. 
			
		switch(selection)
                {
                    case 1: // INSERT
		
			std::cout << "Enter value to insert: ";
			std::cin >> insertValue;
			
			if(myList-> search(insertValue))
				std::cout << "Value already exists in the list. Try again." << std::endl;
			else myList->insert(insertValue);
                        break;
                        
                    case 2:  // ERASE
                        
                        std::cout << "Enter value to delete: ";
                        std::cin >> deleteValue;
                        myList->erase(deleteValue);
                        break;
                        
                    case 3:   // REVERSE
                        
                        myList->reverse();
                        break;
                    
                    case 4:  
                        myList->concatenate(myList2);
                        break;                        
                        
                    case 5:  // PRINT
			myList-> print();
                        break;
			
                    case 6:  // EXIT
			std::cout<< "Program exit" << std::endl;
                        break;
		
                    default: // USER ENTERED SOMETHING ELSE
			std::cout << "Invalid input, try again" << std::endl;
                        break;
                }       
		
	}
	while(selection!=6);	// controls do-while loop, quits if selection = 6
	
        myFile.close();
	delete myList;
        delete myList2;
	
	return 0;  
  
}
