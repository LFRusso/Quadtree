#variables
CXX=g++
CFLAGS=-c -std=c++11 -O3
SOURCES=main.cpp

SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

LIBFLAGS= 

SOURCES+=$(wildcard src/*.cpp)
OBJECTS=$(subst .cpp,.o,$(subst src/,,$(SOURCES)))
EXECUTABLE=quadtree
BINDIR=/bin


all:  makeOBJ
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS)
	
animate: makeOBJ
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS) $(SFMLFLAGS)

makeOBJ:
	$(CXX) $(CFLAGS) $(SOURCES)

clean: 
	rm -rf $(OBJECTS) $(EXECUTABLE)
