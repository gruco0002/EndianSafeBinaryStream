CXX=g++
CXXFLAGS=-std=c++17 -Wall -pedantic

compile:
	$(CXX) $(CXXFLAGS) -c example.cpp
	$(CXX) $(CXXFLAGS) example.o -o example
	
run:
	./example

clean:
	rm -rf example.o
	rm -rf example
	rm -rf test.bin

all: compile run clean
