#include"MainLibrary.h"
using namespace std;

double dt = 0.025;		// time step
bool DoWrite=true;		// Whether to write the data to a text file
bool DEBUG = false;		// For debugging

/*
 * @brief Function to look at the motion of 2 coupled oscillators
 * @par X vector storing initial positions.
 * @par V vector storing initial velocities
 * @par t_end specify how long to simulate
 * @par k_m The ratio k/m , or omega^2
 * @par fname name of the text file to store the data
 */
void Question1(vector<double>X,vector<double>V,double t_end,double k_m, string fname);

int main()
{
  Question1({.5,.5},{0.,0.},20.,1.,"TXT_OUT/A8Q1_1.txt");
  Question1({.5,-.5},{0.,0.},20.,1.,"TXT_OUT/A8Q1_2.txt");
  Question1({.1,-.3},{0.,0.},20.,1.,"TXT_OUT/A8Q1_rand.txt");
  return 0;
}

void Question1(vector<double>X,vector<double>V,double t_end,double k_m, string fname)
{
  FILE* outfile;
  outfile = fopen(fname.c_str(),"w");
  if(DoWrite) printf("Output written to the file: %s\n",fname.data());
  
  int nparticles = X.size();		 // No. of particles
  double* xmid = new double[nparticles]; // Intermediate position
  double* vmid = new double[nparticles]; // Intermediate velocity
  double* amid = new double[nparticles]; // Intermediate acceleration

  X.insert(X.begin(),0.); X.push_back(0.);
  V.insert(V.begin(),0.); V.push_back(0.);
  if(DEBUG) for(int i=0;i<(int)X.size();i++) cout<<X[i]<<"\t"<<V[i]<<endl;
  
  for(double tt=0.; tt<=t_end; tt+= dt){
    if(DoWrite) fprintf(outfile,"%.3f\t",tt+dt);
    
    for(int i=1;i<=(int)nparticles;i++){
      double acc = k_m*(X[i-1]-2.*X[i]+X[i+1]);
      xmid[i] = X[i]+.5*V[i]*dt;
      vmid[i] = V[i]+.5*acc*dt;
    }
    
    for(int i=1;i<=(int)nparticles;i++){
      amid[i] = k_m*(xmid[i-1]-2.*xmid[i]+xmid[i+1]);
      X[i] += vmid[i]*dt;
      V[i] += amid[i]*dt;
      if(DoWrite) fprintf(outfile,"%.4f\t%.4f\t",X[i],V[i]);
    }

    if(DoWrite) fprintf(outfile,"\n");    
  }
}

void Question2()
{
}
