CXXFLAGS=-g -std=c++11
gameoflife: gameoflife.o
		g++ -o gameoflife gameoflife.o
gameoflife.o: gameoflife.h
