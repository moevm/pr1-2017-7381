
all: main.o music.o course.o
	gcc main.o music.o course.o 

main.o: main.c music.h course.h
	gcc -c main.c

music.o: music.c music.h
	gcc -c music.c

course.o: course.c course.h music.h
	gcc -c course.c

clean:
	rm main.o music.o course.o