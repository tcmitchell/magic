/* Copyright (C) 1999 Lucent Technologies */
/* eprintf.h: error wrapper functions     */

/* ---------------------------------------------
 * From the book _The Practice of Programming_
 * Kernighan & Pike.
 * --------------------------------------------- */

#include <stdlib.h>

extern  void    eprintf(char *, ...);
extern  void    weprintf(char *, ...);
extern  char    *estrdup(char *);
extern  void    *emalloc(size_t);
extern  void    *erealloc(void *, size_t);
extern  char    *progname(void);
extern  void    setprogname(char *);

#define NELEMS(a)       (sizeof(a) / sizeof(a[0]))
