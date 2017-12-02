menu: menu.o index_first_zero.o index_last_zero.o sum_between_zero.o sum_before_and_after_zero.o
	gcc menu.o index_first_zero.o index_last_zero.o sum_between_zero.o sum_before_and_after_zero.o -o menu
menu.o: menu.c
	gcc -c menu.c
index_first_zero.o: index_first_zero.c index_first_zero.h
	gcc -c index_first_zero.c
index_last_zero.o: index_last_zero.c index_last_zero.h
	gcc -c index_last_zero.c
sum_between_zero.o: sum_between_zero.c sum_between_zero.h
	gcc -c sum_between_zero.c
sum_before_and_after_zero.o: sum_before_and_after_zero.c sum_before_and_after_zero.h
	gcc -c sum_before_and_after_zero.c
clean:
	rm -rf *.o

