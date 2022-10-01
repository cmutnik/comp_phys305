/* Discrete Fourier transform, time to frequency domain*/
// Corey Mutnik 4/17/15 mod from:
// P. Gorham, for physics 305
//  g++ DFTcalc.cpp DFT.cpp -o DFTcalc


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

#define NMAX 150000

typedef complex<double> dcmplx;  // define a shorthand for double complex

extern dcmplx dft(double*,double*,int,double);


main(int argc, char *argv[])
{

	FILE *fin, *fopen();
	double t[NMAX], f_t[NMAX];
	double fmin,fmax,fstep,nu,deltat,tau,Norm;
	int eof,nread,i;
	dcmplx Fnu;
	
	if(argc<4){
	  cerr << "usage: DFTcalc [min freq.][max freq.][freq. step(hz)] <datafile >spectrum file" << endl;
	  cerr << "Datafile should have two space- or tab-separated columns: col1=time   col2=sample value" <<endl;
	  cerr << "output: three columns: col1=frequency col2=Re(FT) col3=Im(FT)"<<endl;
	  exit(0);
	}

	fmin  = atof(argv[1]);  // min frequency
	fmax  = atof(argv[2]);  // max frequency
	fstep = atof(argv[3]);  // frequency step

	cerr <<"fmin= "<<fmin<< ", fmax= "<<fmax<<  ", fstep= " <<fstep<< endl;


	// read in the data file: each line must have the time and the data value
	nread = 0; i=0;
	while( eof= fscanf(stdin,"%lf %lf\n", &t[i], &f_t[i]) >0 ) {
		nread++;
		i++;
		if(i>=NMAX-1) break;
		}
		deltat = t[1]-t[0];
		tau = t[nread-1]-t[0];
	fprintf(stderr,"%d lines read, deltat= %e s, tau = %e s\n", nread, deltat, tau);
	
//	for(i=0;i<10;i++) cerr << t[i] << "\t" << f_t[i] << endl;

	if(nread >NMAX){
		fprintf(stderr,"NMAX exceeded!\n");
		exit(0);
		}

		Norm = 2.0/tau*sqrt(TWOPI);  //normalization to get amplitude
	for(nu=fmin;nu<fmax;nu+=fstep){
		Fnu = dft(t,f_t,nread,nu);
		fprintf(stdout,"%e   %e   %e\n", nu, Fnu.real()*Norm, Fnu.imag()*Norm);
		}

}

