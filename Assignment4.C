// C++ script to solve the assignment 4

#include"MainLibrary.h"
using namespace std;

/*
 * @descr calculates range of the projectile in absence of air resistance
 * @par x0 = initial x-coordinate
 * @par y0 = initial y-coordinate
 * @par V = magnitude of velocity
 * @par theta = inclination
 * @par tol = tolerance 
 */
double GetRange(double x0,double y0,double V,double theta,double tol);

/*
 * @descr same as GetRange, but with air resistance
 * @par C = constant used in the equation: d^2r/dt^2 = -C*V^2
 */
double GetRangeWithAR(double x0,double y0,double V,double theta,double C,double tol);

double g = -9.8;		// gravitational acceleration [m/s^2]

// Question 1
// 1. Plot 2-d trajectory of ball moving in air
// 2. For V=15m/s, vary theta and find range
// 3. Show that the max range occurs for theta = pi/4
// 4. Print maximum range and compare it with v^2/g
void Question1();

// Question 2
// 1. Find maximum range if y(t=0)=2m
// 2. Print the deviation in range if theta is deviated by 2% from theta_max
void Question2();

// Question 3
// 1. Considering air resistance of the form F = k2*V*2 with k2=0.01,
//    calculate the optimum angle for maximum range if h=2m,V=30m/s C=k2/m=0.1
// 2. Compare the answer with Question 2.
// 3. Check if the range is more sensitive to theta as compared to case without air resistance
// 4. Calculate the maximum range for C = 0.001
void Question3();

int main()
{
  Question1();
  Question2();
  Question3();
  return 0;
}

double GetRange(double x0,double y0,double V,double theta,double tol)
{
  double x_ = x0;
  double y_ = y0;
  double vx = V*cos(theta);
  double vy = V*sin(theta);
  double dt = 0.01;		// step size in time
  
  while((y_>tol)||(vy>0)){
    if(y_+dt*vy<=tol) return x_-x0;
    y_ += dt*vy;
    x_ += dt*vx;
    vy += dt*g;
  }

  return x_-x0;
}

void Question1()
{
  double x_ = 0;
  double y_ = 0.001;
  double V = 15;
  double theta = M_PI/6.;	// angle = 30 degrees
  double vx = V*cos(theta);
  double vy = V*sin(theta);
  double dt = 0.01;		// step size in time
  printf("Question1\nX\tY\n");
  while(y_>0){
    printf("%.3f\t%.3f\n",x_,y_);
    y_ += dt*vy;
    x_ += dt*vx;
    vy += dt*g;
  }
  printf("\ntheta\tRange\n");
  double rmax = 0;
  double theta_max = 0;
  for(double theta_=0;theta_<M_PI/2.;theta_+=0.01){
    double range  = GetRange(0.,0.,15.,theta_,0.);
    if(range>rmax){
      rmax = range;
      theta_max = theta_;
    } 
    printf("%.4f\t%.4f\n",theta_,range);
  }
  printf("\tNumerical\tAnalytical\n");
  printf("rmax\t%.4f\t\t%.4f\n",rmax,V*V/abs(g));
  printf("theta\t%.4f\t\t%.4f\n",theta_max,M_PI/4.);
}

void Question2()
{
  printf("\nQuestion2\n");
  double x_ = 0.;
  double y_ = 2.;
  double V = 15;
  double rmax = 0;
  double theta_max = 0;
  for(double theta_=0;theta_<M_PI/2.;theta_+=0.001){
    double range  = GetRange(x_,y_,V,theta_,0.);
    if(range>rmax){
      rmax = range;
      theta_max = theta_;
    }
  }
  printf("rmax\t%.4f\n",rmax);
  printf("theta\t%.4f\n",theta_max);
  printf("deviation from rmax = %.4fpc\n",100*abs(GetRange(x_,y_,V,theta_max*1.02,0.)/rmax-1.));
}

void Question3()
{
  printf("\nQuestion3\n");
  double x_ = 0.;
  double y_ = 2.;
  double V = 30.;
  double rmax = 0;
  double rmax2 = 0;
  double theta_max = 0;
  for(double theta_=0;theta_<M_PI/2.;theta_+=0.01){
    double range  = GetRangeWithAR(x_,y_,V,theta_,0.1,0.);
    double range2  = GetRangeWithAR(x_,y_,V,theta_,0.001,0.);
    if(range>rmax){
      rmax = range;
      theta_max = theta_;
    } 
    if(range2>rmax2) rmax2 = range2;
    
    printf("%.4f\t%.4f\n",theta_,range);
  }
  printf("rmax\t%.4f\n",rmax);
  printf("theta\t%.4f\n",theta_max);
  printf("deviation from rmax = %.4fpc\n",100*abs(GetRangeWithAR(x_,y_,V,theta_max*1.02,0.1,0.)/rmax-1.));
  printf("rmax for C=0.001: %.4f\n",rmax2);
}

double GetRangeWithAR(double x0,double y0,double V,double theta,double C,double tol)
{
  double x_ = x0;
  double y_ = y0;
  double vx = V*cos(theta);
  double vy = V*sin(theta);
  double dt = 0.01;		// step size in time
  
  while((y_>tol)||(vy>0)){
    if(y_+dt*vy<=tol) return x_-x0;
    y_ += dt*vy;
    x_ += dt*vx;
    double mag = pow(vx*vx+vy*vy,0.5);	// |V|
    vy += dt*(g-C*mag*vy);
    vx -= dt*C*mag*vx;
  }

  return x_-x0;
}
