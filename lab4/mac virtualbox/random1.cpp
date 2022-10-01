using namespace std;       
#include <iostream>       
#include <cstdlib>	// this is a new include library, needed for conversions below
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>  

int main()
{
  double x;
  double y;
  int i;
  int n;
  const int N = 100;

    for(i=0.0; i<N; i++)
    x=rand();
    y=rand();

cout << x << "\t" << y << endl;

return 0;
}