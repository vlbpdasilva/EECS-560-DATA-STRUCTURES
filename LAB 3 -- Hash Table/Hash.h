/**
*	@file :
*	@author :  Victor Berger da Silva
*	@date :
*
*/


#ifndef HASH_H
#define HASH_H


class Hash

{
	public:
	Hash(int k);
	void print();
	void insert(int toInsert);
	bool contains(int x);
	bool isfull();
	void hash(int x);


	private:

	int hashmod;
	int hashres;
	int* table;
	bool* flags;

};

#endif
