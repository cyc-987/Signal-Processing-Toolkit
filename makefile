test: test.o signals.o
	gcc -o test test.o signals.o
test.o: test.c signals.h
	gcc -c test.c
signals.o: signals.c signals.h
	gcc -c signals.c
clean:
	rm -f *.o test