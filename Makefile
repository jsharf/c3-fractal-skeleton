all: Fractal.o Mandelbrot.o fractalgen.o lodepng.o
	g++ -fopenmp -g -o fractalgen Fractal.o Mandelbrot.o fractalgen.o lodepng.o -ansi -pedantic -Wall -Wextra -O3

Fractal.o: src/Fractal.cpp
	g++ -fopenmp -g -c -o Fractal.o src/Fractal.cpp

Mandelbrot.o: src/Mandelbrot.cpp 
	g++ -fopenmp -g -c -o Mandelbrot.o src/Mandelbrot.cpp

fractalgen.o: src/fractalgen.cpp
	g++ -fopenmp -g -c -o fractalgen.o src/fractalgen.cpp

lodepng.o: src/lodepng.cpp
	g++ -fopenmp -g -c -o lodepng.o src/lodepng.cpp

clean:
	rm *.o fractalgen
