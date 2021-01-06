#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = 'b';

  printf("char b value: %d and size: %lu bytes\n", b, sizeof(b));

  float c = 'c';

  printf("float c value: %d and size %lu bytes\n", c, sizeof(c));

  double d = 'd';

  printf("double d value: %d and size %lu bytes\n", d, sizeof(d));

  short int e = 321;

  printf("short int e value: %d and size %lu bytes\n", e, sizeof(e));

  long int f = 123;

  printf("long int f value: %d and size %lu bytes\n", f, sizeof(f));
}
