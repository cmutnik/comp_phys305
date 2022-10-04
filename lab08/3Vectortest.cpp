// c++ program to test 3Vector typedef
using namespace std;       
#include <iostream>        
#define _USE_MATH_DEFINES  
#include <cmath>  
#include "3Vector.h"        

int main()
{                  // begin the main program body
	 vec3 v1,v2,v3;
	 v1.x = 3.0; v1.y = 6.0; v1.z = 9.0;
	 v3.x = 2.0; v3.y = 4.0; v3.z = 6.0;
	 	 
	double v1dotv3 = vec3dot(v1,v3);
	cout << "v1 dot v3 = "<<v1dotv3<<endl;
	
}  