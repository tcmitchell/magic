
#include <stdio.h>

int
main(void)
{
  unsigned long x;
  unsigned char *p;
  int i;

  printf("size of long: %d\n", sizeof(long));
  x = 0x11223344UL;
  p = (unsigned char *) &x;
  for (i = 0; i < sizeof(long); i++)
    {
      printf("%x ", *p++);
    }
  printf("\n");
  return 0;
}
