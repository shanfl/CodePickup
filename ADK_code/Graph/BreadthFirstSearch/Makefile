INCLUDE = -I../BinaryHeap -I..

CC = g++

#DEBUG=-O3
DEBUG = -g

CFLAGS = $(DEBUG) -Wall -pedantic

TESTS = figure6_12

all: $(TESTS)

test: $(TESTS)
	for i in $(TESTS); do ./$${i}; if [ $$? -ne 0 ]; then exit -1; fi; done

GRAPH = ../graphCode.a 

# default rule to build C files
%.o: %.cxx
	$(CC) -c $(CFLAGS) $(INCLUDE) $*.cxx

figure6_12: figure6_12.o counter_bfs.o
	$(CC) -o $@ $+ $(GRAPH)

clean:
	rm -f *~ core
	rm -f $(TESTS)
	rm -f *.o
