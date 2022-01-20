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
  double xmin = 0;
  double xmax = 1;
  printf("Question 1\nN\tTrapez.\tSimpson\tBode\n");
  for(double N=4;N<=128;N=N*2){
    vector<double>x,y;
    double h = (xmax-xmin)/N;
    
    for(double i=0;i<=N;i++){
      double x_ = xmin+h*i;
      x.push_back(x_);
      y.push_back(exp(x_));
    }
    
    printf("%.0f\t%.4f",N,Integrate1(x,y,"trapezoidal"));
    printf("\t%.4f",Integrate1(x,y,"simpson13"));
    printf("\t%.4f\n",Integrate1(x,y,"bode"));
  }
}

void Question2()
{
  double xmin = 0.001;
  double xmax = 0.999;
  printf("\nQuestion 2\nN\tTrapez.\tSimpson\tBode\n");
  for(double N=4;N<=128;N=N*2){
    vector<double>x,y;
    double h = (xmax-xmin)/N;

    for(double i=0;i<=N;i++){
      double x_ = xmin+h*i;
      x.push_back(x_);
      double y_ = pow(x_*x_*(1-x_),-1./3.);
      y.push_back(y_);
    }
    
    printf("%.0f\t%.4f",N,Integrate1(x,y,"trapezoidal"));
    printf("\t%.4f",Integrate1(x,y,"simpson13"));
    printf("\t%.4f\n",Integrate1(x,y,"bode"));
  }
}
