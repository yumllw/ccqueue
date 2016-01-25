all:
	gcc -O2 -Wall test.c -o test
clean:
	rm -f *.o test
