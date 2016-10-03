lab6: main.o Heap.o BST.o RNG_Timer.o Queue.o Node.o Timer.o
	g++ -std=c++11 -g main.o Heap.o BST.o RNG_Timer.o Queue.o Node.o -o lab5

main.o: main.cpp Heap.h Heap.cpp BST.h BST.cpp RNG_Timer.h RNG_Timer.cpp Queue.h Queue.cpp Node.h Node.cpp Timer.cpp
	g++ -std=c++11 -g -c main.cpp
	
Heap.o: Heap.cpp
	g++ -std=c++11 -c Heap.cpp

BST.o: BST.cpp
	g++ -std=c++11 -c BST.cpp
	
RNG_Timer.o: RNG_Timer.cpp
	g++ -std=c++11 -c RNG_Timer.cpp
	
Queue.o: Queue.cpp
	g++ -std=c++11 -c Queue.cpp
	
Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp
	
Timer.o: Timer.cpp
	g++ -std=c++11 -c Node.cpp

clean: rm *.o lab5
	clean done
