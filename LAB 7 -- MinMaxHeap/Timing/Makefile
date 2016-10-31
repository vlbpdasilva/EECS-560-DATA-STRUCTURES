CC = g++
FLAGS = -std=c++11 -c

lab7: main.o MinMaxHeap.o RNG_Timer.o Timer.o Heap.o
	$(CC) -std=c++11 -g main.o MinMaxHeap.o RNG_Timer.o Timer.o Heap.o -o lab7

main.o: main.cpp MinMaxHeap.h MinMaxHeap.cpp RNG_Timer.h RNG_Timer.cpp Timer.cpp Heap.h Heap.cpp
	$(CC) -std=c++11 -g -c main.cpp
	
MinMaxHeap.o: MinMaxHeap.cpp
	$(CC) $(FLAGS) MinMaxHeap.cpp
	
RNG_Timer.o: RNG_Timer.cpp
	$(CC) $(FLAGS) RNG_Timer.cpp
	
Timer.o: Timer.cpp
	$(CC) $(FLAGS) Timer.cpp
	
Heap.o: Heap.cpp
	$(CC) $(FLAGS) Heap.cpp

clean: rm *.o lab7
	clean done
