CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c11
LDLIBS=-lm
OBJ= $(wildcard *.o)

romeo: romeo.o
	$(CC) -o romeo romeo.o $(LDLIBS)

romeo.o: romeo.c
	$(CC) -c romeo.c -o romeo.o $(CFLAGS)
