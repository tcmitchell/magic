#
#
#

CFLAGS = -g -Wall 

LDLIBS = -L/usr/X11/lib -lXaw -lXt -lm

SRCS = mandelzoom.c eprintf.c complex.c athena.c

OBJS = $(SRCS:.c=.o)

mandelzoom:	$(OBJS)
	$(LINK.c) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) *.o
	$(RM) mandelzoom
