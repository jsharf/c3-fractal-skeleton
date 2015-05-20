#include <cmath>
#include <cstdlib>
#include "Fractal.h"

class Mandelbrot : public Fractal
{
	public:
	Mandelbrot(int height, int width):Fractal(height, width) {}
	void gen_fractal();
};

