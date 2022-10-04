using namespace std;
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>

// function that gives the terms of the summation for an approximation of e^z
double expterm(double a, double b)
{
    double i, result;
   
    // loop that calculates b factorial
    double fact = 1.0;
    for (i=1.0; i<=b; i++)
    {
        fact *= i;
    }
   
// calculate b factorial using built in factorial function where    
    // lgamma(x)=ln[(x-1)!]
    //double fact;
    //fact = exp(lgamma(b+1));
   
    result = (pow(a,b))/fact; // algorithm from "Computational Physics" by Landau and Paez page 30
    return result;
}