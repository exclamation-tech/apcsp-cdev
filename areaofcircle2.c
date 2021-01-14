#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle (float radius) {
  return (radius * radius * M_PI);
}

// the two variables which control the number of times areaOfCircle is called
// in this case 5.2, 6.2, 7.2
float end;
float reps;
char input[256];
float start;

// function to take input from the user
void takeInput() {
  printf("\033[1;34mWhat is the lower input?\033[0m\n");
  while(1) {
    fgets(input, 256, stdin);
    if ((sscanf(input, "%f", &start) ==1) && (start > 0)) break;
    printf("\033[0;31mInvalid input, make sure to enter a valid number\033[0m\n");
  }
  printf("\033[1;34mWhat is the higher input?\033[0m\n");
  while(1) {
    fgets(input, 256, stdin);
    if ((sscanf(input, "%f", &end) ==1) && end > 0) break;
    printf("\033[0;31mInvalid input, make sure to enter a valid number\033[0m\n");
  }
}
int main(int argc, char* argv[]) 
{
  // loop to check if there are command line arguments
  if (argc == 1) {
    takeInput();
  } else if (argc == 3) {
  } else {
  printf("\033[0;31m[ERROR] Invalid amount of arguments specified, please try again\033[0m\n");
  }
  // for testing only - do not change
  // getTestInput(argc, argv, &start, &reps);

  printf("calculating area of circle starting at %f, and ending at %f\n", start, end);

  // add your code below to call areaOfCircle function with values between
  // start and end
  reps = end - start;
  for (int i = 0; i < reps; i++)
  {
    float circleArea = areaOfCircle(start + i);
    printf("The area of the circle of radius %f is %f\n", start+i, circleArea);
  }
}
