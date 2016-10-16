#ifndef RNG_TIMER_H
#define RNG_TIMER_H

#include "BST.h"
#include "Heap.h"

class RNG_Timer

{
	public:
        RNG_Timer();
		~RNG_Timer();


	private:
        int* n_values;
		void insertTimer();
		void operationTimer(int n, BST* myBST, Heap* myHeap);
};

#endif
