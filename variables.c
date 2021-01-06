#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);

  a = a - c;
  c = a + c;
  a = c - a;

  printf("A is equal to %d and B is equal to %d, and C is equal to %d\n", a, b, c);
}
