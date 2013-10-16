#ifndef FRACTAL_H
#define FRACAL_H

#include<string>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<omp.h>
#include "lodepng.h"
using namespace std;	


const int MAXITER = 1100;
const int SUBSAMPLING = 20;

class Fractal
{
    public:
        Fractal(unsigned int height, unsigned int width);
		Fractal(double x);
		~Fractal();
        virtual void gen_fractal() = 0;
        bool save_file(string filepath) const;
		unsigned int get_width() const;
		unsigned int get_height() const;
    protected:
        unsigned char *m_bitmap;
		unsigned int m_height;
		unsigned int m_width;
};

#endif // FRACTAL_H
