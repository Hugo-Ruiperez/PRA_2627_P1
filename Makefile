CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: testListArray

testListArray: testListArray.cpp List.h ListArray.h
	$(CXX) $(CXXFLAGS) testListArray.cpp -o testListArray

test: testListArray
	./testListArray

clean:
	rm -f testListArray *.o

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

clean:
	rm -r *.o *.gch *.pch bin

.PHONY: all test clean
