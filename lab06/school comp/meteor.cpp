// meteor counting
using namespace std;       
#include <iostream>        
#include <iomanip>		// requires for "setprecision"
#define _USE_MATH_DEFINES  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{

#define M 100
#define N 10

    double *x, *y,  *img; // declare these as pointers to doubles
    double q;    
	int i,j;

// now create  the memory with calloc, and cast it as a pointer to double:
   x = (double*)calloc(M, sizeof(double));
   y = (double*)calloc(M, sizeof(double));

// for the image array, do it as a single vector for now and use
// indexing to get to the rows and columns, see below
    img = (double*)calloc(N*N, sizeof(double)); 
q=0.01;
    for(i=0;i<M;i++){
        x[i] = drand48();
        y[i] = (x[i] > q ? 0.0 : 1.0);
    fprintf(stdout,"%d    %f   %f\n", i,x[i],y[i]);
    }
/*   
    fprintf(stdout,"\n\n");
   
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           
            img[j+N*i] = j+N*i;
    fprintf(stdout,"%d  %d   %f\n", i,j,img[j+N*i]);
        }
    }
    free(x); free(y);  free(img); 
    // free the memory to avoid dreaded memory leaks!!!
*/
}



/*
double *x;
double q;
int i;

	for(i=0;i<M;i++)
	  x[i] = drand48();
	  q = 0.01;

cout << i << x[i] << (x > q ? 0.0 : 1.0) << endl;
*/

