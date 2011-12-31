CC = gcc

CFLAGS = -Wall -pedantic -O3

# default rule to build C files
.c.o: 
	$(CC) -c $(CFLAGS) $(INC) $*.c

all: eval

eval: eval.o
	$(CC) -o $@ $+ -lm

test:
	@echo "No tests for bin"

clean:
	rm -f eval
	rm -f *.o *~ core
