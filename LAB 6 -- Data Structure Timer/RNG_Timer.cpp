#include "RNG_Timer.h"
#include "BST.h"
#include "Heap.h"
#include "Timer.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

RNG_Timer::RNG_Timer()
{
   int n_values[] = {50000, 100000, 200000, 400000};   
   
   BST* myBST = new BST();
   Heap* myHeap = new Heap();   
   Timer* myTimer = new Timer();
   
   
}
   
