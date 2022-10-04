using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions you need
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cmath>           // The standard C library math.h, has lots of pre-defined math functions

int main()
{
    double answer=1;
    double denom=3;
    int num;
    int i;
    cout << "Enter number of terms " << endl;
    cin >> num;
    for(i=1; i<num; i++){
        answer=answer + pow(-1,i)/denom;
        denom=denom + 2;
    }
    answer=answer*4;
     double error=abs(M_PI - answer);
    cout << "Result " << answer << "Error " << error << endl;
    return 0;
}
