
objects = main.o MusicalComposition.o
executable = MusicalCompositions

all: $(objects)
	gcc -o $(executable) $(objects)

main.o: main.c MusicalComposition.h
	gcc -c main.c

MusicalComposition.o: MusicalComposition.c MusicalComposition.h
	gcc -c MusicalComposition.c

clean:
	rm $(objects) $(executable)