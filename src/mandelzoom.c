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

#include <stdio.h>
#include <stdlib.h>
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
compute_value(double cr, double ci)
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
      complex_product(zr, zi, zr, zi, &tmpr, &tmpi);
      complex_sum(tmpr, tmpi, cr, ci, &zr, &zi);

      i++;
      complex_size(zr, zi, &sz);

      if (sz > max) break;
    }

  return i;
}

/*
 *
 */
#ifdef MANDEL_MAIN
int
main(int argc, char* argv[])
{
  int size;
  int i, j;			/* loop counters */

  if (argc < 2)
    {
      fprintf(stderr, "usage: mandelzoom <size>\n");
      exit(1);
    }

  size = atoi(argv[1]);
  fprintf(stdout, "got size %s, converted to %d.\n", argv[1], size);
  pic = make_pic(size);

  acorner = .26;
  bcorner = 0;

  extent = .01;

  gap = extent / size;

  for (i=0; i<size; i++)
    for (j=0; j<size; j++)
      pic[i][j] = compute_value((gap * i) + acorner,
				(gap * j) + bcorner);

  for (i=0; i<size; i++)
    for (j=0; j<size; j++)
      if (pic[i][j] != 1000)
	printf("pic[%3d][%3d] = %d\n", i, j, pic[i][j]);

  return 0;
}
#endif /* MANDEL_MAIN */
