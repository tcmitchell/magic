/*
 *
 */

#include <stdio.h>
#include <math.h>
#include "complex.h"


void
complex_product2(double ar, double ai,
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
complex_sum2(double ar, double ai,
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
complex_size2(double r, double i, double *s)
{
  *s = sqrt( (r * r) + (i * i) );
}

void
complex_product(complex *a, complex *b, complex *result)
{
  complex tmp;
  tmp.r = (a->r * b->r) - (a->i * b->i);
  tmp.i = (a->r * b->i) + (a->i * b->r);
  result->r = tmp.r;
  result->i = tmp.i;
}

void
complex_sum(complex *a, complex *b, complex *result)
{
  complex tmp;
  tmp.r = a->r + b->r;
  tmp.i = a->i + b->i;
  result->r = tmp.r;
  result->i = tmp.i;
}

void
complex_size(complex *a, complex_t *s)
{
  *s = (complex_t) sqrt( (a->r * a->r) + (a->i * a->i) );
}

void
complex_size_squared(complex *a, complex_t *s)
{
  *s = (a->r * a->r) + (a->i * a->i);
}
