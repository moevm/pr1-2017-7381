
obj = main.o mc.o mcc.o
exe = mcc

all: $(obj)
	gcc -o $(exe) $(obj)

main.o: main.c mc.h mcc.h
	gcc -c main.c

mc.o: mc.c mc.h
	gcc -c mc.c

mcc.o: mcc.c mcc.h mc.h
	gcc -c mcc.c

clean:
	rm $(exe) $(obj)