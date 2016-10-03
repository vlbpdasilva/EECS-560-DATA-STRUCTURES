CC = g++
FLAGS = -std=c++11 -c

lab6: main.o Heap.o BST.o RNG_Timer.o Queue.o Node.o Timer.o
	$(CC) -std=c++11 -g main.o Heap.o BST.o RNG_Timer.o Queue.o Node.o Timer.o -o lab6

main.o: main.cpp Heap.h Heap.cpp BST.h BST.cpp RNG_Timer.h RNG_Timer.cpp Queue.h Queue.cpp Node.h Node.cpp Timer.cpp
	$(CC) -std=c++11 -g -c main.cpp
	
Heap.o: Heap.cpp
	$(CC) $(FLAGS) Heap.cpp

BST.o: BST.cpp
	$(CC) $(FLAGS) BST.cpp
	
RNG_Timer.o: RNG_Timer.cpp
	$(CC) $(FLAGS) RNG_Timer.cpp
	
Queue.o: Queue.cpp
	$(CC) $(FLAGS) Queue.cpp
	
Node.o: Node.cpp
	$(CC) $(FLAGS) Node.cpp
	
Timer.o: Timer.cpp
	$(CC) $(FLAGS) Timer.cpp

clean: rm *.o lab6
	clean done
