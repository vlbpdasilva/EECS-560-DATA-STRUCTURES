CC = g++
FLAGS = -std=c++11 -c

lab11: main.o Timer.o AdjList.o
	$(CC) -std=c++11 -g main.o Timer.o AdjList.o -o lab11

main.o: main.cpp LeftistHeap.h LeftistHeap.hpp RNG_Timer.h RNG_Timer.hpp Timer.cpp Node.h Node.hpp MST.h MST.hpp AdjList.h AdjList.cpp
	$(CC) $(FLAGS) -g main.cpp
	
Timer.o: Timer.cpp
	$(CC) $(FLAGS) Timer.cpp
	
AdjList.o: AdjList.cpp
	$(CC) $(FLAGS) AdjList.cpp

clean: rm *.o lab11
	clean done
