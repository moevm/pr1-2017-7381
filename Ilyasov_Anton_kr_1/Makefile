all:main.o opt.o
	gcc main.o opt.o
main.o:main.c opt.h
	gcc -c main.c
opt.o: opt.c opt.h
	gcc -c opt.c

