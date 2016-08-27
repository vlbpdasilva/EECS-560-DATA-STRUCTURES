#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

void print()
{
		std::cout<< "------------------" << std::endl;
	std::cout << "Please choose one of the following commands: " << std::endl;
	std::cout << "1 - insert" << std::endl;
	std::cout << "2 - print" << std::endl;
	std::cout << "3 - exit" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Selection: ";
}

int main()
{  
	int number;
	int selection;
	int insertValue;
	
	List* myList = new List();

	std::ifstream myFile;
	
	myFile.open("data.txt");
	
	while(myFile >> number)
	{
		myList -> insert(number);
	}
	
	myFile.close();

	do
	{
		print();
		std::cin >> selection;	
			
		if(selection == 1)
		{
			std::cout << "Enter value to insert: ";
			std::cin >> insertValue;
			
			if(myList-> search(insertValue))
				std::cout << "Value already exists in the list. Try again." << std::endl;
			else
				myList->insert(insertValue);
		}	
		else if(selection == 2)
			myList -> print();
			
		else if(selection == 3)
			std::cout<< "Program exit" << std::endl;
		
		else
			std::cout << "Invalid input, try again" << std::endl;
		
	}
	while(selection!=3);	
	
	delete myList;
	
	return 0;  
  
}
