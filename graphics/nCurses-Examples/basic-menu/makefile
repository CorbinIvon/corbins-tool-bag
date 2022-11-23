# Makefile for Writing Make Files Example
# *****************************************************
# Variables to control Makefile operation
CC = g++
CFLAGS = -Wall -g
# ****************************************************
# Targets needed to bring the executable up to date

#example: main.o
#	$(CC) $(CFLAGS) -o example main.o

# The main.o target can be written more simply
#main.o: main.cpp
#	$(CC) $(CFLAGS) -c main.cpp
menu:
	g++ -lncurses menu.h menu.c -o menu
main:
	g++ -lncurses main.cpp -o main
