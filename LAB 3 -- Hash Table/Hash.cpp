/**
*	@file :
*	@author :  Victor Berger da Silva
*	@date :
*
*/

#include "Hash.h"
#include <iostream>


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

bool Hash::isfull()
{
	for (int b = 0; b < hashmod; b++)
	{
		if (table[b] == -1)
			return 0;
	}
	
	return 1;
}
void Hash::insert(int toInsert)
{
	if(isfull())
		std::cout << "Table is already full, cannot insert element." << std::endl;

	else if(contains(toInsert))
		std::cout << "Hash table already contains element " << toInsert << ". Cannot insert." <<std::endl;
	
	else
	{
		hashres = toInsert % hashmod;
		if(table[hashres] == -1)
			table[hashres] = toInsert;
		
		else 
			table[hash(toInsert)] = toInsert;			
	}
}	

int Hash::hash(int x)
{
	int quadratic;
	for(int i = 1; i < hashmod; i++)
	{
		quadratic = ((x % hashmod) + (i*i)) % hashmod;
		if(table[quadratic] == -1)
			return quadratic;
	}		 
}
/**
void Hash::remove(int a)
{ 	
	if(!contains(a))
		std::cout << "Element " << a << " does not exist in table, cannot remove." << std::endl;
	else
	{
		table[index] = -1;
		flags[index] = 1;		
		std::cout << "Element " << a << " successfully removed from table." << std::endl;
	}
}
**/
bool Hash::contains(int f)      			/// TO-DO: FIX REMOVE AND CONTAINS METHODS
{
	for(int p = 0; p < hashmod; p++)
		if (table[p] == f)
			return 1;
	return 0;  
	
 	/* int searched = f % hashmod;
	if(table[searched] == f)
		return 1; 
	else if(flags[searched] == 0)
		contains(hash(f));
	
	return 0; */
}

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
