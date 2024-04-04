CC = gcc
CCFL = -Wall -Werror -Wextra -g

all: checker

adjacency.o: adjacency.c
	$(CC) $(CCFL) -c $<

main.o: main.c
	$(CC) $(CCFL) -c $<

checker: main.o adjacency.o
	$(CC) $(CCFL) $^ -o ../build/$@

clean:
	rm -f *.o
	rm -f ../build/checker

rebuild: clean all
