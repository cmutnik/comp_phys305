// simple harmonic oscillator using Euler's method 
// Corey Mutnik 3/3/15
// Modified from: P. Gorham, updated March 2013 for UH Physics 305

#include <iostream>
#include <iomanip>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 
using namespace std;

#define Tmax  50     // seconds for integration


main(int argc, char *argv[])
{
  double k,m,xt0,t0,vt0,w,vtii,xtii,t,dt,xti,vti, xtrue,vtrue, E, dEperE;
  double dE = 0;
   ofstream outfile; 
   
   	outfile.open("osc1.dat");
	outfile.precision(5);         // set the precision for output
	
// program wont run unless proper command life parameters are set  

if(argc<1){
		cerr<< "usage: harmonic oscillator [time interval, dt]"<<endl;
		exit(0);
		}


//modify program to accept time interval as a command line parameter
	dt = atof(argv[1]);

	k = 1.0;                   // spring constant
	m = 1.0;                   // mass in kg
	w = sqrt(k/m);
	xt0 = 1.0;                 // initial position
	t0 = 0.0;                  // initial time
	vt0 = 0.0;                 // initial velocity


	xti = xt0;               
	vti = vt0;
	t = t0;
//	E = (0.5*m*pow(vt0,2.0)) + (0.5*k*pow(xt0,2.0));
	double T = 2.0*M_PI/w;
	
//inital conditions
	//outfile << t0 << "  " << xt0 << "  " << vt0 << "  " << xtrue << "  " << vtrue << "\t" << dE/E << "\t" << E << endl;

/* Here is the loop that propagates the motion:
	vtii is the velocity at the new time, vti the previous step time;
	xtii is the new position, xti the previous;
	after each step is calculated, the old is set
	to the new, and the cycle is repeated  */

	for(t=t0; t<Tmax; t+= dt){
		vtii = vti + dt*(-k/m)*xti;
		xtii = xti + dt*vti;
		double dv = vtii - vti;
		double dx = xtii - xti;
		xti = xtii;  // set the old values to the new ones for next step
		vti = vtii;
		xtrue = xt0*cos(w*t);
		vtrue = vt0  + -sin(w*t);
		E = (0.5*m*pow(vtrue,2.0)) + (0.5*k*pow(xtrue,2.0));
		//double E2 = (0.5*m*pow(vtii,2.0)) + (0.5*k*pow(xtii,2.0));
		//dE += (0.5*m*pow(dv,2.0)) + (0.5*k*pow(dx,2.0));

		if(t>=(Tmax-T)){
		  double Etot = (0.5*m*pow(vtii,2.0)) + (0.5*k*pow(xtii,2.0));
		  double Ef = abs(E-Etot)/E;
		  dEperE += Ef;
		}
		
		outfile << t << "  " << xtii << "  " << vtii << "  " << xtrue << "  " << vtrue << endl; // << "\t" << (dEperE/T) << "\t" << E2 << endl;

	}		
		// modification to plot (fractional energy change in one period of the oscillator) vs (frac osc period that time interval dt fills)
//		cout << (dt/T) << "\t" << ((dE/E)/T) << endl;
	  		cout << (dt/T) << "\t" << ((dEperE)/T) << endl;
//	}


}