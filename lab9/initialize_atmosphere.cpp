using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib> 


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
    
    for(i=0;i<20;i++){
	  cerr << hkm[i] << " " << rhovh[i] << " " << endl;
	}
/*
    ifstream inFile;
    double nO,nN2,nO2, tmp1,tmp2;
    int i;
   
	inFile.open(fname);
	cerr < inFile;

	if (!inFile) {
	  cerr << "Can't open input file " << fname << endl;
	  exit(1);
	}
	cerr < inFile;
	i=0;
	
	while(!(inFile >> hkm[i] >> nO >> nN2 >> nO2 >> rhovh[i] >> tmp1 >> tmp2)){
	  rhovh[i] = rhovh[i]*1.e3;  // convert to kg/m^3
	  i++;
	}
	inFile.close();
	
	for(i=0;i<20;i++){
	  cerr << hkm[i] << " " << rhovh[i] << " " << endl;
	}
*/
}