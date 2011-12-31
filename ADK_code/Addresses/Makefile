# objdump -h memory
# size memory

CC = gcc
TIMING=../Timing/timing.o
REPORT=../Timing/report.o

CFLAGS = -Wall -pedantic -O3

# default rule to build C files
.c.o: 
	$(CC) -c $(CFLAGS) $(INC) $*.c

all: memory report addressReport order alloc

order: up.o down.o scattered.o order.o
	$(CC) -o orderUp $(TIMING) $(REPORT) up.o order.o
	$(CC) -o orderDown $(TIMING) $(REPORT) down.o order.o 
	$(CC) -o orderScattered  $(TIMING) $(REPORT) scattered.o order.o

alloc: alloc.o
	$(CC) -o $@ $+ $(TIMING) $(REPORT)

report: report.o
	$(CC) -o $@ $+

# this one MUST be compiled using debugging flags
memory: memory.c
	$(CC) -g memory.c -o $@ 

addressReport : memory report report.awk cmds
	awk -f report.awk cmds                                > /tmp/vars
	gdb -batch -x cmds memory | /bin/grep "[0-9] = [0-9]" > /tmp/addresses
	./report /tmp/vars /tmp/addresses  | sort -n -r       > addressReport
	rm /tmp/vars
	rm /tmp/addresses

test:
	@echo "No tests for Addresses"

clean:
	rm -f memory *~ *.o
	rm -f alloc orderUp orderScattered orderDown report
	rm -f fullAllocReport addressReport
