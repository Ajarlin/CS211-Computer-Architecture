all: count

count: count.c
	gcc -Wall -fsanitize=address count.c -o count
	
clean:
	rm -rf count