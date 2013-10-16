all: objs/Fractal.o objs/Buddhabrot.o objs/Mandelbrot.o objs/fractalgen.o objs/lodepng.o
	g++ -fopenmp -g -o fractalgen objs/Fractal.o objs/Buddhabrot.o objs/Mandelbrot.o objs/fractalgen.o objs/lodepng.o -ansi -pedantic -Wall -Wextra -O3

objs/Fractal.o: src/Fractal.cpp
	g++ -fopenmp -g -c -o objs/Fractal.o src/Fractal.cpp

objs/Mandelbrot.o: src/Mandelbrot.cpp 
	g++ -fopenmp -g -c -o objs/Mandelbrot.o src/Mandelbrot.cpp

objs/fractalgen.o: src/fractalgen.cpp
	g++ -fopenmp -g -c -o objs/fractalgen.o src/fractalgen.cpp

objs/Buddhabrot.o: src/Buddhabrot.cpp
	g++ -fopenmp -g -c -o objs/Buddhabrot.o src/Buddhabrot.cpp

objs/lodepng.o: src/lodepng.cpp
	g++ -fopenmp -g -c -o objs/lodepng.o src/lodepng.cpp

clean:
	rm objs/*.o fractalgen
