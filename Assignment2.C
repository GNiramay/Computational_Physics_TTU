// C++ script to solve the assignment 2.

#include"MainLibrary.h"
using namespace std;

/*
 * @descr return value of x^2-5.
 * @par x value at wich function needs to be valuated
 * @par opt integer specifying what to return. opt=0->f(x), opt=1->f'(x)
*/
double func1(double x,int opt=0);

/*
 * @descr same as func1, except for parameter opt.
 */
double func2(double x);


int main()
{
  double x0=0;
  double x1=1;
  printf("N\tNewton\tSecant\tSearch\n");
  
  for(double i=1;i<34;i++){
    double rnewton = Newton(&func1,x1,i);
    double rsecant = Secant(&func2,x0,x1,i);
    double rsearch = Search(&func2,(x1-x0)/2,x1,i);
    printf("%.0f\t%.4f\t%.4f\t%.4f\n",i,func1(rnewton),func2(rsecant),func2(rsearch));
  }
  return 0;
}

double func1(double x,int opt)
{
  if(opt==0) return(pow(x,2)-5);
  if(opt==1) return(2*x);
  cout<<"ERROR. opt used: "<<opt<<endl;
  cout<<"Allowed values:\n";
  cout<<"opt = 0: for original function\n";
  cout<<"opt = 1: for function derivative\n";
  return -1;
}

double func2(double x)
{
  return func1(x);
}
