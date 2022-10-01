// pond3.cpp to check MC integration of unit radius sphere volume
// P. Gorham 2/10/15 for Physics 305 UH Manoa
// Based on Landau Paez & Bordeianu code ch. 11
using namespace std;       
#include <iostream>       
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath> 
#include <cstdlib> 
                     
#define PI  M_PI
#define max 1000
#define seed 681111

main()
{
   double x[max], y[max], z[max], r[max];  // allocate arrays
   double  hits=0.0, ntrials=0.0;
   
   ofstream outfile;  
   outfile.open("pond3.dat"); 
   
   srand48(seed);                       // seed the number generator 
   
      for (int i=0; i<max; i++){
         x[i] = (drand48()-0.5)*2.;      // x, y, and z between 
         y[i] = (drand48()-0.5)*2.;      // -1 and 1 
         z[i] = (drand48()-0.5)*2.;
         r[i] = sqrt(x[i]*x[i] + y[i]*y[i] + z[i]*z[i]);        // distance from origin 
	 hits += r[i]<=1.0 ? 1.0 : 0.0;  // conditional expression
	 ntrials += 1.0;
      }
    double vol = (hits/ntrials)*pow(2.,3.);
   cout << "Volume of inscribed sphere= "<< setprecision(9) <<
   		vol <<" , fractional error= "<< setprecision(9) << fabs((vol-PI)/PI) <<endl;
      
   for (int i=0; i<max; i++){		// write results into file, hits within circle     
     if(r[i]<=1.0)outfile << x[i]<<" "<< y[i] << " " << z[i] <<endl;
   }
   outfile << "\n\n";
   for (int i=0; i<max; i++){		// write results into file, hits outside circle      
     if(r[i]>1.0) outfile << x[i]<<" "<< y[i] << " " << z[i] <<endl;
   } 
 

	cerr << "data stored in pond3.dat" << endl;
   outfile.close();
 
}
 
