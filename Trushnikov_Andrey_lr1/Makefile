all: main

main:get_name.o main.o print_str.o
	gcc get_name.o main.o print_str.o

get_name.o:get_name.c get_name.h
	gcc -c get_name.c 

main.o:main.c
	gcc -c main.c

print_str.o:print_str.c print_str.h
	gcc -c print_str.c


