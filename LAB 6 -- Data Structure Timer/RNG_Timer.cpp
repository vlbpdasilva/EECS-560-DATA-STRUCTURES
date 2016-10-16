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
   insertTimer();
   delete n_values;
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
	double choice = (double)rand() / (RAND_MAX);
	int times = 0.1 * n;
	int randomInt;
	Timer myTimer;

	/**if(choice <= 1)
	{

		cout << "### Time to perform deletemin operations:\n  BST: ";
		
		myTimer.start();		
		for(int i = 0; i < times; i++)
			myBST->deleteMin();
		myTimer.printTime(myTimer.stop()); 
		
	  	cout << "  Heap: ";
		
 		myTimer.start();
		for(int i = 0; i < times; i++)
			myHeap->deleteMin();
		myTimer.printTime(myTimer.stop());  

	}
	else **/if (choice <= 1)
	{
		cout << "### Time to perform deletemax operations:\n BST: ";
		
		myTimer.start();		
		for(int i = 0; i < times; i++)
			myBST->deleteMax();
                
		myTimer.printTime(myTimer.stop());
		
	 	cout << "  Heap: ";
		
                myTimer.start();
		for(int i = 0; i < times; i++)
			myHeap->deleteMax();
		myTimer.printTime(myTimer.stop());  
		
	}
	else if(choice > 4)
	{
		randomInt = rand() % (4 * n) + 1;
		cout << "### Time to perform remove operations:\n BST: ";
		
		myTimer.start();	
		for(int i = 0; i < times; i++)
			myBST->remove(randomInt);
		myTimer.printTime(myTimer.stop());
		
	 	cout << "  Heap: ";
		
  		myTimer.start();
		for(int i = 0; i < times; i++)
			myHeap->deleteMin();
		myTimer.printTime(myTimer.stop());  
		
	}
	else
	{
		randomInt = rand() % (4 * n) + 1;
		cout << "### Time to perform insert operations:\n BST: ";
		
		myTimer.start();		
		for(int i = 0; i < times; i++)
			myBST->insert(randomInt);
		myTimer.printTime(myTimer.stop());
		
	 	cout << "  Heap: ";
		
  		myTimer.start();
		for(int i = 0; i < times; i++)
			myHeap->deleteMin();
		myTimer.printTime(myTimer.stop());  
		
	}
}
