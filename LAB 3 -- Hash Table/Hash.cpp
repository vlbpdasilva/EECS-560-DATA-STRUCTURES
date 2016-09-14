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
	{
		std::cout << "Table is already full, cannot insert element." << std::endl;
		return;
	}

	else if(contains(toInsert))
	{
		std::cout << "Hash table already contains element " << toInsert << ". Cannot insert." <<std::endl;
		return;
	}
		
	hashres = toInsert % hashmod;

	if(table[hashres] == -1)
		table[hashres] = toInsert;

	else 
	{
		int i;
		int quadratic;
		for(i = 1; i < hashmod; i++)
		{
			quadratic = ((toInsert % hashmod) + (i*i)) % hashmod;
			if(table[quadratic] == -1)
				table[quadratic] = toInsert;
		}		
	}
}

bool Hash::contains(int f)
{
	for(int p = 0; p < hashmod; p++)
		if (table[p] == f)
			return 1;
	return 0;
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
