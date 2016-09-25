lab4: main.o BST.o Node.o Queue.o
	g++ -std=c++11 -g main.o BST.o Node.o Queue.o -o lab4

main.o: main.cpp BST.h BST.cpp Node.h Node.cpp Queue.h Queue.cpp
	g++ -std=c++11 -g -c main.cpp
	
BST.o: BST.cpp
	g++ -std=c++11 -c BST.cpp
	
Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp
	 
Queue.o: Queue.cpp
	g++ -std=c++11 -c Queue.cpp 

clean: rm *.o lab4
	clean done
