compiler = gcc

all: run draw
draw: test
	python -u draw.py
run: test
	./test
test: test.o signals.o dsp.o
	${compiler} -o test test.o signals.o dsp.o
test.o: test.c signals.h dsp.h
	${compiler} -c test.c

dsp.o: dsp.c dsp.h
	${compiler} -c dsp.c
signals.o: signals.c signals.h
	${compiler} -c signals.c
clean:
	rm -f *.o test