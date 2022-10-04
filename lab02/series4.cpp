//summing the series for an inverse exponential

using namespace std;       
#include <iostream>        
#define _USE_MATH_DEFINES  
#include <cmath>
#include <cstdio>

int main()

{

	double k;
	double n;
	double fact=1.0;
	double ans;
	double x;
cout << "Enter value " << endl;
cin >> n;
for (k=1.0;k<=n;k++);

{
  fact*=k;
}

cout << "Value of " << n << " factorial is " << fact << endl;
cout << "Enter value of x" << endl;
cin >> x;
ans = pow(-x,n)/fact;
return ans;
}

