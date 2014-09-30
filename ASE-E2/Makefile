all:
	gcc -c test.c -o test.o
	gcc -c linktable.c -o linktable.o
	gcc -c menu.c -o menu.o
	gcc linktable.o test.o menu.o -o test

clean:
	rm -rf *.o test
