CC=gcc
CFLAGS= -O1 -g -Wall -Wextra -std=c99 -Wno-missing-braces
LDFLAGS= -lraylib -lGL -lglfw -lm

# SORTING
SORTDIR=./sorting-algorithms/
SORTALGS=$(wildcard $(SORTDIR)*.c)
SORTOBJS=$(patsubst %.c,%.o,$(SORTALGS))

all: main

main: main.o $(SORTOBJS)
	$(CC) -o main main.o $(SORTOBJS) $(CFLAGS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

# make the sorting algos
$(SORTOBJS): %.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o main.o $(SORTOBJS)