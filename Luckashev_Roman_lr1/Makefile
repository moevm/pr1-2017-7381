all: main.o get_name.o print_str.o
	gcc main.o get_name.o print_str.o
get_name.o: get_name.c get_name.h
	gcc -c get_name.c
print_str.o: print_str.h print_str.c
	gcc -c print_str.c
main.o: main.c
	gcc -c main.c
