// hypersphereMC: a monte-carlo integration of a hypersphere volume 
// P. Gorham, updated 2/10/2015 for Physics 305 
// requires student completion 

using namespace std;       
#include <iostream>       
#include <iomanip>   // required to use "setprecision" if needed
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>      
#include <stdlib.h>
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
/*	        for (int i=0; i<NDIM; i++){		  
     if(r[i]<=1.0)outfile << NDIM << " " << r[i] <<endl;
   }
   outfile << "\n\n";
	    
		for (int i=0; i<NDIM; i++){		// write results into file, hits outside circle      
     if(r[i]>1.0) outfile << NDIM << " " << r[i] <<endl;
*/
n++;	// counter for Ntrials while loop
     
	    }  //---------END OF WHILE LOOP-----------------
	
//	Vtot = D;
		// Vtot=D for 1-dimensional "hypercube" (a line)
//	 for(int i=1;i<NDIM;i++){
	       Vtot = pow(2.,NDIM);
	       //interative multiplication to get N-dim hypercube
//	    }
	
cout << hits << " " << Ntrials << endl;

	      Vsphere = (hits/Ntrials)*Vtot;
	  
	      
	 Vtrue = pow(PI, NDIM/2.)/tgamma((NDIM/2)+1);
/*	Vtrue = A;
 	 {
	   for(int i=1;i<NDIM;i++){
	      A = pow(PI, NDIM/2.)/tgamma((NDIM/2)+1);
	      return A;
	    }
	 }
*/
	 
	 cout << NDIM <<" dimensions, Vsphere= "<< Vsphere <<
	 		"  Vtot= "<< Vtot <<" fractional error= "<< (Vtrue-Vsphere)/Vtrue <<endl;



}
