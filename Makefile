#variables
CXX=g++
CFLAGS=-c -std=c++11 -O3
SOURCES=main.cpp
SOURCES+=$(wildcard src/*.cpp)
OBJECTS=$(subst .cpp,.o,$(subst src/,,$(SOURCES)))
EXECUTABLE=quadtree
BINDIR=/bin


all:  makeOBJ
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS)

makeOBJ:
	$(CXX) $(CFLAGS) $(SOURCES)

clean: 
	rm -rf $(OBJECTS) $(EXECUTABLE)
