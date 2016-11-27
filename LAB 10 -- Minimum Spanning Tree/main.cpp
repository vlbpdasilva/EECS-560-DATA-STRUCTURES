/**
*	@file : main.cpp
*	@author :  Victor Berger da Silva
*	@date : 
*/

#include <iostream>
#include <fstream>

#include "MST.h"

using namespace std;

int main()
{  
    int numGraphs, size, copy;

    std::ifstream myFile("data.txt");        	
    if(!myFile.is_open())
    {
        cout << "\nERROR:\nFile 'data.txt' was not found, please try again. \n\n\n";
        return 1;
    }
	
    myFile >> numGraphs;      
    int graphSizes[numGraphs];	
    MST** myMST = new MST*[numGraphs];

    for(int i = 0; i < numGraphs; i++)
    {
        myFile >> size;
        myMST[i] = new MST(size);
            
        for(int a = 0; a < size; ++a)
            for(int b = 0; b < size; ++b)
            {
                myFile >> copy;
                myMST[i]->build(a,b,copy);
            }
    }

    
    
    myFile.close();
    return 0;    
}
