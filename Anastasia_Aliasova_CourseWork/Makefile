all: main.o options.o
	gcc main.o options.o
main.o: main.c options.h
	gcc -c main.c
options.o: options.c options.h
	gcc -c options.c
