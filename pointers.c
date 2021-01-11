#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 1;
  float e = 2;

  float* ptrtod = &d;
  float* ptrtoe = &e;

  printf("The value of ptrtod is %p\n", (void*)ptrtod);
  printf("It stores the value %f\n", *ptrtod);
  printf("The address of d is %p\n", (void*)&d);

  printf("The value of ptrtoe is %p\n", (void*)ptrtoe);
  printf("It stores the value %f\n", *ptrtoe);
  printf("The address of e is %p\n", (void*)&e);

  float f = d;

  *ptrtod = e;
  *ptrtoe = f;

  printf("The value of ptrtod is %p\n", (void*)ptrtod);
  printf("It stores the value %f\n", *ptrtod);
  printf("The address of d is %p\n", (void*)&d);

  printf("The value of ptrtoe is %p\n", (void*)ptrtoe);
  printf("It stores the value %f\n", *ptrtoe);
  printf("The address of e is %p\n", (void*)&e);
}
