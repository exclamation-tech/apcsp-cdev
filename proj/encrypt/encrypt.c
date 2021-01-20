//
// encrypt.c
//

#include <string.h>
#include <stdio.h>
#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;

/* implement the character shift here:
    given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
    use the CHARS array above
    return the newly shifted char

   eg.
     shiftChar('c', 3, 1) : 'f'
     shiftChar('S', 2, 0) : 'P'
     shiftChar('b', 3, 0) : '8' */
char shiftChar(char c, int shift, int direction)
{
  //Define variable for where the character is located in the array
  int index = c;

  //Determines where the character is located
  if ('a' <= c && c <= 'z') {
    index -= 'a';
  } else if ( 'A' <= c && c <= 'Z') {
    index -= 39;
  } else if ('0' <= c && c <= '9') {
    index += 4;
  } else {

    //Returns if it eligble to be ciphered
    return c;
  }

  //Shifts depending on direction
  direction?(index += shift):(index = index - shift);

  //Puts back into bounds of array
  if(index < 0) {
    index += CHARS_LEN;
  } else if(index > 61) {
    index -= CHARS_LEN;
  }

  //returns encrypted result
  return CHARS[index];
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++)
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++)
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}
