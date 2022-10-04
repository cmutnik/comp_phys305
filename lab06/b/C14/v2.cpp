// program and functions to generate weighted random numbers
// using von Neumann's method
// core mutnik 3/15
// REF: P. Gorham 2/21/2007, updated to c++ 2/3/2013

using namespace std;       
#include <iostream>       
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>   
#include <cstdio>     // for the  useful old C-standard stuff 
#include <cstdlib> 
#include <math.h>	// for lgamma function


#define HL 5730.0	// Half-life of C14, in years, after death
#define dpg 15.0	// degcays per gram per second

//double get_xvalue( void );
//double func(double x);

main(int argc, char *argv[])
{

	if(argc<3){
		cerr<< "usage: C14 [mass of C14 in grams][age of sample in years]"<<endl;
		exit(0);
		}


double P;
double mu;
double x;
double mass;	// in grams
double age;	// in years


mass = atof(argv[1]);
age = atof(argv[2]);

  mu = mass*dpg*exp(-(age)/(HL/log(2.0)))
  
return(pow(mu,x)*exp(-mu)/exp(lgamma(x+1.0)));		// Poisson Distribution equation

cout « mu << endl;}

/*
double get_xvalue( void )
{
	double x,W,fx,fxmax,xmax;
	
	fxmax = 1.0;  // this depends on the desired height of the function
			// it must bound the function from above
	xmax = 15.0; // this depends on the desired range of the function!
			// it must bound the function from the left
			// and if the range can go negative, then
			// it requires an offset translation of the result
	W = fxmax;
	fx = -99.;
	while(W>fx){   
		W = fxmax*(drand48());  // this samples the height
		x= xmax*drand48();  // this sets the range
		fx =  func(x);
	}
	return(x);
}



}	