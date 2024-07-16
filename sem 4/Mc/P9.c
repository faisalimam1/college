//Simulate in pros in C for ARM microcontiller to demonstrate case conversion of characters from upper to lower case upper case and lower to

#include <stdio.h>
#include <lpc214x.h>

int main () 
{
  char ch = 'c';
  if(ch >='a' && ch <='z')
  {
    PINSEL0 = ch;
  }
  else if(ch >='A' && ch<='Z')
  {
    PINSEL0 = ch;
  }
  else
    PINSEL0=ch;
  return 0;
}
