/*
 *
 */

/*
 * TO DO:
 *
 * Accept opts for acorner, bcorner and size.
 *
 * Handle negative sizes properly (error out?)
 *
 * test some computations.
 *
 * incorporate GNU automake/autoconf
 *
 * add basic x interface.  Athena?  GTK?  GTK.
 */

/*  #include <stdio.h> */
/*  #include <stdlib.h> */
#include "eprintf.h"
#include "complex.h"

double acorner;
double bcorner;
double extent;
double gap;

int **pic;

/*
 * Allocates a square two dimensional array of doubles of the given
 * size.
 */
int **
make_pic(int size)
{
  int i;			/* loop counter */
  int **result;

  result = (int **) emalloc ( sizeof(int *) * size );
  
  for (i=0; i<size; i++)
    result[i] = (int *) emalloc ( sizeof(int) * size );

  return result;
}


int
compute_value2(double cr, double ci)
{
  int i;
  double zr = 0.0;
  double zi = 0.0;
  double sz;
  double max = 2.0;
  double tmpr, tmpi;

  i = 0;
  while (i < 1000)
    {
      complex_product2(zr, zi, zr, zi, &tmpr, &tmpi);
      complex_sum2(tmpr, tmpi, cr, ci, &zr, &zi);

      i++;
      complex_size2(zr, zi, &sz);

      if (sz > max) break;
    }

  return i;
}

int
compute_value(complex *c)
{
  int i;
  complex z = { 0.0, 0.0 };
  complex tmp;
  complex_t sz;
  complex_t max = 4.0;

  i = 0;
  while (i < 1000)
    {
      complex_product(&z, &z, &tmp);
      complex_sum(&tmp, c, &z);
      i++;
      complex_size_squared(&z, &sz);

      if (sz > max) break;
    }

  return i;
}
