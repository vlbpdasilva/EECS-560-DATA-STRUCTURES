#ifndef RNG_TIMER_H
#define RNG_TIMER_H

#include "MinMaxHeap.h"
#include "Heap.h"

class RNG_Timer

{
	public:
        RNG_Timer();
        ~RNG_Timer();


	private:
        int* n_values;
        void insertTimer();
        void operationTimer(int n, Heap* myHeap, MinMaxHeap* myMinMaxHeap);
        double opTimerHeap;
        double opTimerMinMaxHeap;
};

#endif
