CC = gcc
CFLAGS = -Wall -Werror

all : first second third fourth fifth

first : first.c first.h
	$(CC) $(CFLAGS) first.c -o first
second : second.c second.h
	$(CC) $(CFLAGS) second.c -o second
third : third.c third.h
	$(CC) $(CFLAGS) third.c -o third
fourth : fourth.c fourth.h
	$(CC) $(CFLAGS) fourth.c -o fourth
fifth : fifth.c fifth.h
	$(CC) $(CFLAGS) fifth.c -o fifth


clean : 
	rm -f first second third fourth fifth