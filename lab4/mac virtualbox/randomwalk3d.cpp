/* 
 * ORIGINAL CODE:
************************************************************************
*  walk.c: Random walk simulation                                      *
*								       *
*  taken from: "Projects in Computational Physics" by Landau and Paez  * 
*	       copyrighted by John Wiley and Sons, New York            *      
*                                                                      *
*  written by: students in PH465/565, Computational Physics,           *
*	       at Oregon State University                              *
*              code copyrighted by RH Landau                           *
*  supported by: US National Science Foundation, Northwest Alliance    *
*                for Computational Science and Engineering (NACSE),    *
*                US Department of Energy 	                       *
*								       *
*  UNIX (DEC OSF, IBM AIX): cc walk.c -lm                              *
*    			                                               *
*  comment: If your compiler complains about drand48, srand48          *
*           uncomment the define statements further down               *
*           Data is saved as sqrt(steps), distance                     *
************************************************************************
*/
/* MODIFIED VERSION:
 * modified to print out the number of steps i rather than sqrt(i).
   P. Gorham 2/5/2004, some updates 2/9/2010 */
// modified 1/29/2013 converted to c++ --P. Gorham
// 2/4/14: use better circle point-picking algorithm --PG
// g++ walkrandom.cpp -o walkrandom 

using namespace std;       
#include <iostream> 
#include <iomanip>   
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>   
#include <cstdlib> 
                      
#define SQRT2 M_SQRT2  // use the cmath definition...
#define max 100000  	// unnecessarily defined max
int seed = 94180717;  // change the seed if you want different results!

main(int argc, char *argv[])
{
   int i, j, Jrand, Nmax=100000;	// had to change to 100,000
   double ranangle, x, y, u, z, phi, r[Nmax+1], Ntrials=10000.; // Ntrials is the number of paths to try 
			    // ^replace "max" with "Nmax¨
   if(argc > 1) {
      seed = atoi(argv[1]);  // argv[1] since argv[0] contains the program name!
      Ntrials = atoi(argv[2]);	// adds Ntrials to command line position 3
      Nmax = atoi(argv[3]);	// adds Nmax to command line in position 4
       cerr << "Using user seed= "<< seed <<endl;     
   }else{
      cerr << "Using default seed= "<< seed <<endl;
   }
   
   ofstream outfile, outpath; 
   outfile.open("walk3dc.dat"); 
   outpath.open("walkpath3dc.dat");
   outpath << "0 0.0 0.0" <<endl;

   
   srand48(seed);                       // seed the number generator 
   					// if the seed is the same the randoms
					//   will also be the same 			   
   Jrand =  (int)(drand48()*Ntrials); // pick one path to print out 
   
   for (i=0; i<=Nmax; i++) r[i]=0.0;     // clear array 
   
   for (j=1; j<=(int)Ntrials; j++){      // average over NTRIALS trials 
      x=y=z=0;                            // starting point  
      for (i=1; i<=Nmax; i++){
	  ranangle = (drand48()*2.*M_PI);
	  phi = (drand48()*2.*M_PI);
	  u =  cos(phi);
	  x += pow((1-u*u),0.5)*cos(ranangle);
	  y += pow((1-u*u),0.5)*sin(ranangle);
	  z += u;
	  r[i] += sqrt(x*x + y*y + z*z);

	 
	 if(j==Jrand){  // print out a random trial path for plotting:
	 	outpath <<  i <<" "<< x <<" "<< y <<" "<< z <<endl;
	    }
		
      }
//      cout << x << "\t" << y << "\t" << z << endl;		// output endpoints
   }
   
   for (i=0; i<=Nmax; i++){		// write results into file, including standard error     
      outfile<< i << "  "<<r[i]/Ntrials << "  "<<sqrt(Ntrials)/Ntrials * r[i]/Ntrials << endl;
   }
   cerr << "data stored in walk3dc.dat"<< endl;
   cerr << "path #"<<Jrand<<" stored in walkpath3dc.dat"<<endl;
   outfile.close();
   outpath.close();
}
 
