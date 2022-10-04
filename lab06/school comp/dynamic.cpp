

using namespace std;       
#include <iostream>        
#define _USE_MATH_DEFINES  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{

#define M 100
#define N 10

    double *x, *y,  *img; // declare these as pointers to doubles
    int i,j;

// now create  the memory with calloc, and cast it as a pointer to double:
   x = (double*)calloc(M, sizeof(double));
   y = (double*)calloc(M, sizeof(double));

// for the image array, do it as a single vector for now and use
// indexing to get to the rows and columns, see below
    img = (double*)calloc(N*N, sizeof(double)); 

    for(i=0;i<M;i++){
        x[i] = i;
        y[i] = i*i;
    fprintf(stdout,"%d    %f   %f\n", i,x[i],y[i]);
    }
   
    fprintf(stdout,"\n\n");
   
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           
            img[j+N*i] = j+N*i;
    fprintf(stdout,"%d  %d   %f\n", i,j,img[j+N*i]);
        }
    }
    free(x); free(y);  free(img); 
    // free the memory to avoid dreaded memory leaks!!!

}

