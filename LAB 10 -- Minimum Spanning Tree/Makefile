lab10: main.o MST.o 
	g++ -std=c++11 -g main.o MST.o -o lab10

main.o: main.cpp MST.h MST.cpp LeftistHeap.h LeftistHeap.hpp Node.h Node.hpp
	g++ -std=c++11 -g -c main.cpp
	
MST.o: MST.cpp 
	g++ -std=c++11 -c MST.cpp	
	
clean: rm *.o lab10
	clean done
