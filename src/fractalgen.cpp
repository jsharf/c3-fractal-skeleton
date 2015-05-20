#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Mandelbrot.h"
using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
    double a;
    char *str; 
    str = (char *) malloc(sizeof(char) * 11);
    if (argc < 3)
    {
        a = 1.0;
        strcpy(str,"output.png");
    }
    else
    {
        a = (double) atoi(argv[1]);
        str = argv[2];
    }
	Mandelbrot my_fractal(a);
	cout << "Fractal Allocated" << endl;
    my_fractal.gen_fractal();
    cout << "Fractal Created" << endl;
	my_fractal.save_file(str);
    cout << "Fractal Saved to file" << endl;
    if (argc < 3)
    {
        free(str);
    }
	return 0;
}
