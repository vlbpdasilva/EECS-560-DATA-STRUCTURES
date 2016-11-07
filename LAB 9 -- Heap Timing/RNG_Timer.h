#ifndef RNG_TIMER_H
#define RNG_TIMER_H

#include "LeftistHeap.h"
#include "SkewHeap.h"

class RNG_Timer

{
	public:
        RNG_Timer();
        ~RNG_Timer();


	private:
        int* n_values;
        void insertTimer();
        void operationTimer(int n, LeftistHeap* myLeftistHeap, SkewHeap* mySkewHeap);
        double opTimerLeftistHeap;
        double opTimerSkewHeap;
};

#endif
