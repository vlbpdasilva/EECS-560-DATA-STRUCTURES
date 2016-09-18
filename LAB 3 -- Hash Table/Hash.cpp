/**
*	@file : Hash.cpp
*	@author :  Victor Berger da Silva
*	@date : September 18, 2016
*	CPP file for the Hash class
*/

#include "Hash.h"
#include <iostream>

/**
* 	Constructor, sets k as the mod for hashing
**/
Hash::Hash(int k)
{
	hashmod = k;
	table = new int[hashmod];
	flags = new bool[hashmod];
	
	for(int a = 0; a < hashmod; a++)
	{
		table[a] = -1;
		flags[a] = 0;
	}
}

// Destructor
Hash::~Hash()
{
	delete table;
	delete flags;	
}

// Returns true is table is full, false otherwise
bool Hash::isfull()
{
	for (int b = 0; b < hashmod; b++)
	{
		if (table[b] == -1)
			return 0;
	}
	
	return 1;
}

// Inserts value onto table, if possible
void Hash::insert(int toInsert)
{
	bool printMessage = 1;
	
	if(isfull())
	{
		printMessage = 0;
		std::cout << "Table is already full, cannot insert element " << toInsert << ".\n";
	}
	else if(contains(toInsert))
	{
		printMessage = 0;
		std::cout << "Hash table already contains element " << toInsert << ". Cannot insert.\n";		
	}
	else
	{
		hashres = toInsert % hashmod;
		if(table[hashres] == -1)
		{
			table[hashres] = toInsert;  // Element inserted at proper location
			return;
		}
		else 
		{
			int result;
					
			for (int i = 1; i < hashmod; i++)
			{	
				result = hash(toInsert, i);
				if (table[result] == -1)
				{
					table[result] = toInsert;  // Element inserted at later location
					return;
				}
			}
		}		
	}
	if(printMessage) 
		std::cout << "Could not find bucket to insert element " << toInsert << ".\n" ;
}	

// Returns results of hashing function for a certain value and index
int Hash::hash(int x, int value)  
{
	return ((x % hashmod) + (value*value)) % hashmod;	 
}

// Removes element from table, if possible
void Hash::remove(int a)
{ 	
	if(!contains(a))
		std::cout << "Element " << a << " does not exist in table, cannot remove." << std::endl;
	else
	{
		int index = search(a);
		table[index] = -1;
		flags[index] = 1;		
		std::cout << "Element " << a << " successfully removed from table." << std::endl;
	}
}

// Returns true if elements exists on table, false otherwise
bool Hash::contains(int f)      			
{
	int modres = f % hashmod;

	if(table[modres] == f)         // Element is found at proper bucket (index == element % hashmod)
		return 1;
	else if(table[modres] == -1 && !(flags[modres])); // Bucket was always empty
	else 
	{
		for (int i = 1; i < hashmod; i++)
		{
			if(table[hash(f,i)] == f)
				return 1;
		}
	}
	
	return 0;
} 

// Returns index of element on table, -1 if element was not found
int Hash::search(int x)
{
	int index = x % hashmod;
	
	if(table[index] == x)  // Element is found at proper bucket (index == element % hashmod)
		return index;
	for (int i = 1; i < hashmod; i++)
	{
		index = hash(x,i);
		if(table[index] == x)   // Element found at different bucket, after hashing
			return index;
	}
		
	return -1;	
}

// Traverses table and prints index, element, and flag
void Hash::print()
{
	std::cout << std::endl;
	for (int i = 0; i < hashmod; i++)
	{
		if((flags[i]) == 0)
			std::cout << i <<": " << table[i] <<" flag = false\n";
		else std::cout << i <<": " << table[i] <<" flag = true\n";
	}
}
