all: index_last_odd.o index_first_even.o sum_between_even_odd.o sum_before_even_and_after_odd.o menu.o
	gcc  index_last_odd.o index_first_even.o sum_between_even_odd.o sum_before_even_and_after_odd.o menu.o -o menu
menu.o: menu.c  
	gcc -c menu.c 
index_last_odd.o:index_last_odd.c index_last_odd.h
	gcc -c index_last_odd.c
index_first_even.o:index_first_even.c index_first_even.h
	gcc -c index_first_even.c
sum_between_even_odd.o:sum_between_even_odd.c sum_between_even_odd.h
	gcc -c sum_between_even_odd.c
sum_before_even_and_after_odd.o: sum_before_even_and_after_odd.c sum_before_even_and_after_odd.h
	gcc -c sum_before_even_and_after_odd.c
