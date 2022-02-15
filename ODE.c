// Function definitions for ODE solvers
#include"MainLibrary.h"
using namespace std;

double RungeKutta(int opt,double x0,double y0,double x1,double h,double (*func)(double,double))
{
  int N = (int)((x1-x0)/h);
  double X=x0;
  double y1 = y0;		// y(x1)

  if(opt==4){
    for(int i=0;i<N;i++){
      double k1 = h*func(X,y1);
      double k2 = h*func(X+h/2,y1+k1/2);
      double k3 = h*func(X+h/2,y1+k2/2);
      double k4 = h*func(X+h,y1+k3);
      y1 += (k1+2*k2+2*k3+k4)/6;
      X += h;
    }
  }
  else if(opt==3){
    for(int i=0;i<N;i++){
      double k1 = h*func(X,y1);
      double k2 = h*func(X+h/2,y1+k1/2);
      double k3 = h*func(X+h,y1-k1+2*k2);
      y1 += (k1+4*k2+k3)/6;
      X += h;
    }
  }
  else if(opt==2){
    for(int i=0;i<N;i++){
      double k1 = h*func(X,y1);
      double k2 = h*func(X+h/2,y1+k1/2);
      y1 += k2;
      X += h;
    }
  }
  return y1;
}

double Euler(double x0,double y0,double x1,double h,double (*func)(double,double))
{
  int N = (int)((x1-x0)/h);
  double X=x0;
  double y1 = y0;		// y(x1)
  for(int i=0;i<N;i++){
    y1 += h*func(X,y1);
    X += h;
  }
  return y1;
}

double Taylor(double x0,double y0,double x1,double h,double (*func)(double,double,int))
{
  int N = (int)((x1-x0)/h);
  double X=x0;
  double y1 = y0;		// y(x1)
  for(int i=0;i<N;i++){
    y1 += h*func(X,y1,0)+h*h*(func(X,y1,1)+func(X,y1,0)*func(X,y1,2))/2;;
    X += h;
  }
  return y1;
}
