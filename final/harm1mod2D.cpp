// Corey Mutnik 4/14/15 modified from:
/*
      harmonic1.c
  
        Solution of the quantum harmonic oscillator
        Eigenvalue search using shooting method.
        Forward and backward integration with Numerov method.
        Solution matching at a classical turning point.
        Adimensional units: x = (mK/hbar^2)^(1/4) X
                            e = E/(hbar omega)
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#define pi M_PI
//-----------------------------fix
#define me 1.0
#define omegax1 1.0
#define omegax2 1.0
#define me 1.0
#define hbar 1.0

//static double pi = 3.14159265358979323846;

main()
{

//    double sqrt();

//    vec3 potential;
//    vec3 psi;
    int mesh, i, icl;
    int nodes, hnodes, ncross, parity, kkk, iterate;
    double xmax, dx, ddx12, xmcl, norm, arg, yicl, djump, dy, ymax, psiicl, normpsi;
    double elw, eup, e;
    double *x, *y, *p, *vpot, *f, *x1, *x2, *F, *potential, *psi;
    char fileout[80];
    FILE *out, *potentials, *debug, *twoD;

/*  Read input data */

    fprintf(stderr, "Max value of x (typical value: 10) ? ");
    scanf("%lf",&xmax);
//    fprintf(stderr, "Max value of y (typical value: 10) ? ");
//    scanf("%lf",&ymax);
    fprintf(stderr, "Number of grid points (typically a few hundreds) ? " );
    scanf("%d",&mesh);

/*  Allocate arrays (from 0 to mesh), Initialize grid */

    x = (double *) malloc( (mesh+1) * sizeof (double));
    x1 = (double *) malloc( (mesh+1) * sizeof (double));
    x2 = (double *) malloc( (mesh+1) * sizeof (double));
//    potential.x = (double *) malloc( (mesh+1) * sizeof (double));
//    potential.y = (double *) malloc( (mesh+1) * sizeof (double));
//    potential.z = (double *) malloc( (mesh+1) * sizeof (double));
    y = (double *) malloc( (mesh+1) * sizeof (double));
    p = (double *) malloc( (mesh+1) * sizeof (double));
    f = (double *) malloc( (mesh+1) * sizeof (double));
    vpot = (double *) malloc( (mesh+1) * sizeof (double));
    potential = (double *) malloc( (mesh+1) * sizeof (double));
    F = (double *) malloc( (mesh+1) * sizeof (double));
    psi = (double *) malloc( (mesh+1) * sizeof (double));
//    potentialy = (double *) malloc( (mesh+1) * sizeof (double));
    dx = xmax / mesh;
 //   dy = ymax/mesh;
    ddx12 = dx * dx / 12.;

/*  set up the potential (must be even w.r.t. x=0) */
// -------------------------------------------------------------------------vpot=1/2*x*X....so w=1???????????????-----------------------------
    fprintf(stderr, "Output file name (1D) = ");
    scanf("%80s", fileout);
    out = fopen(fileout, "w");
    potentials = fopen("potentials.dat", "w");
    debug = fopen("debug.dat", "w");
    twoD = fopen("twoD.dat","w");

    for (i = 0; i <= mesh; ++i) {
	x[i] = (double) i * dx;
	x1[i] = (double) i * dx;
	x2[i] = (double) i*dx;
  //	x2[i] = (double) i * dy;
	vpot[i] = 0.5 * x[i] * x[i];
/*	potential.x=(1.0/2.0)*me*((omegax1*omegax1*x1[i]*x1[i])+(omegax2*omegax2*x2[i]*x2[i]));
	potential.y=(1.0/2.0)*me*((omegax1*omegax1*x1[i]*x1[i])+(omegax2*omegax2*x2[i]*x2[i]));
	potential.z=0.0;
*/
	potential[i] = (1.0/2.0)*me*((omegax1*omegax1*x1[i]*x1[i])+(omegax2*omegax2*x2[i]*x2[i]));
	
	fprintf(potentials,"%7.3f%12.5e%12.5e\n",x1[i],x2[i],potential[i]);
//	fprintf(potentials,"%7.3f%12.5e%12.5e\n",x[i],potential.x,potential.y);
	      
	      
//debug statement
//fprintf(twoD,"%7.3f%12.5e%12.5e\n",x[i],potential.x,potential.y);
	      
	      
//-------------------------------------------------------------create matrix lattice using this mesh
    }

L999:	/* this is the entry point for a new eigenvalue search */

/*  Read number of nodes (stop if < 0) */

    fprintf(stderr, "Number of nodes (-1=exit) ? ");
    scanf("%d",&nodes);
    if (nodes < 0) {
        free(vpot); free(f); free(p); free(y); free(x), free(x1), free(x2), free(F);
        free(potential), free(psi);
        fclose(out);
        exit(0);
    }

/*  set initial lower and upper bounds to the eigenvalue */

    eup = vpot[mesh];
    elw = eup;
    for (i = 0; i <= mesh; ++i) {
        if ( vpot[i] < elw )
            elw = vpot[i];
        if ( vpot[i] > eup )
            eup = vpot[i];
    }

/*  set trial energy */

    fprintf(stderr, "Trial energy (0=search with bisection) ? ");
    scanf("%lf", &e);
    if (e == 0.) { /* search eigenvalues with bisection (max 1000 iterations) */
	e = 0.5 * (elw + eup);
	iterate = 1000;
    } else {	   /*  test a single energy value */
	iterate = 1;
    }

    for (kkk = 0; kkk <= iterate && eup-elw > 1.e-10; ++kkk) {

/*---------------------------------------------------------------------------------------------mod this
     set up the f-function used by the Numerov algorithm
     and determine the position of its last crossing, i.e. change of sign
     f < 0 means classically allowed   region
     f > 0 means classically forbidden region
*/
       f[0] = ddx12 * (2.*(vpot[0] - e));
       F[0] = ddx12 * (2.*(potential[0] - e));
       icl = -1;
       
       
       
       
       for (i = 1; i <= mesh; ++i) {
          f[i] = ddx12 * 2. * (vpot[i] - e);
/*
     beware: if f(i) is exactly zero the change of sign is not observed
     the following line is a trick to prevent missing a change of sign 
     in this unlikely but not impossible case:
*/
	  if (f[i] == 0.) {
	     f[i] = 1e-20;
	  }
/*   store the index 'icl' where the last change of sign has been found */
	  if (f[i] != copysign(f[i],f[i-1])) {
	     icl = i;
	  }
       }

              for (i = 1; i <= mesh; ++i) {
	  F[i] = ddx12 * 2. * (potential[i] - e);
	  if (F[i] == 0.) {
	     F[i] = 1e-20;
	  }
	}

       
       
       
       

       if (icl >= mesh - 2) {
          fprintf(stderr, "last change of sign too far.");
          exit(1);
       }
       if (icl < 1) {
          fprintf(stderr, "no classical turning point?");
          exit(1);
       }

/*   f(x) as required by the Numerov algorithm  */

       for (i = 0; i <= mesh; ++i) {
          f[i] = 1. - f[i];
	  F[i] = 1. - F[i];
       }

       for (i = 0; i <= mesh; ++i) {
          y[i] = 0.;
	  psi[i] = 0.;
       }

/*  Determination of the wave-function in the first two points  */

       hnodes = nodes / 2;

/*  beware the integer division: 1/2 = 0 !
    if nodes is even, there are 2*hnodes nodes
    if nodes is odd,  there are 2*hnodes+1 nodes (one is in x=0)
    hnodes is thus the number of nodes in the x>0 semi-axis (x=0 excepted) */
  
       if (2*hnodes == nodes) {
          /*  even number of nodes: wavefunction is even  */
	  y[0] = 1.;
	  psi[0] = 1.;
          /*  assume f(-1) = f(1)  */
	  y[1] = 0.5 * (12. - f[0] * 10.) * y[0] / f[1];
	  psi[1] = 0.5*(12. - F[0] * 10.) * y[0] / F[1];
       } else {
          /*  odd  number of nodes: wavefunction is odd   */
	  y[0] = 0.;
	  y[1] = dx;
	  psi[0] =0.;
	  psi[1] = dx;
       }

/*   Outward integration and count number of crossings  */

       ncross = 0;
       for (i = 1; i <= icl-1; ++i) {
          y[i + 1] = ((12. - f[i] * 10.) * y[i] - f[i - 1] * y[i - 1]) / f[i + 1];
	  psi[i+1] = ((12. - F[i] * 10.) * psi[i] - F[i - 1] * psi[i - 1]) / F[i + 1];
          if (y[i] != copysign(y[i],y[i+1]))
	      ++ncross;
       }
       yicl = y[icl];
       psiicl = psi[icl];

       if (2*hnodes == nodes) {
          /* even number of nodes: no node in x=a 0*/
          ncross = 2*ncross;
       } else {
          /*  odd number of nodes:    node in x=0 */
          ncross = 2*ncross+1;
       }

       /*  Check number of crossings  */

       if (iterate > 1) {
          if (ncross != nodes) {
             /* Incorrect number of crossings: adjust energy  */
             if ( kkk == 1) {
                fprintf(stdout, "Bisection         Energy       Nodes  Discontinuity\n");
             }
             fprintf(stdout, "%5d%25.15e%5d\n", kkk, e, ncross);

             if (ncross > nodes) {
             /* Too many crossings: current energy is too high
                lower the upper bound */
	         eup = e;
	     } else {
             /* Too few or correct number of crossings: current energy is too low 
                raise the lower bound */
	         elw = e;
	     }
             /* New trial value: */
	     e = 0.5 * (eup + elw);
          }
       } else {
          fprintf(stdout, "%25.15e%5d%5d\n", e, ncross,nodes);
       }

    if ( iterate == 1 ||  ncross == nodes ) {
/*
     Number of crossings is correct, or energy is fixed:
      proceed to inward integration 

     Determination of the wave-function in the last two points 
     assuming y(mesh+1) = 0
*/
       y[mesh] = dx;
       psi[mesh] = dx;
       
       y[mesh - 1] = (12. - 10.*f[mesh]) * y[mesh] / f[mesh-1];
       psi[mesh-1] = (12. - 10.*F[mesh]) * psi[mesh]/F[mesh-1];

       

/*	Inward integration */
       for (i = mesh - 1; i >= icl+1; --i) {
          y[i-1] = ((12. - 10.*f[i]) * y[i] - f[i+1] * y[i+1]) / f[i-1];
	  psi[i-1]=((12. - 10.*F[i])*psi[i] - F[i+1]*psi[i+1]) / F[i-1];
       }

/*	Rescale function to match at the classical turning point (icl) */

       yicl /= y[icl];
       psiicl /= psi[icl];
       for (i = icl; i <= mesh; ++i) {
           y[i] *= yicl;
//	   psi[i] *= yicl;
	   psi[i] *=psiicl;
       }

/*      normalize on the [-xmax,xmax] segment  */

       norm = 0.;
       normpsi = 0.;
       for (i = 1; i <= mesh; ++i) {
           norm += y[i]*y[i];
	   normpsi += psi[i]*psi[i];
       }
       norm = dx * (2.* norm + y[0]*y[0]);
       normpsi =dx*(2.* normpsi+psi[0]*psi[0]);
       norm = sqrt(norm);
       normpsi = sqrt(normpsi);
       for (i = 0; i <= mesh; ++i) {
           y[i] /= norm;
	   psi[i] /= normpsi;
       }

       
       
       
       
       
       //====================================================================need psi below this=======
/* 	calculate the discontinuity in the first derivative 
              y'(i;RIGHT) - y'(i;LEFT)         */

       if (iterate > 1) {
          i = icl;
          djump = (y[i+1] + y[i-1] - (14. - 12.*f[i]) * y[i]) / dx;
          fprintf(stdout, "%5d%25.15e%5d%14.8f\n", kkk, e, nodes, djump);
	  if (djump*y[i] > 0.) {
//               Energy is too high --> choose lower energy range 
	     eup = e;
	  } else {
//               Energy is too low --> choose upper energy range 
	     elw = e;
	  }
	  e = 0.5 * (eup + elw);
       }
    } // end if (ncross==nodes)
    } // end do /*
//============================================================================need psi above this==============








/* ---- convergence has been achieved (or it wasn't required) ---- */
L2:
/*
   Calculation of the classical probability density for energy e:
*/
    xmcl = sqrt(2. * e);
    norm = 0.;
    normpsi = 0.;
    for (i = icl; i <= mesh; ++i) {
	p[i] = 0.;
    }
    for (i = 0; i <= icl - 1; ++i) {
	arg = xmcl*xmcl - x[i]*x[i];
        if ( arg > 0.) 
           p[i] = 1. / sqrt(arg) / pi;
        else
           p[i] = 0.;
	norm += dx * 2. * p[i];
	normpsi +=dx*2. * p[i];
    }
/* The point at x=0 must be counted once: */
    norm -= dx * p[0];
    normpsi -=dx*p[0];
/* Normalize p(x) so that  Int p(x)dx = 1: */
    for (i = 0; i <= icl - 1; ++i) {
//	p[i] /= norm;
	p[i] /=normpsi;
    }
    

/* x<0 region: */
    if (hnodes << 1 == nodes)
        parity = +1;
    else
        parity = -1;
    for (i = mesh; i >= 1; --i) {
        fprintf(out, "%7.3f%16.8e%16.8e%16.8e%12.6f\n",-x[i], parity*y[i], y[i]*y[i], p[i], vpot[i]);
	fprintf(twoD, "%7.3f%7.3f%16.8e%16.8e%16.8e%12.6f\n",-x1[i],-x2[i], parity*psi[i], psi[i]*psi[i], p[i], potential[i]);
    }
        for (i = mesh; i >= 1; --i) {
	fprintf(twoD, "%7.3f%7.3f%16.8e%16.8e%16.8e%12.6f\n",x1[i],-x2[i], parity*psi[i], psi[i]*psi[i], p[i], potential[i]);
    }

/* x>0 region: */
    for (i = 0; i <= mesh; ++i) {
        fprintf(out, "%7.3f%16.8e%16.8e%16.8e%12.6f\n",
		x[i], y[i], y[i]*y[i], p[i], vpot[i]);
	fprintf(twoD, "%7.3f%7.3f%16.8e%16.8e%16.8e%12.6f\n",-x1[i],x2[i], psi[i], psi[i]*psi[i], p[i], potential[i]);
    }
   for (i = 0; i <= mesh; ++i) {
	  fprintf(twoD, "%7.3f%7.3f%16.8e%16.8e%16.8e%12.6f\n",x1[i],x2[i], parity*psi[i], psi[i]*psi[i], p[i], potential[i]);
      
    } 
    
    goto L999;
}

    
    
    
    
    
    


  
  
  
  
    
    
    
    //===========================================WORKS===================================
    
    
    
/* x<0 region: */
/*    if (hnodes << 1 == nodes)
        parity = +1;
    else
        parity = -1;
    for (i = mesh; i >= 1; --i) {
        fprintf(out, "%7.3f%16.8e%16.8e%16.8e%12.6f\n",
		-x[i], parity*y[i], y[i]*y[i], p[i], vpot[i]);
    }
// x>0 region: 
    for (i = 0; i <= mesh; ++i) {
        fprintf(out, "%7.3f%16.8e%16.8e%16.8e%12.6f\n",
		x[i], y[i], y[i]*y[i], p[i], vpot[i]);
	fprintf(twoD, "%7.3f%7.3f%16.8e%16.8e%16.8e%12.6f\n",x1[i],x2[i], psi[i], psi[i]*psi[i], p[i], potential[i]);
	fprintf(twoD, "%7.3f%7.3f%16.8e%16.8e%16.8e%12.6f\n",-x1[i],x2[i], psi[i], psi[i]*psi[i], p[i], potential[i]); 
	
      
    }
    goto L999;
}
*/
