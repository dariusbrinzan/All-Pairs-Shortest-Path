CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo.o

algo.o: algo.cpp algo.h
	$(CC) $(CFLAGS) -c algo.cpp

build_best: algo_test.o algo.o
	$(CC) $(CFLAGS) $^ -o algo_test

algo_test.o: algo_test.cpp
	$(CC) $(CFLAGS) -c algo_test.cpp


.PHONY: clean
clean:
	rm -rf algo_test *.o
