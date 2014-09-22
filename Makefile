CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 

.PHONY:all
all: test

test:test.o
	g++ -o $@ $^

test.o:test.cc


.PHONY:clean
clean: 
	-rm  -f *.o 