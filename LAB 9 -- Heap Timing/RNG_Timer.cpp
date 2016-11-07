#include "RNG_Timer.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "Timer.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

RNG_Timer::RNG_Timer()
{
    n_values = new int[4];
    n_values[0] = 50000;
    n_values[1] = 100000;
    n_values[2] = 200000;
    n_values[3] = 400000;
    opTimerLeftistHeap = 0;
    opTimerSkewHeap = 0;
    insertTimer();
    delete n_values;
    cout << endl << endl;
}

RNG_Timer::~RNG_Timer()
{
}

void RNG_Timer::insertTimer()
{
    LeftistHeap* myLeftistHeap = new LeftistHeap();
    SkewHeap* mySkewHeap = new SkewHeap();
    Timer myTimer;
	
    srand(time(NULL));			
    double totalTimeLeftistHeap = 0;
    double totalTimeSkewHeap = 0;
    int myNum;
    
    for (int values = 0; values < 4; values++)
    {	
        for(int seeds = 1; seeds <= 5; seeds++)
        {	
            cout << "\n### For n = " << n_values[values] <<", seed #" << seeds << ": ";
            srand(seeds + 1);
            myTimer.start();
            for(int counter = 1; counter <= n_values[values]; counter++) 
            {
                myNum = rand() % (4 * n_values[values]) + 1;
                myLeftistHeap->insert(myNum);
            }
            totalTimeLeftistHeap += myTimer.stop();
            cout << "\n  LeftistHeap: ";
            myTimer.printTime(myTimer.stop());
			
            srand(seeds + 1);
            myTimer.start();
            for(int counter = 1; counter <= n_values[values]; counter++) 
            {
                myNum = rand() % (4 * n_values[values]) + 1;
                mySkewHeap->insert(myNum);
            }
            totalTimeSkewHeap += myTimer.stop();
            cout << "  SkewHeap: ";
            myTimer.printTime(myTimer.stop());
            
            operationTimer(n_values[values], myLeftistHeap, mySkewHeap);
			
            delete myLeftistHeap;
            myLeftistHeap = new LeftistHeap();
            delete mySkewHeap;
            mySkewHeap = new SkewHeap();
            
        }
		
        totalTimeLeftistHeap = totalTimeLeftistHeap / 5;
        totalTimeSkewHeap = totalTimeSkewHeap / 5;
        cout << "\n->LeftistHeap time average between seeds for n = " << n_values[values] << ": " << totalTimeLeftistHeap << " seconds\n";
        cout << "->SkewHeap time average between seeds for n = " << n_values[values] << ": " << totalTimeSkewHeap << " seconds\n"; 

    }	
    delete myLeftistHeap;
    delete mySkewHeap;
}

void RNG_Timer::operationTimer(int n, LeftistHeap* myLeftistHeap, SkewHeap* mySkewHeap)
{
    srand(time(NULL));
    double choice;
    int times = 0.1 * n;
    int randomInt;
    Timer myTimer;

    for(int i = 0; i < times; i++)
    {    
        choice = (double)rand() / (RAND_MAX);
        if(choice < 0.5)
        {
            myTimer.start();		
            myLeftistHeap->deleteMin();
            opTimerLeftistHeap += myTimer.stop();                    
            myTimer.start();
            mySkewHeap->deleteMin();
            opTimerSkewHeap += myTimer.stop();
        }
        else
        { 
            randomInt = rand() % (4 * n) + 1;   
            myTimer.start();		
            myLeftistHeap->insert(randomInt);
            opTimerLeftistHeap += myTimer.stop();
            myTimer.start();
            mySkewHeap->insert(randomInt);
            opTimerSkewHeap += myTimer.stop();
        }
    }  
    
    cout << "Time for " << times << " insertion/deletion operations on LeftistHeap: "<< opTimerLeftistHeap << endl;
    cout << "Time for " << times << " insertion/deletion operations on SkewHeap: "<< opTimerSkewHeap << endl;
    
    opTimerLeftistHeap = 0;
    opTimerSkewHeap = 0;
}
