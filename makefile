compile : str.o
	gcc str.o

run:
	./a.out

f:
	emacs str.c

str.o: str.c str.h
	gcc -c str.c
