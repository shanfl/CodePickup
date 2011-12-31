APPS = process

TESTS = smallTest testCormen

all: $(TESTS) $(APPS)

test: $(TESTS)
	for i in $(TESTS); do ./$${i}; if [ $$? -ne 0 ]; then exit -1; fi; done

CC = g++

INCLUDE=-I../BinaryHeap -I.. -I../../Timing

TIMING = ../../Timing/report.o

## for debugging, use "-g -DREPORT"
#DEBUG=-g -DREPORT
DEBUG=-O3

CFLAGS= $(DEBUG) -Wall -pedantic 

GRAPH = ../graphCode.a 
BHEAP = ../BinaryHeap/BinaryHeap.o

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $<

%.o: %.cxx
	$(CC) -c $(CFLAGS) $(INCLUDE) $<

process: process.o mst.o
	$(CC) -o $@ $+ $(BHEAP) $(GRAPH) $(TIMING)

testCormen: testCormen.o $(GRAPH) mst.o
	$(CC) -o $@ $+ $(BHEAP) $(GRAPH) 

smallTest: smallTest.o $(GRAPH) mst.o
	$(CC) -o $@ $+ $(BHEAP) $(GRAPH) 

clean:
	rm -f *~ core
	rm -f *.o
	rm -f $(TESTS) $(APPS)
