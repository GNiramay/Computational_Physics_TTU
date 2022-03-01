// C++ script to solve the assignment 5
#include"MainLibrary.h"
using namespace std;

/*
 * @brief returns the magnitude of the central force 
 * @par x The x-coordinate of the particle
 * @par y The y-coordinate of the particle
 */
double Classical_Gravity(double x, double y);
double Perturbed_Gravity(double x, double y);
double Einsteins_Gravity(double x, double y);
double Cubic_Gravity(double x, double y);

/*
 * @brief prints trajectory of the particle given the acceleration
 * @par dt step size in time
 * @par func pointer to the function which gives acceleration
 */
void GetTrajectory(double dt,double (*func)(double,double));

double Vy_for_Circular_Orbit(double dt,double tol,double (*func)(double,double));

double C_ = 4.0*M_PI*M_PI;
double x0_ = 1.;
double y0_ = 0.;
double vx0_ = 0.;
double vy0_ = 5.;

int main()
{
  printf("Classical Gravity\n");
  GetTrajectory(0.001,&Classical_Gravity);	// Classical gravity
  printf("Perturbation to Classical Gravity\n");
  GetTrajectory(0.001,&Perturbed_Gravity);	// small perturbation to classical gravity
  printf("Einstein's Gravity\n");
  GetTrajectory(0.001,&Einsteins_Gravity);	// Einstein's gravity
  printf("Vy for circular orbit: %.4f\n",Vy_for_Circular_Orbit(0.0001,0.01,&Cubic_Gravity));
  vy0_ = 1.02*Vy_for_Circular_Orbit(0.0001,0.01,&Cubic_Gravity);
  printf("Cubical force\n");
  GetTrajectory(0.001,&Cubic_Gravity);	// Einstein's gravity
  return 0;
}

double Classical_Gravity(double x, double y)
{
  return -C_/(x*x+y*y);
}

double Perturbed_Gravity(double x, double y)
{
  return -C_*pow(x*x+y*y,-2.05/2.0);
}

double Einsteins_Gravity(double x, double y)
{
  double alpha = 0.001;		 // Actually alpha/c^2
  double r1 = pow(x*x+y*y,-0.5);	// 1/r
  return -C_*r1*r1*(1-alpha*C_*r1);
}

double Cubic_Gravity(double x, double y)
{
  return -C_*pow(x*x+y*y,-1./6.);
}

void GetTrajectory(double dt,double (*func)(double,double))
{
  double x = x0_;
  double y = y0_;
  double vx = vx0_;
  double vy = vy0_;
  double time = 0.;

  printf("x,y,r\n");
  while((time<50.0*dt) || (x0_-x>0.0001)){
    double rr = pow(x*x+y*y,-0.5); // 1/r
    double acc = func(x,y);
    vx += x*acc*dt*rr;
    vy += y*acc*dt*rr;
    x += vx*dt;
    y += vy*dt;

    time += dt;
    printf("%.4f,%.4f,%.4f\n",x,y,pow(x*x+y*y,0.5));
  }
}

double Vy_for_Circular_Orbit(double dt,double tol,double (*func)(double,double))
{
  double v0 = 0.01;
  for(int i=0;i<1000;i++,v0+=0.01){
    double x = x0_;
    double y = y0_;
    double vx = vx0_;
    double vy = v0;
    double time = 0.;
    while(abs(1.0-pow(x*x+y*y,0.5))<=tol){
      double rr = pow(x*x+y*y,-0.5); // 1/r
      double acc = func(x,y);
      vx += x*acc*dt*rr;
      vy += y*acc*dt*rr;
      x += vx*dt;
      y += vy*dt;
      time +=dt;
      if(time > 5.) return v0;
    }
  }
  return -1.;
}
