
obj = main.o MCNode.o MCList.o
exe = MCList

all: $(obj)
	gcc -o $(exe) $(obj)

test.o: main.c MCNode.h MCList.h
	gcc -c main.c

MCNode.o: MCNode.c MCNode.h
	gcc -c MCNode.c

MCList.o: MCList.c MCList.h MCNode.h
	gcc -c MCList.c
	
clean:
	rm $(obj) $(exe)  