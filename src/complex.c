/*
 *
 */

#include <stdio.h>
#include <math.h>
#include "complex.h"


void
complex_product(double ar, double ai,
	      double br, double bi,
	      double *cr, double *ci)
{
  double r = (ar * br) - (ai * bi);
  double i = (ar * bi) + (ai * br);
  *cr = r;
  *ci = i;
/*    printf("complex_product = %lf, %lf\n", *cr, *ci); */
}

void
complex_sum(double ar, double ai,
	  double br, double bi,
	  double *cr, double *ci)
{
  double r = ar + br;
  double i = ai + bi;
  *cr = r;
  *ci = i;
/*    printf("cplex_sum = %lf, %lf\n", *cr, *ci); */
}

void
complex_size(double r, double i, double *s)
{
  *s = sqrt( (r * r) + (i * i) );
}
