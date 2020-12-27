CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic

all: sorting

sorting: sorting.o binary.o shell.o bubble.o quick.o
	$(CC) -o sorting sorting.o binary.o shell.o bubble.o quick.o -lm

sorting.o: sorting.c binary.h shell.h bubble.h quick.h
	$(CC) $(CFLAGS) -c sorting.c

binary.o: binary.c binary.h
	$(CC) $(CFLAGS) -c binary.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

quick.o: quick.c quick.h
	$(CC) $(CFLAGS) -c quick.c

bubble.o: bubble.c bubble.h
	$(CC) $(CFLAGS) -c bubble.c

clean:
	rm -rf sorting sorting.o binary.o shell.o quick.o bubble.o infer-out

infer:
	make clean; infer-capture -- make; infer-analyze -- make

valgrind:
	valgrind ./sorting -A

