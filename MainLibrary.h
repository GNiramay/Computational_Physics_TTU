// Main library to store all the function declarations
#ifndef _MAINLIBRARY_H
#define _MAINLIBRARY_H

#include<iostream>
#include<math.h> 
#include<vector>
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
#endif
