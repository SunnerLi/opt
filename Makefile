all: r2.o

r2.o: record2.c
	gcc -o r2 record2.c -lm `pkg-config --cflags --libs opencv` 

clean:
	rm *.o

