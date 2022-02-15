// C++ script to solve the assignment 3.

#include"MainLibrary.h"
using namespace std;

// Q1. solve the differential equation dy/dx = -x*y with initial condition: x=0,y=1
// Find y at x=1,3 using Euler, Taylor implicit and RK4.
// Take step size 0.5,0.2,0.05,0.02,0.01,0.005,0.002,0.001
// @par x1 = x-value at which y needs to be evaluated
void Question1(double x1);

/*
 * @descr returns -x*y.
 */
double func(double x,double y);
double func(double x,double y){return -x*y;}

/*
 * @descr sames as func, but with provision of derivatives
 * @par opt: 0->f(x,y),1->df/dx, 2->df/dy
 */
double func2(double x,double y,int opt);

// The step sizes
vector<double> H = {0.5,0.2,0.05,0.02,0.01,0.005,0.002,0.001};

int main()
{
  Question1(1.);
  Question1(3.);
  return 0;
}

void Question1(double x1)
{
  double Itrue = exp(-x1*x1/2);
  printf("y(x) evaluated at x = %.1f\n",x1);
  printf("h\tEuler\t\tTaylor\t\tRK4\n");
  for(int i=0;i<(int)H.size();i++){
    double e_RK4 = abs(RungeKutta(4,0.,1.,x1,H[i],&func)-Itrue);
    double e_Tay = abs(Taylor(0.,1.,x1,H[i],&func2)-Itrue);
    double e_Eul = abs(Euler(0.,1.,x1,H[i],&func)-Itrue);
    printf("%.3f\t%.4E\t%.4E\t%.4E\n",H[i],e_Eul,e_Tay,e_RK4);
  }
  printf("Analytical value: %.4E\n\n",Itrue);
}

double func2(double x,double y,int opt)
{
  if(opt==0) return -x*y;
  if(opt==1) return -y;
  else return -x;
}
