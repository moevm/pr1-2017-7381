all: main.o MusicalComposition.o
	gcc MusicalComposition.o main.o
main.o: main.c
	gcc -c main.c
MusicalComposition.o: MusicalComposition.h MusicalComposition.c
	gcc -c MusicalComposition.c
clean:
	rm main.o MusicalComposition.o
