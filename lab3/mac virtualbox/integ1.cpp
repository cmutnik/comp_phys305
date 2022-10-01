/* 
************************************************************************
*  integ.c:  Integration using trapezoid, Simpson rules      *
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
*  UNIX (DEC OSF, IBM AIX): cc integ.c -lm                             *
*    			                                               *
*  comment: The derivation from the theoretical result for each method *
*           is saved in x y1 y2 y3 format.			       *
*       
*   Modified 1/21/2013 to c++ for Physics 305, UH Manoa, P. Gorham             *
************************************************************************
*/

using namespace std;       
#include <iostream>       
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>           

#define max_in  3001                  // max number of intervals 
#define vmin 0.0                        // ranges of integration 
#define vmax 6.0			
//#define ME 2.7182818284590452354E0      // Euler's number 
// Since we used the math defines above, we can just use M_E for Euler's number...
#define ME M_E

float trapez  (int no, float min, float max);    // trapezoid rule 
float simpson (int no, float min, float max);    // Simpson's rule 
float f(float);		        	//  contains function to integrate 

main()
{		 
   float result; // declare this within scope of main
   ofstream myfile;  // declare a new instance of an output stream, call it "myfile"
   
 
   myfile.open("integ.dat");  // open is now a method within ofstream class instance outfile
   
   for (int i=3; i<=max_in; i+=2){	   // Simpson's rule requires odd number of intervals
      result = trapez(i, vmin, vmax);
      myfile << i <<"\t"<< setprecision(9) << result <<"\t";  // "\t" here gives a tab
      result = simpson(i, vmin, vmax);
      myfile << setprecision(9) << result << endl;
   }
   cout << "data stored in integ.dat" << endl;
   myfile.close();  // close the file, disable any more writing to it, button it up.
}
/*------------------------end of main program-------------------------*/

// the function we want to integrate 
float f (float x)
{ 
return cos(pow(x,5.))*exp(-pow(x/4.,8.));  // this function for chirp
//return (exp(-x));    // this is exponential
}

/* Integration using trapezoid rule */
float trapez (int no, float min, float max)
{			
   float interval, sum=0., x;		 

   interval = ((max-min) / (no-1));  // this is equivalent to "dt" or "dx" in integral
   
   sum += 0.5 * f(min) * interval; // add the first point
   for (int n=2; n<no; n++)           	// sum the midpoints 
   {
      x = min + interval * (n-1);      
      sum += f(x)*interval;
   }
   sum += 0.5 *f(max) * interval;	// add the endpoint 

   return (sum);
}      

/* Integration using Simpson's rule */ 
float simpson (int no, float min, float max)
{  				 
   float interval, sum=0., x;
   interval = ((max -min) /(no-1));
   
   for (int n=2; n<no; n+=2)                // loop for odd points  
   {
       x = min + interval * (n-1);
       sum += 4 * f(x);
   }
   for (int n=3; n<no; n+=2)                // loop for even points  
   {
      x = min + interval * (n-1);
      sum += 2 * f(x);
   }   
   sum +=  f(min) + f(max);	 	// add first and last value          
   sum *= interval/3.;        		// then multilpy by interval
   
   return (sum);
}  

