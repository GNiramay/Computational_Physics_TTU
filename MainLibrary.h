// Main library to store all the function declarations
#ifndef _MAINLIBRARY_H
#define _MAINLIBRARY_H

#include<iostream>
#include<math.h> 
#include<vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * @brief return integral of function using different algorithms
 * @par x vector of doubles where the function is evaluated
 * @par y vector of doubles storing function values
 * @par method string specifying which algorithm to use. Values are: trapezoidal,simpson13,bode
*/
double Integrate1(vector<double>x,vector<double>y, string method);

/*
 * @descr returns root of the function in given number of iterations and tolerance
 * @par x0 initial guess
 * @par func pointer to the function whose root needs to be found out.
 * Its arguments are: value at which it needs to be evaluated, whether to use the function or its derivative
 * @par tol tolerance level. It's zero by default.
 */
double Newton(double (*func)(double,int), double x0, int iter, double tol=0);

/*
 * @descr returns root of the function in given number of iterations and tolerance. Newton-secan algorithm is been used
 * @par x0 initial guess
 * @par x1 expected initial better guess. (preferably x0,x1 should be close by)
 * @par func pointer to the function whose root needs to be found out.
 * Its arguments are: value at which it needs to be evaluated
 * @par tol tolerance level. It's zero by default.
 */
double Secant(double (*func)(double), double x0, double x1, int iter, double tol=0);

/*
 * @descr Returns root of the function by iterative search
 * @par func pointer to the function whose root needs to be found out
 * @par step_size the initial step size for search
 * @par x0 initial guess
 * @par iter Number of iterations to run for
 * @par tol
*/
double Search(double (*func)(double), double step_size, double x0, int iter, double tol=0);

/*
 * @brief return integral of function using Runge-Kutta family of algorithms
 * @par opt integer specifying which algorithm to use. Values are: 4
 * @par x0 Initial x-value
 * @par y0 Initial y-value
 * @par x1 x-value at which y needs to be evaluated
 * @par h step size
 * @par func pointer to the function f(x,y) used in ODE: dy/dx = f(x,y)
*/
double RungeKutta(int opt,double x0,double y0,double x1,double h,double (*func)(double,double));

/*
 * @brief solves ODE using Euler's method
 * @par x0 Initial x-value
 * @par y0 Initial y-value
 * @par x1 x-value at which y needs to be evaluated
 * @par h step size
 * @par func pointer to the function f(x,y) used in ODE: dy/dx = f(x,y)
*/
double Euler(double x0,double y0,double x1,double h,double (*func)(double,double));

/*
 * @brief solves ODE by Taylor's series expansion
 * @par x0 Initial x-value
 * @par y0 Initial y-value
 * @par x1 x-value at which y needs to be evaluated
 * @par h step size
 * @par func pointer to the function f(x,y) used in ODE: dy/dx = f(x,y)
 * @note func requires 3 params. 3rd one specifying the derivative
*/
double Taylor(double x0,double y0,double x1,double h,double (*func)(double,double,int));


/*
 * @brief Monte Carlo integration eithout random numbers
 * @ par N number of points to consider
 * @par x1 the lower bound for integration
 * @par x2 the upper bound for integration
 * @par func pointer to the function to be integrated
*/
double MonteCarlo2D(vector<double> x,vector<double> y,double area,double (*func)(double,double));

/*
 * @brief Monte Carlo integration of functions z = f(x,y)
 * @ par x,y,z vectors storing coordnates of the points used for integration
 * @par vol the volume enclosing the random points (Should be more than the expected integral value)
 * @par func pointer to the function f(x,y) to be integrated
*/
double MonteCarlo3D(vector<double>x,vector<double>y,vector<double>z,double vol,double (*func)(double,double));

#endif
