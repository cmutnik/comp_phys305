/* earth-moon system equations of motion, and the Apollo 13 spacecraft*/
// Corey Mutnik 4/7/15
/* modified from: P. Gorham, updated 4/10/2013 for UH Physics 305 */
// g++ earth_moon.cpp 3Vector.o vecFRK4xv.o -o ~/bin/earth_moon

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 
#include "3Vector.h"
// note that the 3vector functions are found in 3vector.cpp

#define Tmax  10000            // seconds, not long enough yet to get to moon
#define PI M_PI


double t0, theta0;

/*  global previous positions for the mass bodies--needed for acceleration functions */
vec3 rtEold, rtMold;


#define Re  6.3710e6       /* radius of the earth, m */
#define G   6.6730e-11     /* m^3/kg/s^2,   Gravitational constant */
#define Rm  1.73710e6	   /* mean radius of the Moon */
#define Me  5.9736e24      /* 1 earth mass, kg */
#define Mm  7.3477e22      /* moon mass, kg*/
#define Dem 3.84403e8      /* m, mean distance earth to moon*/

#define Ma (28881.+15188.) /* Apollo 13, Command+Service Module (28881 kg) + Lunar lander (15188 kg) */
#define R0A (Re+175.0e3)    /* 175 km altitude Earth parking orbit */
#define v0A  7820.0	   /* m/s spacecraft velocity in (circular) Earth parking orbit */ 

vec3 f_rEM(double t, vec3 r, vec3 v)  /* for Earth */
{
	return(v);
}



vec3 f_vEM(double t, vec3 r, vec3 v)  /* for Earth, force from Moon */
{

	double REM;
	vec3  dvdt, DrEM, FgEM;

	/* this takes the rE-rM vector difference */
	DrEM = vec3diff( r, rtMold);


	/* here is the magnitude of position vector differences */
	REM = vec3mag(DrEM); // earth to moon
	

	FgEM = scalar_vec3mult((-G*Me*Mm/pow(REM,3)), DrEM);
	
	
	/* here are the forces in each case */
/*	FgEM.x = (-G*Me*Mm/pow(REM,3)), DrEM.x*cos(theta0);
	FgEM.y = (-G*Me*Mm/pow(REM,3)), DrEM.y*sin(theta0);
	FgEM.z = 0.0;
*/


	/* return value: the acceleration */
	dvdt.x = (FgEM.x)/Me;
	dvdt.y = (FgEM.y)/Me;
	dvdt.z = 0.0;

	return(dvdt); // return the acceleration
}

vec3 f_rME(double t, vec3 r, vec3 v)  /* for Moon */
{
	return(v);
}



vec3 f_vME(double t, vec3 r, vec3 v)   /* for Moon, force due to Earth */
{

	double RME;
	vec3  dvdt, DrME, FgME;

	/* this takes the rM-rE vector difference */
	DrME = vec3diff( r, rtEold);

	/* here is the magnitude of position vector differences */
	RME = vec3mag(DrME); // moon to earth

	
	FgME = scalar_vec3mult((-G*Me*Mm/pow(RME,3)), DrME);
	
	
	/* here are the forces in each case */
/*	FgME.x = (-G*Me*Mm/pow(RME,3))*DrME.x*cos(theta0);
	FgME.y = (-G*Me*Mm/pow(RME,3))*DrME.y*sin(theta0);
	FgME.z = 0.0;
*/


	/* return value: the acceleration */
	dvdt.x = (FgME.x)/Mm;
	dvdt.y = (FgME.y)/Mm;
	dvdt.z = 0.0;

	return(dvdt);
}

vec3 f_rA(double t, vec3 r, vec3 v)
{
	return(v);
}



vec3 f_vA(double t, vec3 r, vec3 v) /* for Apollo, forces from Earth and Moon */
{

	double RAM,RAE;
	vec3  dvdt, DrAM,DrAE, FgAM, FgAE;

	/* this takes the rE-rM vector difference */
	DrAM = vec3diff( r, rtMold);
	/* this takes the rE-rA vector difference */
	DrAE = vec3diff( r, rtEold);

	/* here is the magnitude of position vector differences */
	RAM = vec3mag(DrAM); // satellite to moon
	RAE = vec3mag(DrAE); // satellite to earth

	
	FgAM = scalar_vec3mult((-G*Ma*Mm/pow(RAM,3)), DrAM);
	
	FgAE = scalar_vec3mult((-G*Ma*Me/pow(RAE,3)), DrAE);
	
	
	/* here are the forces in each case */
/*	FgAM.x = (-G*Ma*Mm/pow(RAM,3))*DrAM.x;
	FgAM.y = (-G*Ma*Mm/pow(RAM,3))*DrAM.y;
	FgAM.z = 0.0;

	FgAE.x =(-G*Ma*Me/pow(RAE,3))*DrAE.x*cos(theta0);
	FgAE.y = (-G*Ma*Me/pow(RAE,3))*DrAE.y*sin(theta0);
	FgAE.z = 0.0;
*/
	
	/* return value: the acceleration */
	dvdt.x = (FgAM.x + FgAE.x)/Ma;
	dvdt.y = (FgAM.y + FgAE.y)/Ma;
	dvdt.z = 0.0;


	return(dvdt);
}

// This function is found in an external file: vecFRK4xv.cpp
extern vec3 vecFRK4xv(int ytype, vec3 (*f_x)(double, vec3, vec3),
			  vec3 (*f_v)(double, vec3, vec3), 
			double t, vec3 xold,vec3 vold,double dt);

main(int argc,char *argv[])
{

  double t, dt, Ttot, v0E, v0M,R, rE, rM;
  vec3 rtE,rtM,rtA,rtAold,vtE,vtM,vtA,vtEold,vtMold,vtAold;
  ofstream outfile; 


	if(argc<4){
		fprintf(stderr, "usage: earth_moon [total time][outfile][theta0]\n");
		exit(0);
		}

	Ttot = atof(argv[1]);
	outfile.open(argv[2]);
//theta0 = (PI/180.0)*(atof(argv[3]));	
	t0 = 0.0;     			   // initial time

//------------------------------QUESTION-----------------------------------------------------------------------------------------
	dt = 5.0;                         // time step, is this small enough?

	
	rE = (Mm/(Mm+Me))*Dem;   // this is the distance from earth center to Earth-Moon barycenter
	rM = (Me/(Mm+Me))*Dem;   // distance of Moon center to barycenter

	/* calculate velocities based on the known sidereal Earth-Moon orbital period of 27.322 days */
	v0E = (2.0*PI*rE)/(27.322*24.0*3600.0);  // earth initial velocity, m/s
	v0M = (2.0*PI*rM)/(27.322*24.0*3600.0);  // moon initial velocity, m/s;

	/* all orbits here are PROGRADE: counterclockwise looking from above N pole */
	/* earth's initial velocity */
	vtEold.x = v0E;                     // components of velocity
	vtEold.y = 0.0;
	vtEold.z = 0.0;                     //  in plane motion only here

	/* earth's initial position: CHANGE THIS to put the barycenter at origin!! */
	rtEold.x = 0.0;
	rtEold.y = -rE;   // put it at the "bottom" of cartesian plane
	rtEold.z = 0.0;

	/* moon initial position, YOU MUST MODIFY for barycentric origin!!  */
	rtMold.x = 0.0;
	rtMold.y = rM;   // put it at the 'top' in cartesian plane
	rtMold.z = 0.0;

	/* moon's initial velocity */
	vtMold.x = -v0M;                     // components of velocity
	vtMold.y = 0.0;
	vtMold.z = 0.0;                     // in plane motion only here



	for(t=t0; t<Ttot; t+= dt){
theta0 = (PI/180.0)*(atof(argv[3]))+360.0*(PI/180.0)*(t/5270.66287144); // change 3 days to singular orbit time of apollo around moon




	/* initial position of spacecraft, use Earth parking orbit */
//	rtAold.x = R0A*cos(theta0)-mu;
//rtAold.x = 0.0;
//rtAold.y = R0A;   // m, put it "above" the Earth initially in line with Earth-Moon barycenter
rtAold.x = R0A*cos(theta0);
rtAold.y = R0A*sin(theta0);
rtAold.z = 0.0;

	
	/* Apollo 13 initial velocity rel. to Earth, use Earth parking orbit velocity */
//	vtAold.x = -v0A+1600.0;                     // components of velocity
//      vtAold.x = -sqrt(3.986005e14/R0A);		// = ~(-7803.35)
	vtAold.x = -sqrt((G*Me)/R0A);
	vtAold.y = 0.0;
	vtAold.z = 0.0;                     // in plane motion only here
	vtAold = vec3sum(vtEold,vtAold);  // to get spacecraft barycentric velocity, need to add Earth v!

double r1 =	
double r2 = 	
double deltav1 = sqrt((G*Me)/r1)*(sqrt((2.0*r2)/(r1 + r2))-1.0);
if(t>=(20.0*5270.66287144)){
  	vtAold.x = -(sqrt((G*Me)/R0A) + deltav1)*sin(theta0) + rtAold.y;
	vtAold.y = (sqrt((G*Me)/R0A) + deltav1)*cos(theta0) - rtAold.x;
	vtAold.z = 0.0;                     // in plane motion only here
	vtAold = vec3sum(vtEold,vtAold); 
}
/*
//---------------------------------------------------------------------------------------------------------------------
// if time is equal to time it take for apollo to go half way around earth then give it hoff. trans. vel	
	if(t>=2.0*PI*R0A/sqrt(G*Me/R0A)){
// transfer to higher orbit
//	  vtAold.x = sqrt(G*Me/R0A)*(sqrt(2.0*(Dem-RAM))/(R0A+Dem-RAM))-1.0);			  
	  	vtAold.x = -sqrt(G*Me/R0A)*(sqrt(2.0*(Dem-vec3mag(vec3diff( rtEold, rtMold))))/(R0A+Dem-vec3mag(vec3diff( rtEold, rtMold)))- 1.0);
  
//transfer to lower orbit
//	  vtAold.x = sqrt(G*Me/(Dem-vec3mag(vec3diff( rtEold, rtMold))))*(1.0 - sqrt(2.0*R0A/(R0A+Dem-vec3mag(vec3diff( rtEold, rtMold)))));

	vtAold.y = 0.0;
	vtAold.z = 0.0;                     // in plane motion only here
	vtAold = vec3sum(vtEold,vtAold);  // to get spacecraft barycentric velocity, need to add Earth v!
	}
	
      if(t>=(2.0*PI*R0A/sqrt(G*Me/R0A))+PI*sqrt(pow((Dem-vec3mag(vec3diff( rtEold, rtMold))),3.0)/(8.0*G*Me))){
	vtAold.x = sqrt(G*Me/(Dem-vec3mag(vec3diff( rtEold, rtMold))))*(1.0 - sqrt(2.0*R0A/(R0A+Dem-vec3mag(vec3diff( rtEold, rtMold)))));
//	vtAold.x = -sqrt(G*Mm/(Dem-vec3mag(vec3diff( rtEold, rtMold))));
	vtAold.y = 0.0;
	vtAold.z = 0.0;                     // in plane motion only here
	vtAold = vec3sum(vtEold,vtAold); 
      }
//----------------------------------------------------------------------------------------------------------------------------	
*/
/*
// after orbiting the vel changes to head for the moon
    if(t>=179.5*PI*R0A/sqrt(G*Me/R0A)){
	vtAold.x = -vtAold.x;
	vtAold.y = -523.5;
	vtAold.z = 0.0;                     // in plane motion only here
	vtAold = vec3sum(vtEold,vtAold);  // to get spacecraft barycentric velocity, need to add Earth v!
       }
     if(t>=1149350.4){
	vtAold.x = sqrt(G*Mm/(Rm+250000.0));
	vtAold.y = 0.0;
	vtAold.z = 0.0;                     // in plane motion only here
	vtAold = vec3sum(vtMold,vtAold);  // to get spacecraft barycentric velocity, need to add Earth v!
       }
//    if(t>=1149450.4){
//	vtAold.x = 3.0;
//	vtAold.y = 20.0;
//	vtAold.z = 0.0;                     // in plane motion only here
//	vtAold = vec3sum(vtEold,vtAold);  // to get spacecraft barycentric velocity, need to add Earth v!
//    }
*/
	/* These lines update the position and velocity of Earth */
		rtE = vec3sum( rtEold , vecFRK4xv(0,f_rEM,f_vEM,t,rtEold,vtEold,dt) );
		vtE = vec3sum( vtEold , vecFRK4xv(1,f_rEM,f_vEM,t,rtEold,vtEold,dt) );

	/* These lines update the position and velocity of the Moon */
		rtM = vec3sum( rtMold , vecFRK4xv(0,f_rME,f_vME,t,rtMold,vtMold,dt) );
		vtM = vec3sum( vtMold , vecFRK4xv(1,f_rME,f_vME,t,rtMold,vtMold,dt) );

	/* These lines update the position and velocity of the spacecraft */
		rtA = vec3sum (rtAold , vecFRK4xv(0,f_rA,f_vA,t,rtAold,vtAold,dt) );
		vtA = vec3sum (vtAold , vecFRK4xv(1,f_rA,f_vA,t,rtAold,vtAold,dt) );

	/* set the old values to the new updated values for next iteration */
		rtEold = rtE;
		vtEold = vtE;

		rtMold = rtM;
		vtMold = vtM;

		rtAold = rtA;
		vtAold = vtA;

/*		double TM = -G*Mm*Me/vec3mag(rtMold);
		double KM = (1.0/2.0)*Mm*pow(vec3mag(vtMold),2.0);
		double TE = -G*Mm*Me/vec3mag(rtEold);
		double KE = (1.0/2.0)*Me*pow(vec3mag(vtEold),2.0);
		double Etot = TM + KM + TE + KE;
*/




	/* we only print values every 100 seconds, but calculate them on a finer scale */
	if(((int)t)%100 == 0.0){
	
	outfile << " " << rtE.x <<  " " << rtE.y <<  " " << vtE.x << " " <<  vtE.y 
			<< " " << rtM.x << " "  << rtM.y << " "  << vtM.x << " " <<  vtM.y 
			<< " " << rtA.x <<  " " << rtA.y <<  " " << vtA.x << " " << vtA.y << endl;

	   }  /* end of update loop */


}  /* end of main */
}







