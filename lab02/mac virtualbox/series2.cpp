//summing the series for an inverse exponential

using namespace std;       
#include <iostream>        
#define _USE_MATH_DEFINES  
#include <cmath>
#include <cstdio>

int main()

{

	double k;
	double den;
	double fact=1.0;
cout << "Enter value " << endl;
cin >> den;
for (k=1.0;k<=den;k++);

{
fact*=k;
}
cout << "Value of " << den << " factorial is " << fact << endl;

return 0;
}

