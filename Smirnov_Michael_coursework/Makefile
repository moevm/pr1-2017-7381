all: main.o others.o kurs.o
	gcc main.o others.o
main.o: main.c function.h
	gcc -c main.c
others.o: others.c function.h
	gcc -c others.c
kurs.o: kurs.c function.h
	gcc -c kurs.c
