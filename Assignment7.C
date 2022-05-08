#include"MainLibrary.h"
using namespace std;

double Question1(int npts);
double Question2(int npts, bool plot=false);
double Question3(int npts);
void Question4(int nparticles,string fname,double tol=2.);

double f1(double x, double y);
bool DoPrint = false;		// Flag to control whether to write to a text file

int main()
{
  if(DoPrint) cout<<"Outputs will be written to files\n";
  else cout<<"Not writing to files\n";
  
  // Question 1
  FILE* outfile_1;
  outfile_1 = fopen("TXT_OUT/A7Q1.txt","w");
  for(int i=10;i<1000;i+=10) if(DoPrint) fprintf(outfile_1,"%i\t%.4f\n",i,Question1(i));

  // // Question 2
  FILE* outfile_2;
  outfile_2 = fopen("TXT_OUT/A7Q2.txt","w");
  for(int i=100;i<=5000;i+=100) if(DoPrint) fprintf(outfile_2,"%i\t%.4f\n",i,Question2(i));
  double temp = Question2(1000,true); // For plotting the points

  // Question 3
  printf("\nQuestion3\nTotal number of neutrons = %i\nFraction passed = %.4f\n",1000,Question3(1000));

  // Question 4
  printf("\nQuestion4\nN\tEq. time\tVar\tFluctuations\n");
  Question4(8,"TXT_OUT/A7Q4N8.txt");
  Question4(16,"TXT_OUT/A7Q4N16.txt");
  Question4(64,"TXT_OUT/A7Q4N64.txt");
  Question4(400,"TXT_OUT/A7Q4N400.txt");
  Question4(800,"TXT_OUT/A7Q4N800.txt");
  Question4(3600,"TXT_OUT/A7Q4N3600.txt");
}

double Question1(int npts)
{
  vector<double> X,Y,Z;
  for(int i=0;i<npts;i++){
    double r = rand() /(2.0* RAND_MAX); // r in (0,0.5)
    double theta = 2.0*M_PI*rand()/RAND_MAX; // theta in (0,2*pi)
    X.push_back(0.5+r*cos(theta));
    Y.push_back(0.5+r*sin(theta));
    Z.push_back(1.*rand()/RAND_MAX); // z in (0,1)
  }
  return MonteCarlo3D(X,Y,Z,1.*M_PI/4.0,&f1);
}

double f1(double x, double y)
{
  return sin(pow(log(x+y+1.0),0.5));
}

double Question2(int npts, bool plot)
{
  double ntotal = npts;
  double n_in = 0.0;		// no. of points inside the shape
  double vtotal = 8.;	// volume of the cube

  FILE* inside;
  FILE* outside;
  if(plot){
    inside = fopen("TXT_OUT/A7Q2inside.txt","w");
    outside = fopen("TXT_OUT/A7Q2outside.txt","w");
  }  

  for(int i=0;i<npts;i++){
    double x = 2.*rand()/RAND_MAX-1.; // x in (-1,1)
    double y = 2.*rand()/RAND_MAX-1.; // y in (-1,1)
    double z = 2.*rand()/RAND_MAX;    // z in (0,2)

    bool IsIn = ((x*x+y*y+z*z-2.*z) < 0.); // within the sphere or not
    IsIn &= ((z*z) > (x*x+y*y));	   // Within the cone or not

    if(IsIn){
      n_in++;
      if(plot) if(DoPrint) fprintf(inside,"%.4f\t%.4f\t%.4f\n",x,y,z);
    }
    else if(plot) if(DoPrint) fprintf(outside,"%.4f\t%.4f\t%.4f\n",x,y,z);
  }

  return vtotal*n_in/ntotal;
}

double Question3(int npts)
{
  double ntotal = npts;		// total number of neutrons incident
  double npassed = 0.;		// no. of neutrons that passed

  for(int i=0;i<npts;i++){
    double length = 1.;
    for(int j=0;j<7;j++)
      length += cos(2.*M_PI*rand()/RAND_MAX-M_PI); // theta in (-pi,pi)
    if(length>=5.) npassed++;
  }
  return npassed/ntotal;
}

void Question4(int nparticles,string fname,double tol)
{
  FILE* outfile;
  outfile = fopen(fname.c_str(),"w");
  if(DoPrint) printf("Output written to the file: %s",fname.data());

  // double n_avg=nparticles;		// average number of particles
  double nleft = nparticles;
  double ntotal = nparticles;

  int time = 0;
  int t_eq = 0.;		// Time at which equilibrium is reached
  bool equl = false;		// whether the equilibrium is reached

  // Variables for Question b
  double avg_eq{0.};		// average after equilibrium
  double avg2_eq{0.};		// average square after equilibrium
  double t2_eq{0.};		// No. of timesteps considered after equilibrium

  for(int i=0;i<5000;i++){
    double navg = 0.;
    for(int j=0;j<5;j++){
      time++;
      if(nleft < ntotal*rand()/RAND_MAX)
	nleft++;
      else
	nleft--;
      navg += nleft;
      if(equl){
	avg_eq += (double)nleft;
	avg2_eq += (double)pow(nleft,2);
	t2_eq++;
      }
    }
    navg = navg/5.;
    if(DoPrint) fprintf(outfile,"%i\t%.1f\n",time,navg);
    if((!equl)&&(abs(navg-ntotal/2.)<=tol)){
      t_eq = time;
      // printf("No. of particles %d\tTime to equilibrium %d\t",nparticles,t_eq);
      printf("%d\t%d\t",nparticles,t_eq);
    }
    equl |= abs(navg-nparticles/2.)<=tol;
  }
  double var = avg2_eq/t2_eq-pow(avg_eq/t2_eq,2);
  double fluc = var*t2_eq/avg_eq;
  // printf("Variance %.4f\tFluctuations %.4f\n",var,fluc);
  printf("%.4f\t%.4f\n",var,fluc);
}
