/*
 * Gets One Root of polynomial by Newton's method
 * Modify function f() to find ints zeros
 * LIMIT is maximum allowed iterations in Newton's method
 * delta is the interval for numerical integration
 * TOL i tolernce between consecutive values to test convergence
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.c"
#define DELTA 0.00001
#define LIMIT 100
#define TOL 0.00001
#define INITIAL 5

double slope(double x, double (* funptr)(double ))
{
	return ((*funptr)(x + DELTA) - (*funptr)(x - DELTA))/(2 * DELTA);
}

double r00t(double (* funptr)(double),double tolerance,double ini)
{
	int iterations = 0;
	double x0 = ini;
	double x1 = x0 + 2 * tolerance;
	while (fabs(x1 - x0) > tolerance && iterations < LIMIT)
	{

		x0 = x1;
		x1 = x0 - (* funptr)(x0)/slope(x0,funptr);
		printf("%lf %lf %lf %lf\n",x0,x1,slope(x1,funptr),(* funptr)(x1));

		iterations++;
	}
	if (iterations == LIMIT)
	{
		fprintf(stderr,"Iteration Limit Exceeded\n");
		exit(1);
	}
	else
	{
		return x1;
	}
}	


int main()
{
	double (* funptr)(double) = &f;
	// Difficult to declare a pointer to a function that has a function pointer as arguement
	//double (* slopeptr)((double),double (* double)(double)) = &slope;
	double root = r00t(funptr,TOL,INITIAL);

	printf("%lf: %lf\n",root,(* funptr)(root));
	return 0;
}

