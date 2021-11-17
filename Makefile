CXX=g++
CXXFLAGS=-std=c++17 -Wall -pedantic

compile:
	$(CXX) $(CXXFLAGS) -c EndianSafeBinaryStream.cpp
	$(CXX) $(CXXFLAGS) -c example.cpp
	$(CXX) $(CXXFLAGS) example.o EndianSafeBinaryStream.o -o example
	
clean:
	rm -rf EndianSafeBinaryStream.o
	rm -rf example.o
	rm -rf example
	rm -rf test.bin
