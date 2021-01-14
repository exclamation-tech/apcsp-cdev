#include <stdio.h>
#include <string.h>

int main()
{
  //String created with a for loop
  char string1[26];
  string1[26] = '\0';
  for (int i = 0; i < 26; i++) {
    string1[i] = 97 + i;
  }
  //Second string created with a constant initializer
  char string2[] = "abcdefghijklmnopqrstuvwxyz";
  //Compare the two strings to test if they are the same
  if (strcmp(string1, string2) == 0)
    printf("The first string and the second string are identical!\n");
  else
    printf("The first string and the second string are different!\n");
  //Update the first string to uppercase in a for loop by adding a constant integer value
  for (int i = 0; i < 26; i++) {
    string1[i] -= 32;
  }
  //Compare the two strings to test if they are different
  if (strcmp(string1, string2) == 0)
    printf("The first string and the second string are identical!\n");
  else
    printf("The first string and the second string are different!\n");
  //Create a third string which holds both upper and lower by joining the first two strings
  char string3[52];
  strcpy(string3, string1);
  strcat(string3, string2);
  //Print out all three strings
  printf("The first string: %s\n", string1);
  printf("The second string: %s\n", string2);
  printf("The third string: %s\n", string3);
}
