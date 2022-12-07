ggplot: ggplot.o
	gcc ggplot.o -o ggplot

ggplot.o: plot.c
	gcc -c plot.c -o ggplot.o

clean:
	rm *.o