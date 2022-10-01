//Value of series generated from e^(-z), using summation notation

using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions you need
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cstdio>
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
	double err;
cout << "Enter desired value of z" << endl;
cin >> z;
cout << "Enter number of terms " << endl;
cin >> k;
for (j=0.0; j<=k; j++)
{
ans += expterm(j,z); //this calls function defined above

err = abs((exp(z)-ans)/exp(z));
iterations = j+1;
       
        printf("%9d iteration(s), causes fractional error = %20.18f\n",iterations,err);
}
//cout << "The value of this series with " << k << " terms is " << ans << endl; 
//return ans;
}
