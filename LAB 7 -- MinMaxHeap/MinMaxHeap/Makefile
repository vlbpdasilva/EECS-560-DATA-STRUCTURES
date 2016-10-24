lab7: main.o MinMaxHeap.o 
	g++ -std=c++11 -g main.o MinMaxHeap.o -o lab7

main.o: main.cpp MinMaxHeap.h MinMaxHeap.cpp 
	g++ -std=c++11 -g -c main.cpp
	
MinMaxHeap.o: MinMaxHeap.cpp
	g++ -std=c++11 -c MinMaxHeap.cpp	

clean: rm *.o lab7
	clean done
