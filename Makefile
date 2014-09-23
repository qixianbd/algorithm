CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 
LANG=en_US

.PHONY:all
all: test BinarySearch tree_max_distance

test:test.o
	g++ -o $@ $^

BinarySearch: BinarySearch.o
	g++ -o $@ $^

tree_max_distance:tree_max_distance.o
	g++ -o $@ $^

test.o:test.cc
BinarySearch.o:BinarySearch.cc
tree_max_distance.o:tree_max_distance.cc tree.h


.PHONY:clean
clean: 
	-rm  -f *.o 