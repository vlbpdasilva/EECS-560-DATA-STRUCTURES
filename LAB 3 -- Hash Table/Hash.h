/**
*	@file :	Hash.h
*	@author :  Victor Berger da Silva
*	@date :	September 18, 2016
*	Header file for Hash class
*/


#ifndef HASH_H
#define HASH_H


class Hash

{
	public:
	
	Hash(int k);
	~Hash();
	void print();
	void insert(int toInsert);
	bool contains(int x);
	int search(int x);
	bool isfull();
	int hash (int x, int value);
	void remove(int a);


	private:

	int hashmod;
	int hashres;
	int* table;
	bool* flags;

};

#endif
