#include "RNG_Timer.h"
#include "MinMaxHeap.h"
#include "Heap.h"
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
    opTimerHeap = 0;
    opTimerMinMaxHeap = 0;
    insertTimer();
    delete n_values;
    cout << endl << endl;
}

RNG_Timer::~RNG_Timer()
{
}

void RNG_Timer::insertTimer()
{
    Heap* myHeap = new Heap();
    MinMaxHeap* myMinMaxHeap = new MinMaxHeap();
    Timer myTimer;
	
    srand(time(NULL));			
    double totalTimeHeap = 0;
    double totalTimeMinMaxHeap = 0;
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
                myHeap->insert(myNum);
            }
            totalTimeHeap += myTimer.stop();
            cout << "\n  Min-5-Heap: ";
            myTimer.printTime(myTimer.stop());
			
            srand(seeds + 1);
            myTimer.start();
            for(int counter = 1; counter <= n_values[values]; counter++) 
            {
                myNum = rand() % (4 * n_values[values]) + 1;
                myMinMaxHeap->insert(myNum);
            }
            totalTimeMinMaxHeap += myTimer.stop();
            cout << "  Min Max Heap: ";
            myTimer.printTime(myTimer.stop());
            
            operationTimer(n_values[values], myHeap, myMinMaxHeap);
			
            delete myHeap;
            myHeap = new Heap();
            delete myMinMaxHeap;
            myMinMaxHeap = new MinMaxHeap();
            
        }
		
        totalTimeHeap = totalTimeHeap / 5;
        totalTimeMinMaxHeap = totalTimeMinMaxHeap / 5;
        cout << "\n->Min-5-Heap time average between seeds for n = " << n_values[values] << ": " << totalTimeHeap << " seconds\n";
        cout << "->Min Max Heap time average between seeds for n = " << n_values[values] << ": " << totalTimeMinMaxHeap << " seconds\n"; 

    }	
    delete myHeap;
    delete myMinMaxHeap;
}

void RNG_Timer::operationTimer(int n, Heap* myHeap, MinMaxHeap* myMinMaxHeap)
{
    srand(time(NULL));
    double choice;
    int times = 0.1 * n;
    int randomInt;
    Timer myTimer;

    for(int i = 0; i < times; i++)
    {    
        choice = (double)rand() / (RAND_MAX);
        if(choice < 0.25)
        {
            myTimer.start();		
            myHeap->deleteMin();
            opTimerHeap += myTimer.stop();                    
            myTimer.start();
            myMinMaxHeap->deleteMin();
            opTimerMinMaxHeap += myTimer.stop();
        }
        else if (choice < 0.5)
        { 
            myTimer.start();		
            myHeap->deleteMax();
            opTimerHeap += myTimer.stop();
            myTimer.start();
            myMinMaxHeap->deleteMax();
            opTimerMinMaxHeap += myTimer.stop();
        }
        else
        { 
            randomInt = rand() % (4 * n) + 1;   
            myTimer.start();		
            myHeap->insert(randomInt);
            opTimerHeap += myTimer.stop();
            myTimer.start();
            myMinMaxHeap->insert(randomInt);
            opTimerMinMaxHeap += myTimer.stop();
        }
    }  
    
    cout << "Time for " << times << " insertion/deletion operations on Min-5-Heap: "<< opTimerHeap << endl;
    cout << "Time for " << times << " insertion/deletion operations on Min Max Heap: "<< opTimerMinMaxHeap << endl;
    
    opTimerHeap = 0;
    opTimerMinMaxHeap = 0;
}
