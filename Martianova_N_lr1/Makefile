all: main.o get_name.o print_str.o
	gcc  main.o get_name.o print_str.o
main.o: get_name.h print_str.h main.c
	gcc -c main.c
get_name.o: get_name.h get_name.c
	gcc -c get_name.c
print_str.o:print_str.h print_str.c
	gcc -c print_str.c
