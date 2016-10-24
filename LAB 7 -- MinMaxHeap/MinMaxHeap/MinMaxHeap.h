/**
*	@file :	
*	@author :  Victor Berger da Silva
*	@date :	
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
    
    
private:
    int size;
    int array[500000];
    
    void trickleDown();
    
};

#endif
