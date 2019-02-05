SHELL = /bin/bash
CC = g++
CFLAGS = -g -Wall
OUTP = main.o util.o hillClimb.o board.o

queens: $(OUTP)
	g++ $(CFLAGS) -o queens $(OUTP)

main.o: main.cpp util.cpp
	g++ -c main.cpp

hillClimb.o: hillClimb.cpp util.cpp board.cpp
	g++ -c hillClimb.cpp

board.o: board.cpp
	g++ -c board.cpp

util.o: util.cpp
	g++ -c util.cpp

clean:
	rm queens $(OUTP)
