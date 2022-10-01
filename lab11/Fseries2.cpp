//Value of series generated from e^(-z), using summation notation

using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions you need
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cstdio>	   // includes printf
#include <cmath>           // The standard C library math.h, has lots of pre-defined math functions
#define TMAX  1.0
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//sum series
main(int argc, char *argv[])
{
	if(argc<2){
		fprintf(stderr,"usage: Fseries [Ncoeff] > Fseries2.dat\n");
		exit(0);
		}

	int Ncoeff, n;
	double series, w, dt, fs, t;
	double Ast2 = 0.0;
	double Ast3 = 0.0;
Ncoeff = atoi(argv[1]);
	dt = 2.5e-3;               // 2.5 ms time step
	fs = 5.0;                  // 5 Hz frequency


  for(t=dt;t<TMAX;t += dt){




	series = 0.0;
	w = 2.0*M_PI*fs;

//cout << "Enter number of terms" << endl;
//cin >> Ncoeff;
	double Ast = (2.0/M_PI)*(sin(w*t) - (1.0/2.0)*sin(2.0*w*t) + (1.0/3.0)*sin(3.0*w*t) - (1.0/4.0)*sin(4.0*w*t) + (1.0/5.0)*sin(5.0*w*t) - (1.0/6.0)*sin(6.0*w*t) + (1.0/7.0)*sin(7.0*w*t) - (1.0/8.0)*sin(8.0*w*t) + (1.0/9.0)*sin(9.0*w*t) - (1.0/10.0)*sin(10.0*w*t) + (1.0/11.0)*sin(11.0*w*t) - (1.0/12.0)*sin(12.0*w*t) + (1.0/13.0)*sin(13.0*w*t) - (1.0/14.0)*sin(14.0*w*t) + (1.0/15.0)*sin(15.0*w*t) - (1.0/16.0)*sin(16.0*w*t) + (1.0/17.0)*sin(17.0*w*t) - (1.0/18.0)*sin(18.0*w*t) + (1.0/19.0)*sin(19.0*w*t) - (1.0/20.0)*sin(20.0*w*t) + (1.0/21.0)*sin(21.0*w*t));

		
	for(n=1;n<Ncoeff;n++){
 	double index1 = 1.0/((2.0*n)+1.0);
	double index2 = 1.0/(2.0*n);

	double odd = 0.0;
	double even = 0.0;
		odd += index1*sin(index1*w*t);
		even += index2*sin(index2*w*t);

		series = (2.0/M_PI)*(odd - even + sin(w*t));
		double ddd = 0.0;
		ddd += (sin(w*t) + (1/(2*n)+1)*sin((1/(2*n)+1)*w*t) - (1/(2*n))*sin((1/(2*n))*w*t));
 		ddd = (2.0/M_PI)*ddd;
cout << t << "\t" << series << "\t" << Ast << "\t" << Ast2 << "\t" << ddd << endl;
}
}
}




/*-------------------------------------------------------
cout << "Enter desired value of z" << endl;
cin >> z;
cout << "Enter number of terms " << endl;
cin >> k;
for (j=0.0; j<=k; j++)
{
ans += expterm(j,z); //this calls function defined above
ans2 += actterm(k,z);

ferr = abs((exp(z)-ans)/exp(z));

iterations = j+1;
  	printf("%9d interation(s), series sum = %20.18f\n",iterations,ans2);   
//	printf("%9d interation(s), fractional error = %20.18f\n",iterations,ferr);     
}
//cout << "The value of this series with " << k << " terms is " << ans << endl; 
//return ans;
}
*/
