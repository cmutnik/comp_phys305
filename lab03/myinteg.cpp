// Integrate acoustic energy

using namespace std;       
#include <iostream>       
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>           

#define max_in  600000                  // sets max number of intervals
#define vmin -6.0                        // sets lower limit of integration
#define vmax 6.0			// sets upper limit of integration
#define ME M_E				// Euler's number

# define RHO 1.2			// RHO is the density of air in kg/m^(3)
# define c 340.0			// c is the speed of sound in m/s
# define AMP 20.0			// A is the amplitude of the pressure pulse in Pa

double trapez (int no, double min, double max);		// trapezoid rule
double psq(double);					// pressure squared
ofstream myfile;  					// declare a new instance of an output stream, call it "myfile"

main()
{
    double result;
    myfile.open("myinteg4.dat");  			// open is now a method within ofstream class instance outfile
    result = trapez(max_in, vmin, vmax);
    cout << "Answer= " << setprecision(12) << result << endl;
    cerr << "data stored in myinteg4.dat" << endl;
  myfile.close();					// close the file, disable any more writing to it, button it up
}


/*------------------------end of main program-------------------------*/


// the function we want to integrate
double psq (double t)

{ 
return pow(cos(pow(2*M_PI*t,3.))*exp(-pow(t/4.,8.))*AMP,2.);  // this function for chirp where 2pi is omega in rad/sec and t is time
}


/* Integration using trapezoid rule */
double trapez (int no, double min, double max)
{			
   double interval, sum=0.0, t;		 

   interval = ((max-min) / (no-1.0));  // interval is same as "dt" in integral, max-min is change in time (delta t), no-1. is number of samples
   sum += 0.5 * psq(min) * 1.0/(RHO*c) * interval; 	// add the first point
   for (int n=2; n<no; n++)           			// sum the midpoints
   {
      t = min + interval * (n-1.0);      
      sum += psq(t) * 1.0/(RHO*c) * interval;
      myfile << t << "\t" << setprecision(12) << sum << endl;		// "\t" here gives a tab
   }
   sum += 0.5 * psq(max) * 1.0/(RHO*c) * interval;			// add the endpoint

   return (sum);
}  
