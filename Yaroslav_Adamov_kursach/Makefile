all: main.o api.o
	gcc main.o api.o
main.o: main.c api.h
	gcc -c main.c
api.o: api.c api.h
	gcc -c api.c
clean:
	rm main.o api.o
