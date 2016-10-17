#include "RNG_Timer.h"
#include "BST.h"
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
    opTimerBST = 0;
    opTimerHeap = 0;
    insertTimer();
    delete n_values;
    std::cout << std::endl << std::endl;
}

RNG_Timer::~RNG_Timer()
{
}

void RNG_Timer::insertTimer()
{
    Heap* myHeap = new Heap();
    BST* myBST = new BST();  
    Timer myTimer;
	
    srand(time(NULL));		
    double totalTimeBST = 0;	
    double totalTimeHeap = 0;
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
                myBST->insert(myNum);
            }
            totalTimeBST += myTimer.stop();
            cout << "\n  BST: ";
            myTimer.printTime(myTimer.stop());
			
            srand(seeds + 1);
            myTimer.start();
            for(int counter = 1; counter <= n_values[values]; counter++) 
            {
                myNum = rand() % (4 * n_values[values]) + 1;
                myHeap->insert(myNum);
            }
            totalTimeHeap += myTimer.stop();
            cout << "  Heap: ";
            myTimer.printTime(myTimer.stop());
            
            operationTimer(n_values[values], myBST, myHeap);
			
            delete myBST;
            myBST = new BST();
            delete myHeap;
            myHeap = new Heap();
        }
		
        totalTimeBST = totalTimeBST / 5;
        totalTimeHeap = totalTimeHeap / 5;
        cout << "\n->BST time average between seeds for n = " << n_values[values] << ": " << totalTimeBST << " seconds\n";
        cout << "->Heap time average between seeds for n = " << n_values[values] << ": " << totalTimeHeap << " seconds\n";

    }	
    delete myBST;
    delete myHeap;
}

void RNG_Timer::operationTimer(int n, BST* myBST, Heap* myHeap)
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
            myBST->deleteMin();
            opTimerBST += myTimer.stop();                    
            myTimer.start();
            myHeap->deleteMin();
            opTimerHeap += myTimer.stop();
        }
        else if (choice < 0.5)
        { 
            myTimer.start();		
            myBST->deleteMax();
            opTimerBST += myTimer.stop();
            myTimer.start();
            myHeap->deleteMax();
            opTimerHeap += myTimer.stop();
        }
        else if(choice < 0.75)
        {
            randomInt = rand() % (4 * n) + 1;     
            myTimer.start();	
            myBST->remove(randomInt);
            opTimerBST += myTimer.stop();	
            myTimer.start();
            myHeap->remove(randomInt);
            opTimerHeap += myTimer.stop();
        }
        else
        { 
            randomInt = rand() % (4 * n) + 1;   
            myTimer.start();		
            myBST->insert(randomInt);
            opTimerBST += myTimer.stop();
            myTimer.start();
            myHeap->insert(randomInt);
        }
    }  
    
    cout << "Time for " << times << " insertion/deletion operations on BST: "<< opTimerBST << endl;
    cout << "Time for " << times << " insertion/deletion operations on Min-5-Heap: "<< opTimerHeap << endl;
    
    opTimerBST = 0;
    opTimerHeap = 0;
}
