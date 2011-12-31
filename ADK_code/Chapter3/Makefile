JAVA = java
JAVAC = javac

CCPLUSPLUS = g++
CC = gcc
CFLAGS = -O3 -Wall -pedantic

INCLUDE = -I../Timing/

TIMING = ../Timing/report.o

# default rule to build C files
.c.o: 
	$(CC) -c $(CFLAGS) $(INCLUDE) $*.c

%.o: %.cxx
	$(CCPLUSPLUS) -c $(CFLAGS) $(INCLUDE) $*.cxx

all: Comparison Example_3_2 Comparison.class

Comparison.class: Comparison.java
	$(JAVAC) $<

# need math libraries
Comparison: comparison.o
	$(CCPLUSPLUS) $< -o $@ $(TIMING)

Example_3_2: example_3_2.o
	$(CC) $< -o $@

test:
	@echo "No tests for Chapter3"

clean:
	rm -f *.o *.class
	rm -f *~
	rm -f a.out Comparison Example_3_2


