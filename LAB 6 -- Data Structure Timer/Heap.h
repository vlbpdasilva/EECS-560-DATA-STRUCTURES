/**
*	@file :	Heap.h
*	@author :  Victor Berger da Silva
*	@date :	Oct 17 2016
*
*/


#ifndef HEAP_H
#define HEAP_H

class Heap

{
	public:
        Heap();
        ~Heap();
        void builder();
        void heapify(int x);
        int  search(int x);
        void levelorder();
	void insert(int x);
	void deleteMin();
	void goDown(int hole_index);
	bool hasChildren(int a);
	void deleteMax();
	void remove(int value);
        void goingUp(int x);
        int search(int x, int beg);

	private:
        int array[500000];
        int size;
	void remove(int value, bool all, int value_index);
};

#endif
