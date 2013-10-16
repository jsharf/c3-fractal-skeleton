#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Mandelbrot.h"
using namespace std;

int main(int argc, char *argv[])
{
    // Seed the random number generator
	srand(time(0));
   
    // Read command line input (if you're on windows, you might want to replace this with some I/O code)
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

    // Create a fractal object
	Mandelbrot my_fractal(a);
	cout << "Fractal Allocated" << endl;

    // Generate the fractal
    my_fractal.gen_fractal();
    cout << "Fractal Created" << endl;
    
    // Save the fractal to a file
	my_fractal.save_file(str);
    cout << "Fractal Saved to file" << endl;
    
    if (argc < 3)
    {
        free(str);
    }
	
    return 0;
}
