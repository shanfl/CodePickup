CC = gcc

INC = ../Timing

# make sure to optimize performance.
CFLAGS = -Wall -pedantic -O3

# default rule to build C files
.c.o: 
	$(CC) -c $(CFLAGS) -I $(INC) $*.c

ALL = IntTime StringTime DivTimeInt DivTimeDouble DivTimeFloat \
	MulTimeInt MulTimeShort MulTimeDouble MulTimeFloat \
	MulTimeLongDouble SqrtTimeFloat SqrtTimeDouble

all: $(ALL)

TRIALS = 10000000

TIMING = ../Timing/timing.o \
	 ../Timing/report.o

DivTimeInt : DivTimeInt.o
	$(CC) -o $@ $+ $(TIMING)

DivTimeFloat : DivTimeFloat.o
	$(CC) -o $@ $+ $(TIMING)

SqrtTimeFloat : SqrtTimeFloat.o
	$(CC) -o $@ $+ $(TIMING) -lm

SqrtTimeDouble : SqrtTimeDouble.o
	$(CC) -o $@ $+ $(TIMING) -lm

DivTimeDouble : DivTimeDouble.o
	$(CC) -o $@ $+ $(TIMING)

MulTimeShort : MulTimeShort.o
	$(CC) -o $@ $+ $(TIMING)

MulTimeInt : MulTimeInt.o
	$(CC) -o $@ $+ $(TIMING)

MulTimeFloat : MulTimeFloat.o
	$(CC) -o $@ $+ $(TIMING)

MulTimeDouble : MulTimeDouble.o
	$(CC) -o $@ $+ $(TIMING)

MulTimeLongDouble : MulTimeLongDouble.o
	$(CC) -o $@ $+ $(TIMING)

IntTime : buildInt.o
	$(CC) -o $@ $+ $(TIMING)

StringTime : buildString.o
	$(CC) -o $@ $+ $(TIMING)

table:
	@echo -n "32-bit integer comparison, "
	./IntTime -n $(TRIALS) | head -1

	@echo -n "32-bit integer multiplication, " 
	./MulTimeInt -n $(TRIALS) | head -1

	@echo -n "32-bit float multiplication, " 
	./MulTimeFloat -n $(TRIALS) | head -1

	@echo -n "64-bit double multiplication, " 
	./MulTimeDouble -n $(TRIALS) | head -1

	@echo -n "32-bit float division, " 
	./DivTimeFloat -n $(TRIALS) | head -1

	@echo -n "8-bit integer multiplication, " 
	./MulTimeShort -n $(TRIALS) | head -1

	@echo -n "64-bit double division, " 
	./DivTimeDouble -n $(TRIALS) | head -1

	@echo -n "64-bit double multiplication, " 
	./MulTimeLongDouble -n $(TRIALS) | head -1

	@echo -n "32-bit integer division, " 
	./DivTimeInt -n $(TRIALS) | head -1

	@echo -n "64-bit double square root, " 
	./SqrtTimeDouble -n $(TRIALS) | head -1

	@echo -n "32-bit double square root, " 
	./SqrtTimeFloat -n $(TRIALS) | head -1

test:
	@echo "No tests for Math"

clean:
	rm -f *.o
	rm -f core *~ $(ALL)
