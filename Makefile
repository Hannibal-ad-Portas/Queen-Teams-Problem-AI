SHELL = /bin/bash
CC = g++
CFLAGS = -g -Wall
OUTP = main.o

queens: $(OUTP)
	g++ $(CFLAGS) -o queens $(OUTP)

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm queens $(OUTP)
