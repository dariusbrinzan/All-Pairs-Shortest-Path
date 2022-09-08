CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: roy_test.o johnson_test.o dijkstra_test.o

run-best:
	./test1

run-p1:
	./test2

run-p2:
	./test3

Johnson.o: Johnson.cpp
	g++ Johnson.cpp -c $(CFLAGS)

johnson_test.o: main.cpp Johnson.o
	g++ Johnson.o main.cpp -o test1 $(CFLAGS)

Roy.o: Roy.cpp
	g++ Roy.cpp -c $(CFLAGS)

roy_test.o: main.cpp Roy.o 
	g++ Roy.o main.cpp -o test2 $(CFLAGS)

Dijkstra.o: Dijkstra.cpp
	g++ Dijkstra.cpp -c $(CFLAGS)

dijkstra_test.o: main.cpp Dijkstra.o 
	g++ Dijkstra.o main.cpp -o test3 $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test3 test.in test.out