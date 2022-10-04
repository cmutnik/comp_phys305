using namespace std;       
#include <iostream>       
#include <cstdlib>	// this is a new include library, needed for conversions below
#include <iomanip>   // this is required to use "setprecision" below
#include <fstream>
#define _USE_MATH_DEFINES  
#include <cmath>  

//ofstream myfile;
//double random(double , double );



int main()
{
/*  double ans;
  
  myfile.open("coor.txt");
  ans = random(x, y);
    cerr << "coordinates stored in coor.txt" << endl;
  myfile.close();
}
*/  
  
  
//double random (double x, double y)
//{
  double x;
  double y;
  const int N = 1000;
    for(int i=0.0; i<N; i++)
{
      x=drand48();
      y=drand48();
//    x=rand();
//    y=rand();

//myfile << x << "\t" << y << endl;
    cout << x << "\t" << y << endl;
}
return 0;
//return (random(x,y));
}