CC=gcc

tutorial: tutorial.o
	$(CC) tutorial.o -o tutorial 

tutorial.o: tutorial.C
	$(CC) -c tutorial.C

clean:
	rm *.o tutorial
