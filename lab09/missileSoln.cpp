// ballistic missile 
// P. Gorham, 
// April 2014 Physics 305
// To compile:
//  g++ missile.cpp vecFRK4xv.cpp 3Vector.cpp initialize_atmosphere.cpp -o ~/bin/missile

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 
#include "3Vector.h"
// note that the 3vector functions are found in 3vector.cpp

#define Tmax  1000.0                // seconds
#define PI M_PI
#define Diam 1.320  // meters for the rocket
#define Am  (PI*Diam*Diam/4.)
#define Cd  0.25	// coeff of drag
#define tb   110.0     // seconds
#define m0   16000.0    // kg
#define mf   12912.0  // kg initial fuel
#define G    6.67e-11  // gravity
#define Re   6335437.0  // meters
#define Me   5.972e24  // kg
#define Thrust (9.8066*26050.0) // in Newtons


// global variable for wind velocity
vec3 W0;		
// we use a global direction for the initial thrust
vec3 InitialThrustDir;
double hkm[1500],rhovh[1500];  // atmosphere table parameters

// mass function vs. time ----------------------------------

double m_t(double t)
{
	double m;
	if(t<tb){
		m = m0 - mf*(t/tb);
	   }else{
		m = m0 - mf;
		}
	return(m);
}

double rho(double h) // h in meters, returns density ----------------------------------
{
	int ih;
	double density,x1,x2,y1,y2,slope;
	
	if(h>298e3) return(density=0);
	// the following does a linear interpolation
	ih = ((int)(h/2000.));	// density file in 2km steps
	y2 = rhovh[ih+1];
	y1 = rhovh[ih];
	x2 = hkm[ih+1]*1000;
	x1 = hkm[ih]*1000;
	slope = (y2-y1)/(x2-x1); // kg/m^3 per meter
	
	density = y1 + slope*(h-x1);
	return(density);
}

// gravitational + normal force at start ----------------------------------
vec3 Fgn(vec3 r, double t)  // r is the vector location of rocket
{
	vec3 fg;
	double R = vec3mag(r);
	double Fmag = -G*Me*m_t(t)/(R*R);
	vec3 Fdir = vec3norm(r);  // lies along radial direction
	fg = scalar_vec3mult(Fmag,Fdir);
	vec3 fn = scalar_vec3mult(-1.,fg);  // normal force cancels gravity at start
	if(t==0.0) {
	  return(vec3sum(fg,fn));
	  //return 0.0;
	}else{ 
	  return(fg);
	}
}

// drag force ----------------------------------
vec3 Fb(vec3 v, vec3 r, double t)
{
	double _h = vec3mag(r)-Re;
	vec3 vapp = vec3diff(v,W0); 
	double vmag = vec3mag(vapp);
	double bmag = -0.5*rho(_h)*Cd*Am;
	vec3 fdrag = scalar_vec3mult(-bmag*vmag, vapp);	
	return(fdrag);
}

//  thrust force ----------------------------------
vec3 Fp(double m, vec3 v, double t)
{
	vec3 thrust,thrdir;
	double thrmag;
	
	if(t<=tb){
		thrmag = Thrust;
	}else{
	  	thrmag = 0.0;
	}
	thrdir = vec3norm(InitialThrustDir);
	thrust = scalar_vec3mult(thrmag,thrdir);
	return(thrust);

}

// this function is complete: gives the formal definition dx/dt=v
vec3 f_x(double t, vec3 x, vec3 v)
{
	return(v);
}


// this function should return the force/mass=acceleration as a 
// function of the position and velocity vectors, based on the force law
vec3 f_v(double t, vec3 r, vec3 v)
{
	
    vec3 dvdt;

//	acceleration law: dvdt = 1./m_t(t) * ( (Fg(r)+Fn(t)) + Fb(v,r) + Fp(m_t(t),v,t)  );
	dvdt = scalar_vec3mult(1./m_t(t), vec3sum3(Fgn(r,t),Fb(v,r,t),Fp(m_t(t),v,t)));		
        return(dvdt);

}


// This function is found in an external file: vecFRK4xv.cpp
extern vec3 vecFRK4xv(int ytype, vec3 (*f_x)(double, vec3, vec3),
			  vec3 (*f_v)(double, vec3, vec3), 
			double t, vec3 xold,vec3 vold,double dt);

//extern void initialize_atmosphere(double*, double*);

void initialize_atmosphere(double hkm[], double rhovh[])
{
    ifstream ifile;
    ifile.open("AtmosphereModel.dat");
    string header;
    double unused;
    
    getline(ifile,header);
    getline(ifile,header);
    
    int i = 0;
    while(!ifile.eof()){
      ifile >> hkm[i] >> unused >> unused >> unused >> rhovh[i] >> unused >> unused;
      i++;
    }
    ifile.close();
    
//  for(i=0;i<20;i++){
//	cerr << hkm[i] << " " << rhovh[i] << " " << endl;
//	}
}

main(int argc,char *argv[])
{
  vec3 xt,vt,at,xtold,vtold,atold,Fg1,Fp1,Fb1;
  double t, dt, nO, nN2, nO2;
  double vt0,v0,theta0,t0;
  int i;
   ofstream outfile; 
   ifstream inFile;
   
	if(argc<3){
		cerr << "usage: missile [theta0 from vertical (deg)][outfile]" << endl;
		exit(0);
		}
 
	outfile.open(argv[2]);

	initialize_atmosphere(hkm,rhovh);
	
	
	W0.x=W0.y=W0.z=0.0;
	theta0 = PI/180.0*(atof(argv[1]));   // initial angle, converted to radians from horizontal
	InitialThrustDir.x = cos(theta0);  
	InitialThrustDir.y = 0.0;
	InitialThrustDir.z = sin(theta0);	
	v0 = 0.0;                // initial velocity, m/s
	t0 = 0.0;
	vtold.x = v0*cos(theta0);          // x and z components of velocity
	vtold.y = 0.0;                     //  start in x-z plane here
	vtold.z = v0*sin(theta0);	
	xtold.x = 0.0;                     // initial position at origin
	xtold.y = 0.0;
	xtold.z = Re+4.0;                  // center of mass is above surface
	atold.x = 0.0;                     // initial position at origin
	atold.y = 0.0;
	atold.z = 0.0;
	
	dt = 0.01;                         // time step


	// print out starting values 

	 outfile << t0 << " " << xtold.x << " " << setprecision(9) << xtold.z-Re << " " 
	 		<< vtold.x << " " << vtold.z << " " << atold.x << " " << atold.z << " " << vec3mag(xtold) << " " << vec3mag(vtold) << endl; 

	for(t=0.0; t<Tmax; t+= dt){

		xt = vec3sum( xtold , vecFRK4xv(0,f_x,f_v,t,xtold,vtold,dt) );
		vt = vec3sum( vtold , vecFRK4xv(1,f_x,f_v,t,xtold,vtold,dt) );	
		
		at = f_v(t,xtold,vtold);  // for reference
		
		//Fg1 = Fg(xtold,t); Fb1 = Fb(vtold,xtold,t); Fp1 = Fp(m_t(t),vtold,t);
		//fprintf(stderr,"%e  %e  %e\n", Fb1.x,Fb1.y,Fb1.z);
		
		xtold = xt;
		vtold = vt;
		atold = at;
	
		if(vec3mag(xt)<=Re){
		 	 outfile << t << " " << xtold.x << " " << setprecision(9) << xtold.z-Re << " " 
	 			<< vtold.x << " " << vtold.z << " " << atold.x << " " << atold.z << " " << vec3mag(xtold)-Re << " " << vec3mag(vtold) << endl; 
			 break;  // this means we hit the earth
			 }
		if(fmod(t,1.0) < dt){	 
 		outfile << t+dt << " " << xtold.x << " " << setprecision(9) << xtold.z-Re << " " 
	 			<< vtold.x << " " << vtold.z << " " << atold.x << " " << atold.z << " " << vec3mag(xtold)-Re << " " << vec3mag(vtold) << endl; 
//		outfile << t+dt << " " << Fg1.x/m_t(t) << " " << setprecision(9) << Fg1.z/m_t(t) << " " 
//	 			<< Fb1.x/m_t(t) << " " << Fb1.z/m_t(t) << " " << Fp1.x/m_t(t) << " " << Fp1.z/m_t(t)<< endl;				
		}
	}  // end of main loop over time

	  outfile.close();

}


