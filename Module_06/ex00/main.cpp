#include <stdio.h>

int main ()
{
  char sentence [] = "111111121312312";
  char str [20];
  int i;

  int err = sscanf (sentence, "%d" ,&i);
  printf ("%d %d\n", i, err);
  
  return 0;
}
