// c++ program to estimate value of pi
#include <iostream>
#include <cmath>             //includes math package
using namespace std;        //need for all programs

int main()
{
    int k;
    double val=0.0 , fval;
    double den=1;
    int num;

cout << "Enter Number of Terms" << endl;   
cin >> num;
for (k=1;k<=num;k++)
{

val = val+ ( pow(-1,k+1)/den );    //causes the series to alternate between positive and negative signs
den = den+2;                               //changes the summation index, in order to generate each subsequent term in series

}

fval = 4*val;                                //series is pi/4 so we multiply generated answer by 4, to get the value of pi

double err=abs(M_PI - fval);
cout << "Estimate for Pi is " << fval << ", Associated Error " << err << endl;

return 0;
}
