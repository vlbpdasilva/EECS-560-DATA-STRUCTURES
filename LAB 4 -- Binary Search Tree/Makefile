lab4: main.o BST.o Node.o
	g++ -std=c++11 -g main.o BST.o Node.o -o lab4

main.o: main.cpp BST.h BST.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c main.cpp
	
BST.o: BST.cpp
	g++ -std=c++11 -c BST.cpp
	
Node.o: Node.cpp
	 g++ -std=c++11 -c Node.cpp

clean: rm *.o lab4
	clean done
