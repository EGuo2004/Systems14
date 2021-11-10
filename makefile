all: main.o
	gcc -o fourteen main.o

main.o: main.c
	gcc -c main.c

run:
	./fourteen
