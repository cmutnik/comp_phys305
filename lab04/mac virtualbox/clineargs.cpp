using namespace std;       
#include <iostream>       
#include <cstdlib>	// this is a new include library, needed for conversions below
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>  

int main (int argc, char *argv[])
{
  int i;
  int Ival = atoi(argv[1]);
  double Fval = atof(argv[2]);
    for (i=0; i < argc; i++)
      cerr << "argv " << i << " = " << argv[i] << " atoi(argc["<<i<<"]) = " << atoi(argv[i]) << endl;
return 0;
}