# should we count each comparison between two elements?
# report will include these results.

CC = gcc

DEBUG=-g
#DEBUG=-O3

CFLAGS = $(DEBUG) -Wall -pedantic

# timing contains report.h and other necessary filesn
INC = -I../Timing

# default rule to build C files
.c.o: 
	$(CC) -c $(CFLAGS) $(INC) $*.c

TIMING = ../Timing/report.o

all: tester large

tester: tester.o
	$(CC) -o $@ $+ $(TIMING)

large: large.o
	$(CC) -o $@ $+ $(TIMING)

test:
	@echo "No tests for Chapter1"

clean:
	rm -f *.o 
	rm -f *~ core
	rm -f tester large

