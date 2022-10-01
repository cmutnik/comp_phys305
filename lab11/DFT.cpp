/* Discrete Fourier transform, time to frequency domain*/
// Corey Mutnik 4/17/15 mod from:
// P. Gorham, for physics 305, 3/27/2003, modified 4/13/2010 for C99 complex standard

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 
#include <complex>

#define PI M_PI   /* from values.h */
#define TWOPI (2.00000000000*PI)

typedef complex<double> dcmplx;


dcmplx dft(double t[], double data[], int nsamp, double nu)
                /* discrete fourier transform at frequency
                  nu of equally-spaced time series samples in data[].
                  returns the complex transform value at frequency nu.*/

{
        int k,i;
        double w, deltat;
        dcmplx ft,zsum(0.0,0.0);

        w = TWOPI*nu;  // angular frequency
	deltat = t[1]-t[0]; // assumes all time intervals equal!
	
//	for(i=0;i<10;i++) cerr << t[i] << "\t" << data[i] << endl;
	

	
        for(k=0;k<nsamp;k++){   // k is the time index
	     dcmplx expiwt(cos(w*t[k]),sin(w*t[k]));  // using Euler's representation   
	     zsum += data[k] * expiwt * deltat;
//  cerr << k << " " << w << " " << t[k] << " " << expiwt << " " << zsum.real() << " " << zsum.imag() << endl;
          }

          ft  = 1.0/sqrt(TWOPI)*zsum;

        return(ft);
}

