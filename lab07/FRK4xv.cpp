/* FRK4xv: a function to calculate second-order Runge-Kutta
   for 1-dimensional F = dp/dt = f(x(t),v(t)) (Newton force law) 
   the user must supply the functions f_x, f_v which determine
   the return value.
   Both x and v increments must be calculated at each step in 
   the integration of the equation, and xold and vold must be
   reset after each step 

--P. Gorham: updated 3/9/2010 for Physics 305, add explicit time dependence,
correct error in previous version

  March 2013, convert for use with c++*/

double FRK4xv(int ytype, double (*f_x)(double, double, double), 
			 double (*f_v)(double, double, double),
               		 double t,double xold,double vold,double dt)

/* ytype = 0 for x(t) increment, 1 for v(t) increment,
xold, vold, previous position and velocity
   t=time variable, dt = step size

   double (*f_x)(double, double ,double) ==> pointer to a function of
   three doubles that returns a double. Note the order: the f_x function
   comes first in the argument list.
  see Landau & Paez equations 9.44 and 9.45
*/

{
	double k1x, k1v, k2x, k2v, k3x, k3v, k4x, k4v, ktot;

		k1x = dt*(*f_x)(t, xold, vold);
		k1v = dt*(*f_v)(t, xold, vold);
		k2x = dt*(*f_x)(t+dt/2.0, xold+k1x/2.0, vold+k1v/2.0);
		k2v = dt*(*f_v)(t+dt/2.0, xold+k1x/2.0, vold+k1v/2.0);
		k3x = dt*(*f_x)(t+dt/2.0, xold+k2x/2.0, vold+k2v/2.0);
		k3v = dt*(*f_v)(t+dt/2.0, xold+k2x/2.0, vold+k2v/2.0);
		k4x = dt*(*f_x)(t+dt, xold+k3x, vold+k3v);
		k4v = dt*(*f_v)(t+dt, xold+k3x, vold+k3v);

	if(ytype==0){   /* ytype = 0 is for x(t) */

		ktot = (1.0/6.0)*(k1x + 2.0*k2x + 2.0*k3x + k4x);

	    }else{  /* ytype = 1 is for v(t)*/

		ktot = (1.0/6.0)*(k1v + 2.0*k2v + 2.0*k3v + k4v);
	}
	
	return(ktot);  // add this value to the previous v or x
}


/* the following are examples of the form of the functions needed.
  In practice you should put the relevant functions in the source
  code that contains the loop for integration of the position
  and velocity */

/*the dx/dt function only requires returning the velocity--no action */
double f_x (double x, double v)
{
	return (v);
}
// Here is the actual force law...with f_dvdt replaced by f_v
double f_v(double x, double v)
{

// F = dp/dt m dv/dt = m(-kx/m) = -kx | k=1
	double retval = -x;
	return( retval );
}



