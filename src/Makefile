#
#
#

CFLAGS = -g -Wall 
LDFLAGS = -L/usr/X11R6/lib
LDLIBS = -lXaw -lXt -lm


UTIL_SRCS = eprintf.c

MANDEL_SRCS = mandelbrot.c complex.c athena.c $(UTIL_SRCS)
MANDEL_OBJS = $(MANDEL_SRCS:.c=.o)

MARKOV_SRCS = markov.c $(UTIL_SRCS)
MARKOV_OBJS = $(MARKOV_SRCS:.c=.o)

all: mandelzoom markov

mandelzoom:	$(MANDEL_OBJS)
	$(LINK.c) -o $@ $(MANDEL_OBJS) $(LDFLAGS) $(LDLIBS)

markov:	$(MARKOV_OBJS)
	$(LINK.c) -o $@ $(MARKOV_OBJS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) *.o
	$(RM) mandelzoom markov
