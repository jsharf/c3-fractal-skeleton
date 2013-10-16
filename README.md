Hello!

This is lab 1 of the UCLA IEEE C3 program.

Make commands:
  
    Make all
        Compile the project
    Make clean
        Delete any compiled executables and temporary files

Once the program is built, run ./fractalgen <number> <filename.png> to generate a fractal

<number> is a multiplier on the size of the fractal. While running fractalgen with 1 should be relatively quick, using a value above 20 will start to take a lot of time.
See the Mandelbrot and Fractal class constructors for more information.

Lodepng is a library using to generate .png files. Don't worry about the code in that file. It's abstracted in the save_file method in the Fractal class.

More on m_bitmap...

m_bitmap is a single-dimensional array used to encode the entire image. It's length is equal to the width of the image times the height of the image.

To get the r,g,b values for a coordinate x, y, you might do something like....

    m_bitmap[x*m_height*4 + y*4 + 0] // R
    m_bitmap[x*m_height*4 + y*4 + 1] // G
    m_bitmap[x*m_height*4 + y*4 + 2] // B

To iterate along each pixel, choosing a point in the complex plane for each, you might do something like...

    int height = get_height(), width = get_width();
    int i, npixels = height*width;
    for (i = 0; i<npixels; i++)
    {
        int x = i%height;
        int y = i/height;
        
        double c_r = (((double)x)/width)*3.0 - 2.25;
        double c_i = (((double)y)/height)*3.0 - 1.5;

        /// ....

    }


Parallelization
---------------

We highly recommend using openmp to improve the performance of your application

If you're not sure how to do this, try just adding "#pragma omp parallel for" to the line above your outer for loop

(This will result in the loop being executed out of order and simultaneously on multiple cores. it will jumble any print statements you have)

If this breaks your program, you have some data dependencies you need to resolve.

Continuous Coloring
-------------------

You may notice that your fractal's coloring has a number of bands of color. In order to get continuous coloring, there's an alternative coloring method
mentioned on wikipedia's mandelbrot fractal page.

Resources
---------

I highly suggest the wikipedia page on fractals. In particular, look at the section on computer drawings of the mandelbrot set. 

Particular performance improvements will save you a lot of time (parallelism, not testing the main cardioids, etc).  So look for these online and on the wikipedia page.
