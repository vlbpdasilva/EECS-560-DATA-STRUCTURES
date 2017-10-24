/**
*	@file :	Heap.h
*	@author :  Victor Berger da Silva
*	@date : Oct 02 2016
*
*/


#ifndef HEAP_H
#define HEAP_H

class Heap

{
	public:
        Heap();
        ~Heap();
        void builder(int a[], int b);
        void heapify(int x);
        int  search(int x);
        void levelorder();
		void insert(int x);
		void deleteMin();
		void goDown(int hole_index);
		bool hasChildren(int a);
		void deleteMax();
		void remove(int value);
		int find_last_element_index();
		void goingUp(int x);

	private:
        int array[500];
		void remove(int value, bool all);
};

#endif
