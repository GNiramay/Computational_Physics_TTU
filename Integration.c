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
    for(int i=0;i<N;i+=2){
      integral+= h*(
		    y[i]
		    +2*y[i+1]
		    +y[i+2]
		    )/2;
    }
  }

  // Simpson's 1/3 rule
  if(method=="simpson13"){
    if(N%2 != 1){
      printf("Error. vector size = %i\n",N);
      printf("Odd nunber of points needed for integration\n");
      return -1;
    }
    for(int i=0;i<N;i+=2){
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
    for(int i=0;i<N;i+=4){
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
