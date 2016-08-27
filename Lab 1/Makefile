Lab1: main.o List.o Node.o
	g++ -std=c++11 -g main.o List.o Node.o -o Lab1

main.o: main.cpp List.h List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c main.cpp
	
List.o: List.cpp
	g++ -std=c++11 -c List.cpp
	
Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp

clean: rm *.o Lab1
	clean done
