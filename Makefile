CC=g++
CFLAGS =-g -Wall

default: main

main: fonctions_2048.o main.o
	$(CC) $(CFLAGS) -o main fonctions_2048.o main.o

fonctions_2048.o: fonctions_2048.cpp 2048.h
	$(CC) $(CFLAGS) -c fonctions_2048.cpp

main.o: main.cpp 2048.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) count *.o*~
