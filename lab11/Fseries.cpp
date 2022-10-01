/*  fourier series approximations to some simple signals */
// g++ Fseries.cpp -o ~/bin/Fseries

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI M_PI
#define TMAX  1.0

main(int argc, char *argv[])
{


	double dt,fs,a[50],b[50],t,told,Ast,Astold,Aft,Aftold,w,a0, fsaw;
	int Ncoeff,i,n,smod,start,cont;


	if(argc<2){
		fprintf(stderr,"usage: Fseries [Ncoeff] > Fseries.dat\n");
		exit(0);
		}


	Ncoeff = atoi(argv[1]);    // number of coefficients to use

	dt = 2.5e-3;               // 2.5 ms time step
	fs = 5.0;                  // 5 Hz frequency
	fsaw = 2.4e-9;			// sawtooth freq in GHz

/*	
	fprintf(stderr,"Input dc value a0:\n");
	  fscanf(stdin,"%lf", &a0);
  	fprintf(stderr,"Input %d cosine coefficients:\n",Ncoeff);
	  for(i=0;i<Ncoeff;i++)fscanf(stdin,"%lf", a+i);
  	fprintf(stderr,"Input %d sine coefficients:\n",Ncoeff);	
	  for(i=0;i<Ncoeff;i++)fscanf(stdin,"%lf", b+i);
*/
	  fprintf(stderr,"Input dc value a0 (enter 1):\n");
	  fscanf(stdin,"%lf", &a0);
  	fprintf(stderr,"Input %d odd sine term coeffs:\n",Ncoeff);
	  for(i=0;i<Ncoeff;i++)fscanf(stdin,"%lf", a+i);
  	fprintf(stderr,"Input %d even sine term coefficients:\n",Ncoeff);	
	  for(i=0;i<Ncoeff;i++)fscanf(stdin,"%lf", b+i);

	t = dt; told = 0.0; Astold = 0.0; Aftold = 0.0;
	start = 1;

		
	  for(t=dt;t<TMAX;t += dt){
	
		// create the half sine wave of frequency fs

		w = 2.0*PI*fsaw;   // the angular frequency
//		Ast = sin(w*t);  
//		if(Ast<0.0) Ast = 0.0;
//		Ast = (2.0/M_PI)*(sin(w*t) - (1.0/2.0)*sin(2.0*w*t) + (1.0/3.0)*sin(3.0*w*t) - (1.0/4.0)*sin(4.0*w*t) + (1.0/5.0)*sin(5.0*w*t) - (1.0/6.0)*sin(6.0*w*t) + (1.0/7.0)*sin(7.0*w*t) - (1.0/8.0)*sin(8.0*w*t) + (1.0/.0)*sin(9.0*w*t));
 double T = 1.0/fs;
        Ast = 10.0*fmod((t+0.5*T),T)-1.0;  



		

	   // the Fourier series is a sum of cos & sin harmonics
           //----------here is the series sum-----------
		Aft = 0.0;
		for(n=1;n<=Ncoeff;n++){
			Aft +=  a[n-1]*cos(n*w*t) + b[n-1]*sin(n*w*t);
			}
			Aft += a0/2.;    // add the DC value





		// write out the data
		fprintf(stdout,"%e %e %e\n",t, Ast, Aft);
		
		// these lines set the old values to the newer ones
		Astold = Ast;
		Aftold = Aft;
		told = t;
		start = 0;
	  }


	

}

