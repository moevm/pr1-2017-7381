
obj = main.o mc.o
exe = mc

all: $(obj)
	gcc -o $(exe) $(obj)

main.o: main.c mc.h
	gcc -c main.c

mc.o: mc.c mc.h
	gcc -c mc.c

clean:
	rm $(exe) $(obj)
