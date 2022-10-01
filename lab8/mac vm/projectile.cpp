// projectile motion 
// P. Gorham, updated 3/20/2007 for UH Physics 305 
// March 2013, updated to minimal c++ --PG


using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 

#define Tmax  500                // seconds
#define PI M_PI
#include "3Vector.h" 

// this structure type for 3-vectors 
/*typedef struct {
		double x, y, z;
		} vec3;
*/		
// we use a global time variable so the functions can use time
//   dependent accelerations if necessary
double t,t0, theta0;

extern vec3 vecFRK4xv(int, vec3 (*)(double, vec3, vec3),
			  vec3 (*)(double, vec3, vec3),
			  double ,vec3, vec3,double ), vec3sum(vec3, vec3);


// this function should return the drag coeffcient as a function of altitude H
// accounting for the density of air using an exponential scale height
double dragc(double H)
{
	double Cd, A, Po, ho, r;
	r = 0.0738/2.0;		// radius of ball in m
	A = pow(r,2.0)*PI;		// cross sectional area in m^2
	Po = 1.22;		// sealevel air density in kg/m^3
	Cd = 0.3;		// drag coeff
	ho = 7000.0;		// scale height of atm
	double altitude = 1600.0;	// altitude of city above sea-level, in meters

// for zero drag case
//	double Cdrho = 0.0;

	double Cdrho = (1.0/2.0)*Cd*A*Po*exp(-(H + altitude)/ho);
	return(Cdrho);
}

// this function is complete: gives the formal definition dx/dt=v
vec3 f_x(double t, vec3 x, vec3 v)
{
	return(v);
}


// this function should return the force/mass=acceleration as a 
// function of the position and velocity vectors, based on the force law
vec3 f_v(double t, vec3 x, vec3 v)
{
	double  g=9.8, m=0.145;
    vec3 retval;
    vec3 W;
    vec3 vapp;
    vec3 a;
	
    a.x = 0.0;
    a.y = 0.0;
    a.z = 0.0;
    
// 15mph = 6.7056m/s
	W.x = 6.7056; // same direction is negative
	W.y = 0.0;
	W.z = 0.0;
	
	vapp = vec3diff(v, W);
	double bvmag = dragc(x.z)*vec3mag(vapp);
	a = scalar_vec3mult(bvmag/m, vapp);
        retval.x = 0.0; // x is forward
        retval.y = 0.0; // y is side-to-side
        retval.z = -g;  // z is vertical, gravity only here
retval=vec3diff(retval,a);
        return(retval);

}




main(int argc,char *argv[])
{
  vec3 xt,vt,xtold,vtold;
  double dt;
  double vt0,v0;
   ofstream outfile;  
   
	if(argc<3){
		cerr << "usage: projectile [theta0 (deg)][v0 (m/s)]" << endl;
		exit(0);
		}
 
   
	outfile.open("dragdeg40denverwithw.dat");
	
	theta0 = PI/180.0*atof(argv[1]);   // initial angle, radians
	v0 = atof(argv[2]);                // initial velocity, m/s
	vtold.x = v0*cos(theta0);          // x and z components of velocity
	vtold.z = v0*sin(theta0);
	vtold.y = 0.0;                     //  in plane motion only here
	t0 = 0.0;                          // initial time
	xtold.x = 0.0;                     // initial position at origin
	xtold.y = 0.0;
	xtold.z = 0.0;
	dt = 0.01;                         // time step


	// print out starting values 

	 outfile << t0 << " " << xtold.x << " " << xtold.x << " " 
	 		<< vtold.x << " " << vtold.z << endl;

	for(t=t0; t<Tmax; t+= dt){

		xt = vec3sum( xtold , vecFRK4xv(0,f_x,f_v,t,xtold,vtold,dt) );
		vt = vec3sum( vtold , vecFRK4xv(1,f_x,f_v,t,xtold,vtold,dt) );

		xtold = xt;
		vtold = vt;

		if(xt.z<0.0){
		 	 outfile << t << " " << xtold.x << " " << xtold.z << " " 
	 			<< vtold.x << " " << vtold.z << endl; 
			 break;
			 }
 		outfile << t << " " << xtold.x << " " << xtold.z << " " 
	 			<< vtold.x << " " << vtold.z << endl;
	   }

cout << argv[1] << "\t" << xtold.x << endl;
}