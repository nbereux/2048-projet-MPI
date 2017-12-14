CC=g++
CFLAGS =-g -std=c++11 -Wall

default: main

main: fonctions_2048.o main.o ncurses.o
	$(CC) $(CFLAGS) -o main fonctions_2048.o main.o ncurses.o -lncurses

fonctions_2048.o: fonctions_2048.cpp 2048.h
	$(CC) $(CFLAGS) -c fonctions_2048.cpp

ncurses.o: ncurses.cpp 2048.h
	$(CC) $(CFLAGS) -c ncurses.cpp -lncurses

main.o: main.cpp 2048.h ncurses.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) count *.o*~
