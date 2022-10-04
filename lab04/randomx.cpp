// Random x generator
using namespace std;       
#include <iostream>       
#include <cstdlib>	// this is a new include library, needed for conversions below
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath> 


int main()			
{
	int x;
        int i;
	int n;
//for (i=1.0; i<n; i++)
    x = rand();// % 100 + 1;	// Generate an integer between 1 and 100
 
    cout << "Random x = " << x << endl;
    return x;
}  