//summing the series for an inverse exponential



using namespace std;       
#include <iostream>        
#define _USE_MATH_DEFINES  
#include <cmath>
#include <cstdio>
int fakt(int n);

int main()

{

  int k;
  int n;
  int fac;

cout << "Enter non-negative integer" << endl;
cin >> n;
for (k=0; k<=n; k++);

{
    fac *= k;
    //if (i == 0)
    //factorial =1;
    //else
    //factorial = factorial*i;
}

cout << "Value of " << n << "! is " << fac << endl;

return fac;
}
