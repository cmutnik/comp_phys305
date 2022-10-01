// simple harmonic oscillator using external Runge-Kutta function
// Corey Mutnik 3/15
// modified from: P. Gorham, originally 3/6/2003 for UH Physics 305, updated 3/14/2007

/* updated 3/17/07 to use modified Runge-Kutta code that repaired
  a subtle bug:  FRK2xv.c --PG */
  
//  -- updated to c++ 3/10/2013 --PG 


using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 

#define Tmax  50                  // seconds


extern double FRK2xv(int, double (*)(double, double, double), 
				   double (*)(double, double, double), 
				   double ,double ,double ,double );
double  f_x(double, double, double), f_v(double, double, double);

main( int argc, char *argv[])
{
  double xt0,t0,vt0,vt,xt,t,dt,xtold,vtold, dE, E, dEperE;
  double k,m,w,xtrue,vtrue;
  
   ofstream outfile;  
   
	outfile.open("oscRK1.dat");
	
// program wont run unless proper command life parameters are set  
if(argc<2){
		cerr<< "usage: harmonic oscillator [time interval, dt]"<<endl;
		exit(0);
		}
// modify program to accept time interval as a command line parameter
	dt = atof(argv[1]);

	k = 1.0;                   // spring constant
	m = 1.0;                   // mass in kg
	w = sqrt(k/m);
	
	xt0 = 1.0;                 // initial position
	t0 = 0.0;                  // initial time
	vt0 = 0.0;                 // initial velocity
//	dt = 0.1;

	xtold = xt0;               // set & print the initial conditions
	vtold = vt0;
	t = t0;

	dEperE = 0.0;
	dE = 0.0;
	double Ei = (0.5*m*pow(vt0,2.0)) + (0.5*k*pow(xt0,2.0));
	double T = 2.0*M_PI/w;
	
	outfile << t << "\t" << xt0 << "\t" << vt0 << "\t" << xtrue << "\t" << vtrue << "\t" << dEperE/T << "\t" << Ei << endl;


	
/* Here is the loop that propagates the motion:
	vt is the new time, vtold the previous step time;
	xt is the new position, xtold the previous;
	after each step is calculated, the old is set
	to the new, and the cycle is repeated  */

	for(t=t0; t<Tmax; t+= dt){

		xt = xtold + FRK2xv(0,f_x,f_v,t,xtold,vtold,dt);
		vt = vtold + FRK2xv(1,f_x,f_v,t,xtold,vtold,dt);
		
		double dv = vt - vtold;
		double dx = xt - xtold;
		
		xtrue = xt0*cos(w*t);
		vtrue = vt0  + -sin(w*t);

		xtold = xt;
		vtold = vt;
		E = (0.5*m*pow(vtrue,2.0)) + (0.5*k*pow(xtrue,2.0));
//		dE = (0.5*m*pow(dv,2.0)) + (0.5*k*pow(dx,2.0));
		
		
		if(t>=(Tmax-T)){
		  double Etot = (0.5*m*pow(vt,2.0)) + (0.5*k*pow(xt,2.0));
		  double Ef = abs(E-Etot)/E;
		  dEperE += Ef;
		}
		
		outfile << t << "\t" << xt << "\t" << vt << "\t" << xtrue << "\t" << vtrue << "\t" << dEperE/T << "\t" << E <<endl;
	   }

		// modification to plot (fractional energy change in one period of the oscillator) vs (frac osc period that time interval dt fills)
//		cout << (dt/T) << "\t" << ((dE/E)/T) << endl;
		cout << (dt/T) << "\t" << ((dEperE)/T) << endl;
}

/* the following is just the formal definition: f(x) = dx/dt == v */
double f_x(double t, double x, double v)
{
	return(v);
}

/* this is where the action is: should contain the force law: dv/dt = f(t,x,v) */
double f_v(double t, double x, double v)
{
	double k = 1.0, m=1.0;

	return( -k/m*x );
}



