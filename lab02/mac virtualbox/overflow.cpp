/*  check of machine underflow and overflow */
// PG 1/15/2013

using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions you need
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cmath>

main()    
{
	int N;  // no initialization since these are set later
	float over=1.0;  // these are floats (4 bytes) not doubles (8 bytes)
	float under=1.0;   
	// read in the value 
  	cerr << "Enter number of iterations:" << endl; 
  	cin >> N;

	for(int i=0;i<N;i++){
	    over = over*2.0;
	    under = under/2.0;
		cout << "iteration= " << i+1 << " over= " << over << " under= "<< under << endl;
	}    // end of for loop

 }   // end of main
