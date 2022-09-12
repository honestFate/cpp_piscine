#include <stdio.h>
#include <stdlib.h>
int main ()
{
char *s[] = {"inf", "1e1", "1d1", "1f1"};
char * pEnd;
double d0, d1, d2, d3;
d0 = strtod (s[0],&pEnd);
printf ("a - %c\n", *pEnd);
d1 = strtod (s[1],&pEnd);
printf ("e - %c\n", *pEnd);
d2 = strtod (s[2],&pEnd);
printf ("d - %c\n", *pEnd);
d3 = strtod (s[3],&pEnd);
printf ("f - %c\n", *pEnd);

printf ("::: [%f] [%f] [%f] [%f] \n", d0, d1, d2, d3);
return 0;
}
