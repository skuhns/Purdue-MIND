//Solves FFT according to the summation defintion
//Xk = Summation(x_n * e^(-i*2*pi*k*n / N))
//Where x_n is the number at index "n" of dataset "x"
//N is number of samples in the dataset
//e^(-i*2*pi*k*n / N)) simplifies to cos(2pi*k*n/N) - i*sin(2pi*k*n/N)
//according to Euler's formula
//We ignore "i" in the case where i is the complex number in this case.
//Since we are solving for the magnitude of the FFT, the i falls out anyway
//https://en.wikipedia.org/wiki/Fast_Fourier_transform
//https://en.wikipedia.org/wiki/Discrete_Fourier_transform
//#include "TrigDef.h"

