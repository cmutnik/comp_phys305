
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

  double mu=0.5;
  int k, max, P;

cout << "enter max k " << endl;
cin >> max;

for(k=1.0; k<=max; k++)
{
P +=  pow(mu,k)*exp(-1.0*mu)/exp(lgamma(k+1));
}

cout << P << endl;

}