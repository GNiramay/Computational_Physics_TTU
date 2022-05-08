// File to store the commonly used methods of numerical integration
#include"MainLibrary.h"

using namespace std;

double Integrate1(vector<double>x,vector<double>y, string method)
{
  int N = x.size();		// No. of steps considered
  double h = x[1]-x[0];		// step size
  double integral=0.0;		// Integral

  // Trapezoidal method
  if(method=="trapezoidal"){
    if(N%2 != 1){
      printf("Error. vector size = %i\n",N);
      printf("Odd nunber of points needed for integration\n");
      return -1;
    }
    for(int i=0;i<N-1;i++){
      integral += h*(y[i]+y[i+1])/2;
    }
  }

  // Simpson's 1/3 rule
  if(method=="simpson13"){
    if(N%2 != 1){
      printf("Error. vector size = %i\n",N);
      printf("Odd nunber of points needed for integration\n");
      return -1;
    }
    for(int i=0;i<N-2;i+=2){
      integral+= h*(
		    y[i]
		    +4*y[i+1]
		    +y[i+2]
		    )/3;
    }
  }
  
  // Bode's rule
  if(method=="bode"){
    if(N%4 != 1){
      printf("Error. vector size = %i\n",N);
      printf("4n+1 nunber of points needed for integration\n");
      return -1;
    }
    for(int i=0;i<N-4;i+=4){
      integral+= 2*h*(
		      7*y[i]
		      +32*y[i+1]
		      +12*y[i+2]
		      +32*y[i+3]
		      +7*y[i+4]
		      )/45;
    }
  }
  
  return integral;
}

double MonteCarlo2D(vector<double> x,vector<double> y,double area,double (*func)(double,double))
{
  double npts = x.size();		// no. of points
  double result = 0;		// The integral
  for(int i=0;i<(int)npts;i++){
    result += func(x[i],y[i]);
  }
  result  = result/npts;
  return result*area;
}

double MonteCarlo3D(vector<double>x,vector<double>y,vector<double>z,double vol,double (*func)(double,double)){
  double ntot = x.size();
  double ngood{0.};		// number of good points (points under the curve)
  for(int i=0;i<(int)ntot;i++){
    double f_xy = func(x[i],y[i]);
    if(f_xy>=z[i]) ngood++;
  }
  return vol*ngood/ntot;
}
