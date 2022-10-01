//meteor

using namespace std;       
#include <iostream>       
#include <iomanip>   // required to use "setprecision" if needed
#define _USE_MATH_DEFINES  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>		// for lgamma

main()
{
  
#define M 1000000
#define N 6000
 
  double *x, q;
  int *y;
  int i, j;
 

// now create  the memory with calloc, and cast it as a pointer to double:
   x = (double*)calloc(M, sizeof(double));
   y = (int*)calloc(M, sizeof(int));
   
q = 0.001;
srand48(15485867);	// sets seed value 
// random number where q was .01 not .001
    for(i=0;i<M;i++){
        x[i] = drand48();	

	y[i] = (x[i] > q ? 0.0 : 1.0);
//	fprintf(stdout,"%d    %f   %f\n", i,x[i],y[i]);
//cout << i << "\t" << x[i] << "\t" << y[i] << endl;
    }


// this re-bins number of meteors seen per minute   
    for(i=0; i<M-N; i+=N){
      for(j=i; j<i+N; j++){
	y[i/N]+=y[j];
      }
//      cout << i/N << "\t" << y[i/N] << endl;
    }

// need to re-bin to produce Noccur VS Nmeteor hisogram
int max = 14;		// looking at dat file the max
		     // number of meteors seen in any one minute is 14
int a;
int *z;
a = (M-N)/N;			// number of minutes (intervals)
    
   //make histogram, have to reset  everything to zero
    int hist[max];
    for(i=0; i<max; i++){
      hist[i] = 0;
    }
   
    for (i=0; i<a; i++){
      hist[y[i]]++;		// counter of "marbles"
    }
  
    for (i=0; i<=max; i++){
      cout << i << "\t" << hist[i] << endl;
    }
     
// free memory to avoid memory leaks 
    free(x);
      free(y);
 
  
}