/*
 * From "The Practice of Programming".
 */

/* eprintf: print error message and exit */
void eprintf(char *, ...);

/* emalloc: malloc and report if error. */
char * estrdup(char *);

/* emalloc: malloc and report if error. */
void * emalloc(size_t);

/* progname: return stored name of program */
char * progname(void);

/* setprogname: set stored name of program */
void setprogname(char *);
