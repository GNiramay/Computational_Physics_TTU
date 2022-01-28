// Root finding algorithms

#include"MainLibrary.h"
using namespace std;

double Newton(double (*func)(double,int), double x0, int iter, double tol)
{
  double X = x0;
  for(int i=0;i<iter;i++){
    if(func(X,1)==0){
      cout<<"derivative is zero.\nX="<<X<<endl;
      return X;
    }
    X -= func(X,0)/func(X,1);
    if(abs(func(X,0))<=tol) return X;
  }
  return X;
}

double Secant(double (*func)(double), double x0, double x1, int iter, double tol)
{
  double X0 = x0;
  double X1 = x1;
  double der = 0;
  
  for(int i=0;i<iter;i++){
    if(X0==X1) return X1;
    der = (func(X1)-func(X0))/(X1-X0);
    if(der==0){
      cout<<"Numerical derivative is zero.\nX0="
	  <<X0<<", X1="<<X1
	  <<"\nStopping\n";
      return X1;
    }
    X0 = X1;
    X1 -= func(X1)/der;
    if(abs(func(X1))<=tol) return X1;
  }
  return X1;
}

double Search(double (*func)(double), double step_size, double x0, int iter, double tol)
{
  double h = step_size;		// Step size. Will change over time
  double root=x0;		// root of the function
  int N = 0;			// Counter for the number of iterations ellapsed

  if(abs(func(x0+h))>abs(func(x0-h)))
    h = -h;

  for(int i=0;i<iter;i++){    
    if(func(root)*func(root+h)<0) {
      N=i;
      break;
    }
    else if(abs(func(root))<=tol) return root;    
    else root+=h;    
  }

  for(int i=0;i<iter-N;i++){
    if(func(root)*func(root+h)<0) {
      h = h/2;
    }
    else if(abs(func(root))<=tol) return root;
    else root+=h;
  }

  return root+h;
}
