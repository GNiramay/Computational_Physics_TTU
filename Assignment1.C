// C++ script to solve the first assignment.

#include"MainLibrary.h"
using namespace std;

// Q1. Write a program to find integral exp(x) from 0 to 1. Use Trapezoidal, Simponson's and Bode's rule to calculate the integral. Increase the numer of steps from 4,8,16,...128 and compare the results with the analytical result. (Analytically, integral = e-1)
void Question1();

// Q2. Write a program to find integral t^(-2/3).(1-t)^(-1/3) from 0 to 1. Use Trapezoidal, Simponson's and Bode's rule to calculate the integral. Increase the numer of steps from 4,8,16,...128 and compare the results with the analytical result. (Analytically, integral = 2*pi/sqrt(3))
void Question2();

int main()
{
  Question1();
  Question2();
  return 0;
}

void Question1()
{
  double xmin = 0.0;
  double xmax = 1.0;
  double Itrue = exp(1)-1;	// e-1
  printf("Question 1\nN\tTrapez.\t\tSimpson\t\tBode\n");
  for(double N=4.0;N<=128.0;N=N*2.0){
    vector<double>x,y;
    double h = (xmax-xmin)/N;
    
    for(double i=0.0;i<=N;i++){
      double x_ = xmin+h*i;
      x.push_back(x_);
      y.push_back(exp(x_));
    }
    
    printf("%.0f\t%.8f",N,Integrate1(x,y,"trapezoidal"));
    printf("\t%.8f",Integrate1(x,y,"simpson13"));
    printf("\t%.8f\n",Integrate1(x,y,"bode"));
  }
  printf("Analytical solution: %.8f\n",Itrue);
}

void Question2()
{
  double x1min = 0.0;
  double x1max = pow(0.5,1.0/3.0);
  double x2min = 0.0;
  double x2max = pow(0.5,2.0/3.0);
  
  double Itrue = 2*M_PI/sqrt(3);	// 2*pi/sqrt(3)
  printf("\nQuestion 2\nN\tTrapez.\t\tSimpson\t\tBode\n");
  for(double N=4.0;N<=128.0;N=N*2.0){
    vector<double>x1,x2,y1,y2;
    double h1 = (x1max-x1min)/N;
    double h2 = (x2max-x2min)/N;

    for(double i=0.0;i<=N;i++){
      double x1_ = x1min+h1*i;
      double x2_ = x2min+h2*i;
      double y1_ = 3.0*pow(1.0-x1_*x1_*x1_,-1.0/3.0);
      double y2_ = 1.5*pow(1.0- pow(x2_,1.5),-2.0/3.0);
      x1.push_back(x1_);
      x2.push_back(x2_);
      y1.push_back(y1_);
      y2.push_back(y2_);
    }
    
    printf("%.0f\t%.8f",N,Integrate1(x1,y1,"trapezoidal")+Integrate1(x2,y2,"trapezoidal"));
    printf("\t%.8f",Integrate1(x1,y1,"simpson13")+Integrate1(x2,y2,"simpson13"));
    printf("\t%.8f\n",Integrate1(x1,y1,"bode")+Integrate1(x2,y2,"bode"));
  }
  printf("Analytical solution: %.8f\n",Itrue);
}
