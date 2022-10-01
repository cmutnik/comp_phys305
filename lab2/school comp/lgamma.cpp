//lgamma

using namespace std;		// sets up some standard names for things
#include <iostream>		// This is  library containing input-output functions you need
#define _USE_MATH_DEFINES	// tells the compiler to define math constants (like pi) for you
#include <cstdio>
#include <math.h>		//for lgamma function
#include <cmath>           	// The standard C library math.h, has lots of pre-defined math functions
double lgamma(int x);		//before int main, so tell program to look for lgamma(x)


int main()
{
	double fact;
	double i;
	double k;
cout << "Enter number of terms" << endl;
cin >> k;
for (i=1.0; i<=k; i++)
{
//lgamma returns natural loq in input lgamma(x) = ln((x-1)!)
//exp returns exponent of the input	
fact = exp(lgamma(k+1));
}
cout << "The factorial of " << k << " is " << fact << endl;
return fact;
}
