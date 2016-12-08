#include "RNG_Timer.h"
#include "LeftistHeap.h"
#include "MST.h"
#include "Timer.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

RNG_Timer::RNG_Timer()
{
    randCounter = 1;
    int dummy = 500;
    while(dummy <= 4000)
    {
        graphTimer(dummy);
        dummy *= 2;
    }
}

RNG_Timer::~RNG_Timer()
{
}

void RNG_Timer::graphBuilder(int a, MST* myMST)
{
    int edgeCost;
    srand(randCounter);
	
    for(int k = 0; k < a; ++k)
        for(int n = k; n < a; ++n)
        {
            if(n == k) continue;
            value = ((double)rand() / (RAND_MAX));
            if(value < 0.5) edgeCost = 0;
            else edgeCost = rand() % (4 * a) + 1;				
            myMST->build(k,n,edgeCost);		
            myMST->build(n,k,edgeCost);
        }
}

void RNG_Timer::graphTimer(int a)
{
    MST* myMST = new MST(a);
    KruskalTime = 0;
    PrimTime = 0;
    Timer myTimer;	
	
    for(int i = 0; i < 5; ++i)
    {
        ++randCounter;		
            
        cout << "\n### For n = " << a << ", seed #" << i+1 <<":\n";
        graphBuilder(a, myMST);
		
        myTimer.start();
        cout << "Cost " << myMST->Kruskal() <<" for Kruskal's algorithm, time: ";
        KruskalTime += myTimer.stop();
        myTimer.printTime(myTimer.stop());
                    
        myTimer.start();
        cout << "Cost " << myMST->Prim() <<" for Prim's algorithm, time: ";
        PrimTime += myTimer.stop();
        myTimer.printTime(myTimer.stop());		
				
        delete myMST;
        myMST = new MST(a);
    }
		
    KruskalTime /= 5;
    PrimTime /= 5;
	
    cout << "\n->Kruskal's algorithm average time for " << a <<" values: " << KruskalTime << endl;
    cout << "->Prim's algorithm average time for " << a << " values: " << PrimTime << endl;
	
    delete myMST;
}
