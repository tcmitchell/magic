/*
 *
 */

typedef float complex_t;
/*  typedef double complex_t; */

struct complex
{
  complex_t r;
  complex_t i;
};

typedef struct complex complex;

void
complex_product2(double ar, double ai,
		double br, double bi,
		double *cr, double *ci);

void
complex_sum2(double ar, double ai,
	    double br, double bi,
	    double *cr, double *ci);

void
complex_size2(double r, double i, double *s);

void complex_product(complex *a, complex *b, complex *result);
void complex_sum(complex *a, complex *b, complex *result);
void complex_size(complex *a, complex_t *result);
void complex_size_squared(complex *a, complex_t *s);
