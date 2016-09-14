lab3: main.o Hash.o
	g++ -std=c++11 -g main.o Hash.o -o lab3

main.o: main.cpp Hash.h Hash.cpp
	g++ -std=c++11 -g -c main.cpp
	
Hash.o: Hash.cpp
	g++ -std=c++11 -c Hash.cpp

clean: rm *.o lab3
	clean done
