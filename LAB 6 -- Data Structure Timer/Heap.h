/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
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

	private:
        int array[500];
        int size;
	void remove(int value, bool all);
};

#endif
