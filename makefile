all: proc1.o proc2.o
	gcc -o 1 proc1.o
	gcc -o 2 proc2.o

proc1.o: proc1.c
	gcc -c proc1.c

proc2.o: proc2.c
	gcc -c proc2.c

	
