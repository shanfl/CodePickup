CC = gcc

INCLUDE = -I../Timing/

CFLAGS = -O3 -Wall -pedantic $(INCLUDE)

# default rule to build C files
.c.o: 
	$(CC) -c $(CFLAGS) $*.c

REPORT = ../Timing/report.o
TIMING = ../Timing/timing.o  

all: test sample resolution

sample: sample.o
	$(CC) -o $@ $+ -lrt -lm $(REPORT)

test: forLoop.o
	$(CC) -o $@ $+ $(TIMING) $(REPORT)

resolution : tr.o
	$(CC) -o $@ $+ -lrt

clean:
	rm -f *~ a.out *.o test sample resolution


