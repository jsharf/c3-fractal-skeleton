#include "Buddhabrot.h"
using namespace std;

void Buddhabrot::gen_fractal()
{

   
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
    
    // Initialize a bucket array (one integer for each pixel) (this is the outer bucket array)

    // iterate over the following several thousand times (at least more times than # of pixels)
  
        // Create a temporary bucket array (one integer for each pixel
        //
        // Let C be a random point in the complex plane
        //
        // Trace the orbit of C, incrementing the temporary bucket that z falls in for each iteration
        // If Z is in the mandelbrot set, discard the temporary bucket
        // Else, merge the temporary bucket with the outer bucket array
        

     // Normalize the global bucket array by dividing each value by the maximum value
     // Color each pixel however you wish
     //
     // Parallelizing this function is tricky. It helps to have a list of temporary bucket arrays
     // Which are merged after the computation has finished.
     
     // Parallelizing is not required, but will save you a lot of time.
     

}
    

