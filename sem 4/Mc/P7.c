//Simulate a microcontroller program in C for ARM microcontroller to sort numbers in asconding/descending order using bubble sort

#include <stdio.h>
#include <lpc214x.h>

int main ()
{
  unsigned long array[]={ 0x555555,0x444444, 0x333333,0x222222,0x111111 };
  unsigned long temp, i,j; 
  for(i=0; i<5; i++) 
  {
    for (j=0; j<5; j++)
    {
      if (array [j] > array [j+1])
      { 
        temp = array [j+1]; 
        array [j+1] = array[j];
        array [j] = temp;
      }
    }
  }while(1);
 return 0;
}
