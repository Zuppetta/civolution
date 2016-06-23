CC = g++
DEBUG = -g
CFLAGS = -O0 -Wall $(DEBUG) -c
LFLAGS = -O0 -Wall $(DEBUG)
OBJS = settler.o

settler.o: settler.hpp settler.cpp
	$(CC) $(CFLAGS) settler.cpp

clean:
	rm ./*.o
