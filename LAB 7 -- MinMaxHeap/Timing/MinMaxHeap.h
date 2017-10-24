/**
*	@file :	MinMaxHeap.h
*	@author :  Victor Berger da Silva
*	@date :	Oct 30 2016
*
*/


#ifndef MIN_MAX_HEAP_H
#define MIN_MAX_HEAP_H

class MinMaxHeap
{

public:
    MinMaxHeap();
    ~MinMaxHeap();
    void build(int values[], int sizeBuilder);
    void levelOrder();
    void deleteMin();
    void deleteMax();
    void insert(int a);

private:
    int size;
    int array[500000];
    void trickleDown();
    void bubbleUp(int index);
};

#endif
