lab5: main.o Heap.o
	g++ -std=c++11 -g main.o Heap.o -o lab5

main.o: main.cpp Heap.h Heap.cpp
	g++ -std=c++11 -g -c main.cpp
	
Heap.o: Heap.cpp
	g++ -std=c++11 -c Heap.cpp

clean: rm *.o lab5
	clean done
