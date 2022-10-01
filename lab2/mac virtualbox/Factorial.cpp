//Value of a factorial

using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions you need
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cstdio>
#include <cmath>           // The standard C library math.h, has lots of pre-defined math 				//functions
int main()
{
	double i;
	double k;
	double fact = 1.0;

cout << "Enter number of terms " << endl;
cin >> k;
for (i=1.0; i<=k; i++)
{
	fact *= i;
}

cout << "The value of " << k << "! is " << fact << endl;  

return fact;
}
