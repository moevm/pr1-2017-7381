all: menu
menu: menu.o index_first_even.o index_last_odd.o sum_between_even_odd.o sum_before_even_and_after.o
	gcc menu.o index_first_even.o index_last_odd.o sum_between_even_odd.o sum_before_even_and_after.o
menu.o: menu.c
	gcc -c menu.c
index_first_even.o: index_first_even.c index_first_even.h
	gcc -c index_first_even.c
index_last_odd.o: index_last_odd.c index_last_odd.h
	gcc -c index_last_odd.c
sum_between_even_odd.o: sum_between_even_odd.c sum_between_even_odd.h index_last_odd.h index_first_even.h
	gcc -c sum_between_even_odd.c
sum_before_even_and_after.o: sum_before_even_and_after.c sum_before_even_and_after.h index_last_odd.h index_first_even.h
	gcc -c sum_before_even_and_after.c
