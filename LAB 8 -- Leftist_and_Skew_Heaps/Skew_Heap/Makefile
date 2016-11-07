lab8: main.o SkewHeap.o Node.o Queue.o
	g++ -std=c++11 -g main.o SkewHeap.o Node.o Queue.o -o lab8

main.o: main.cpp SkewHeap.h SkewHeap.cpp Node.h Node.cpp Queue.h Queue.cpp
	g++ -std=c++11 -g -c main.cpp
	
SkewHeap.o: SkewHeap.cpp
	g++ -std=c++11 -c SkewHeap.cpp
	
Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp
	
Queue.o: Queue.cpp
	g++ -std=c++11 -c Queue.cpp

clean: rm *.o lab8
	clean done
