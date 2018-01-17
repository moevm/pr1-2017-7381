
objects = menu.o index_first_zero.o index_last_zero.o sum_between.o sum_before_and_after.o
executable = menu

all: $(objects)
	gcc -o $(executable) $(objects)

menu.o: index_first_zero.h index_last_zero.h sum_between.h sum_before_and_after.h
	gcc -c menu.c

index_first_zero.o: index_first_zero.c
	gcc -c index_first_zero.c

index_last_zero.o: index_last_zero.c
	gcc -c index_last_zero.c

sum_between.o: sum_between.c index_first_zero.h index_last_zero.h
	gcc -c sum_between.c

sum_before_and_after.o: sum_before_and_after.c index_first_zero.h index_last_zero.h
	gcc -c sum_before_and_after.c

clean:
	rm $(objects) $(executable)
