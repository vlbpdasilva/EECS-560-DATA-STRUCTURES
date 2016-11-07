CC = g++
FLAGS = -std=c++11 -c

lab9: main.o LeftistHeap.o  SkewHeap.o RNG_Timer.o Timer.o Node.o
	$(CC) -std=c++11 -g main.o LeftistHeap.o  SkewHeap.o RNG_Timer.o Timer.o Node.o -o lab9

main.o: main.cpp LeftistHeap.h LeftistHeap.cpp SkewHeap.h SkewHeap.cpp RNG_Timer.h RNG_Timer.cpp Timer.cpp Node.h Node.cpp
	$(CC) -std=c++11 -g -c main.cpp
	
LeftistHeap.o: LeftistHeap.cpp
	$(CC) $(FLAGS) LeftistHeap.cpp
	
SkewHeap.o: SkewHeap.cpp
	$(CC) $(FLAGS) SkewHeap.cpp
	
RNG_Timer.o: RNG_Timer.cpp
	$(CC) $(FLAGS) RNG_Timer.cpp
	
Timer.o: Timer.cpp
	$(CC) $(FLAGS) Timer.cpp
	
Node.o: Node.cpp
	$(CC) $(FLAGS) Node.cpp

clean: rm *.o lab9
	clean done
