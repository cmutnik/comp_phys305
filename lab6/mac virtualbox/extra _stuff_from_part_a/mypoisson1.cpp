using namespace std;       
#include <iostream>       
#include <iomanip>   // required to use "setprecision" if needed
#define _USE_MATH_DEFINES  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>		// for lgamma

main()
{
double P;
double mu=0.5;
double a;
int k;
cout << "enter value of k" << endl;
cin >>k;
a = pow(mu, k);
cout << a << endl;
}