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
#define decays 15.0	// degcays per gram per second

double func(double mu, double x);







main(int argc, char *argv[])
{

	if(argc<4){
		cerr<< "usage: C14 [mass of C14 in grams][age of sample in years][nTrials]"<<endl;
		exit(0);
		}

double mass;	// in grams
double age;	// in years
double nTrials, x, i, fx, W, mu;
double *arr;
srand48(15485863);

  mass = atof(argv[1]);
  age = atof(argv[2]);
  nTrials = atoi(argv[3]);

  mu = mass*decays*exp(-(age)/(HL/log(2.0)));
//  cout << mu << endl;
  arr = new double[20]();
  

for(i=0;i<nTrials;i++){
	x = (int)(14*drand48());	// 14 was the max number of meteors per minute in lab 6a
	fx = func((double) x, mu);
	W = drand48();
		if(W<fx){
		  arr[(int) x]+=1;
		  }
		}
	for(int i=0;i<20;i++){
	    cout << i << "\t" << arr[i] << endl;
	}
  
}
// Poisson Distribution function
double func(double x, double mu)
{	
	return(pow(mu,x)*exp(-mu)/exp(lgamma(x+1.0)));
}
