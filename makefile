CC = gcc
CFLAGS = -Wall -Werror

SRC_FILES = day01/day01.c 

main: main.c $(SRC_FILES)
	mkdir -p bin
	$(CC) $(CFLAGS) -o ./bin/aoc main.c $(SRC_FILES)
