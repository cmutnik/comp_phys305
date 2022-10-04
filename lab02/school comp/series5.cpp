//Value of series generated from e^(-z), using summation notation

using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions you need
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cstdio>	   // includes printf
#include <cmath>           // The standard C library math.h, has lots of pre-defined math functions



//calculates factorial to be called later
float fac(int k)
{
	double i;
	double fact = 1.0;
for (i=1.0; i<=k; i++)
{
fact *= i;
} 
return fact;
}

//calculate a term in the series
double expterm(int k, double z)
{
	double num;
{
num = pow(-z,k)/fac(k); //calling fac(k) defined above
}
return num;
}

//calculate using lgamma instead of my factorial
#include <math.h>		//for lgamma function
double actterm(int k, double z)
{
	double g;
{
g = pow(-z,k)/exp(lgamma(k+1));
}
return g;
}
	


//sum e^(-z) series
int main()
{
	double ans;
	double a;
	double k;
	double z;
	double d;
	double j;
	int iterations;
	double ferr;
	double ans2;
	double ans3;
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

	printf("%9d interation(s), difference = %20.18f\n",iterations,ferr);
//	printf("%9d interation(s), fractional error = %20.18f\n",iterations,ferr);     
}
//cout << "The value of this series with " << k << " terms is " << ans << endl; 
//return ans;
}
