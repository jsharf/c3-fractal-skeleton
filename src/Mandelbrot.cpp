#include "Mandelbrot.h"

void Mandelbrot::gen_fractal()
{
    // Pseudocode:
    // Real (-2.5, 1)
    // Imaginary (-1, 1)

    // Iterate over each pixel and determine the corresponding complex coordinate (or several complex coordinates if you're anti-aliasing)


    // For each pixel, compute the corresponding complex coordinate C (or multiple sub-coordinates, for AA)   

    // let z_r and z_i be 0
    // Begin iterating... while z is not infinity and not too many iterations have passed...

    // Z = Z^2 + C
    // increment an iteration counter

    // Color each pixel

    unsigned int width = get_width();
    double len_pix_x = 3.0/get_width();
    unsigned int height = get_height();
    double len_pix_y = 3.0/get_height();

    unsigned int total_pixels = height*width;

    #pragma omp parallel for
    for (int flat_i=0; flat_i<total_pixels; flat_i++)
    {	
        unsigned int i = flat_i%height;
        unsigned int j = flat_i/height;
        vector <unsigned char> pix(4);

        unsigned int array_x = j;
        unsigned int array_y = i;

        double iter_avg = 0;

        double a = (((double)array_x)/width)*3.0-2.25;
        double b = (((double)array_y)/height)*3.0-1.5;

        #pragma omp parallel for reduction(+ : iter_avg)
        for (int k = 0; k<SUBSAMPLING; k++)
        {
            double u = (len_pix_x/SUBSAMPLING)*(rand()%SUBSAMPLING);
            double v = (len_pix_y/SUBSAMPLING)*(rand()%SUBSAMPLING);
            int iter=0;
            double z = 0, zi = 0, ztemp;
            while (pow(z, 2.0) + pow(zi, 2.0) < 4 && iter < MAXITER)
            {
                ztemp = pow(z, 2.0) - pow(zi, 2.0) + (a+u);
                zi = 2.0*zi*z + (b+v);
                z = ztemp;
                iter++;
            }
            // Continuous coloring!
            double mag_z = sqrt(pow(z, 2.0) + pow(zi, 2.0));
            iter_avg += (iter - log(log(mag_z)/log(2.0)));
            // iter_avg += iter;
        }
        int iter = static_cast<int>(iter_avg/SUBSAMPLING);

        if (iter<MAXITER)
        {
            // Colorizing step... RGBA = 0, 1, 2, 3.
            double percent_iter = ((double)iter)/MAXITER;
            pix[0] = static_cast<unsigned char>(pow(percent_iter, 0.6)*255);
            pix[1] = static_cast<unsigned char>(pow(percent_iter, 0.5)*255);
            pix[2] = static_cast<unsigned char>(pow(percent_iter, 0.4)*255);
        }
        else
        {
            pix[0] = 0;
            pix[1] = 0;
            pix[2] = 0;
        }

        m_bitmap[array_y*m_width*4 + array_x*4 + 0] = pix[0];
        m_bitmap[array_y*m_width*4 + array_x*4 + 1] = pix[1];
        m_bitmap[array_y*m_width*4 + array_x*4 + 2] = pix[2];
        m_bitmap[array_y*m_width*4 + array_x*4 + 3] = 255;
    }


}
