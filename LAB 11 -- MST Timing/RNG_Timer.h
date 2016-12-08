#ifndef RNG_TIMER_H
#define RNG_TIMER_H

#include "LeftistHeap.h"
#include "MST.h"

class RNG_Timer

{
	public:
        RNG_Timer();
        ~RNG_Timer();

	private:
        void graphTimer(int a), graphBuilder(int a, MST* myMST);
        double value, KruskalTime, PrimTime;
        int randCounter;
};

#include "RNG_Timer.hpp"
#endif

