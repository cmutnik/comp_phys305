/* Isotope1.cpp: program to simulate radioactive decay
 * -- P. Gorham for UH Physics 305 2/24/14 
 * g++ Isotope1.cpp -o Isotope1
 */

using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions
#include <iomanip>   // this is required to use "setprecision" 
#include <fstream>
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cmath>
#include <cstdio>     // for the  useful old C-standard stuff 
#include <cstdlib>    

#define LONGENOUGH  18000 // fill this in with an integer time in secs that is long enough
    
main(int argc, char *argv[])
{
 
	if(argc<6){
		cerr<< "usage: Isotope2 [Natoms-C10][Natoms-C11][Natoms-C12][Half-life-C10][Half-life-C11]"<<endl;
		exit(0);
		}
		
	int Natoms1[3];
	for(int i=0; i<=2; i++){ // check i<+ ----should it be i<3 ??-------------------------------------------------------------------------
	    Natoms1[i] = atoi(argv[i+1]);
	}
	
	double Lifetime1[2];
	for(int i=0; i<2; i++){
	   Lifetime1[i] = atof(argv[i+4])/log(2);
	}
	 
 /* do loop instead ^
    int Natoms1 = atoi(argv[1]); // number of inital C12 atoms
    int Natoms11 = atoi(argv[2]); // number of inital C11 atoms
    int Natoms10 = atoi(argv[4]); // number of inital C10 atoms
    double Lifetime11 = atof(argv[3])/log(2); // defined halflife of C11
    double Lifetime10 = atof(argv[5])/log(2); // defined halflife of C10
*/
 
    double *DecayArr[2], *RemainArr[2], *decaytot, *remaintot;   
    double dt = 0.1;  // the time resolution of our clock, seconds
    double bindt = 10.0; //size of each larger count bin in seconds
    
    
    // differential decay probability per atom per dt
    double dt_DecayProb[2];
    for(int i=0; i<2; i++){
      dt_DecayProb[i]= dt/Lifetime1[i];  
    }
    
    int Ndecay[2], Nt[2];
    int TotalTime = LONGENOUGH; // TotalTime is a parameter we need to set long enough     
    srand48(1299811); // a large prime  
    double tt = 0.0;   // our overall clock time
  
  for(int i=0; i<2; i++){
    Nt[i] = Natoms1[i];  // starting number of atoms for a given isotope
  }
  
  int Ndeltat = LONGENOUGH/bindt;   
  
  for(int i=0; i<2; i++){
    DecayArr[i] = new double [Ndeltat]();  // initialize our decay counter array
    RemainArr[i] = new double [Ndeltat](); // this will keep track of remaining atoms
  }
  
  decaytot = new double [Ndeltat]();
  remaintot = new double [Ndeltat]();
  
    while(tt < TotalTime) {          
        Ndecay[0] = 0;  // reset the atom decay counter for each dt time interval
	Ndecay [1] = 0;
	
       // now loop over all of our atoms, check if any decay in this dt interval
      for(int i=0;i<2;i++){ 
	for(int j=0; j<Nt[i]; j++){
	  int idecay = drand48() <= dt_DecayProb[i] ? 1 : 0 ;  // conditional statement
           if(idecay){
	     DecayArr[i][(int)(tt/bindt)] += 1.0; // here the index is modulo bindt=10sec
              Ndecay[i] += 1;
            }   
          }      // end of our atom-decay check loop
        Nt[i] -= Ndecay[i];  // remove the incremental number of decayed atoms from the total number
        RemainArr[i][(int)(tt/bindt)] = Nt[i];
      }
      
        tt += dt;      
    }  // end of our outer time loop
   
    for(int i=0;i<Ndeltat;i++){
      decaytot[i] += DecayArr[0][i]+DecayArr[1][i];
      remaintot[i] += RemainArr[0][i]+RemainArr[1][i]+Natoms1[2];
     
        cout << (i+0.5)*bindt << "\t" << DecayArr[0][i] << "\t"<< RemainArr[0][i] << "\t" << DecayArr[1][i] << "\t" << RemainArr[1][i]
        << "\t" << decaytot[i] << "\t" << remaintot[i] << endl;
        }

}	