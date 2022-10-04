// hypersphereMC: a monte-carlo integration of a hypersphere volume 
// C. Mutnik student completion 2/10/15
// from P. Gorhams, updated 2/10/2015 for Physics, 305 code

using namespace std;       
#include <iostream>       
#include <iomanip>   // required to use "setprecision" if needed
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>      
#include <stdlib.h>
#include <math.h>	// for tgamma
#define PI M_PI

main(int argc, char *argv[])
{

	double hit,xi,R,Rsq,D,R_D,Vtot,Vsphere, A, Vtrue, r;
	double hits=0.0;
	int n,i,NDIM=3, Ntrials=1000000;
	
	srand48(1299811); // a large prime

	/* usage: NDIM = # of dimensions, NMAX=number of sample points */
	if(argc<2){
		cerr<< "usage: hypersphereMC [NDIM][NMAX]"<<endl;
		exit(0);
		}
	
	NDIM = atoi(argv[1]); // number of dimensions
	Ntrials = atoi(argv[2]); // number of trials



	D= 2.0;		// side of hypercube needed to contain hypersphere
	R_D = 1.0;	// radius of hypersphere
	hit = 0.0;	// the counter for events within sphere
	n=0;		// initialize the loop counter
	
	//-------this is the main loop----------------------

	while(n<Ntrials){  // continue generating coordinates up to Ntrials
	    Rsq = 0.0;  // this variable accumulates the square of each coordinate
	    double r[NDIM];

	    for(int i=0;i<NDIM;i++){
		   
	xi = (drand48()-0.5)*2.; // uniform random value +/-[0,1] in each coordinate
	Rsq += pow(xi,2.);	// sum up the squares
	
		} // end of NDIM loop------------
R = sqrt(Rsq); // calc radius
	hits += R<=1.0 ? 1.0 : 0.0;
	//hits += R<=R_D ? 1.0 : 0.0;
	
n++;	// counter for Ntrials while loop
     
	    }  //---------END OF WHILE LOOP-----------------
	    
	       Vtot = pow(2.,NDIM);
	       //Vtot = pow(D,NDIM);

	      Vsphere = (hits/Ntrials)*Vtot;
	  	      
//	 Vtrue = (pow(M_PI,NDIM/2.)/tgamma((NDIM/2.)+1.))*pow(R_D,NDIM);  // R_D=1 so pow(R_D,NDIM)=1
 Vtrue = pow(M_PI,NDIM/2.)*(1/exp(lgamma((NDIM/2.)+1.)))*pow(R_D,NDIM); // using lgamma	 
	 cout << NDIM <<" dimensions, Vsphere= "<< Vsphere << " Vtrue= " << Vtrue <<
	 		"  Vtot= "<< Vtot <<" fractional error= "<< abs(Vtrue-Vsphere)/Vtrue <<endl;

}
