using namespace std;       
#include <iostream>       
#include <iomanip>   // required to use "setprecision" if needed
#define _USE_MATH_DEFINES  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>		// for lgamma


main()
{

#define M 100
#define N 10

    double q;
    double *x, *y,  *img; // declare these as pointers to doubles
    int i,j;

// now create  the memory with calloc, and cast it as a pointer to double:
   x = (double*)calloc(M, sizeof(double));
   y = (double*)calloc(M, sizeof(double));
/*
// for the image array, do it as a single vector for now and use
// indexing to get to the rows and columns, see below
    img = (double*)calloc(N*N, sizeof(double)); 
*/
    for(i=0;i<M;i++){
        x[i] = drand48();
	  q = 0.01;
//        y[i] = ;
//cout << i << x[i] << (x > q ? 0.0 : 1.0) << endl;
	    fprintf(stdout,"%d    %f   %f\n", i,x[i],(x[i] > q ? 0.0 : 1.0));
    }
/*   
    fprintf(stdout,"\n\n");
   
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           
            img[j+N*i] = j+N*i;
    fprintf(stdout,"%d  %d   %f\n", i,j,img[j+N*i]);
        }
    }
*/
    free(x); free(y);  free(img); 
    // free the memory to avoid dreaded memory leaks!!!


}