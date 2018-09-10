#include <stdint.h>
#include <stdio.h>
#include <string.h>

void reverso(char *str) //when reverso is called the string will be reversed
{
  int length,i,j;
  length= strlen(str); //finds the legnth of the string
  char *reverse_string;
  j=0;
  for (i=0; i< length-1; i++) // prevents the length of the string from going over by one and adding an extra character to the reversed string 
  {
    for (j=0; j<length-1-i; j++)
      {
	reverse_string=str[j]; //setting a temporary register to store the string
	str[j] = str [j+1]; 
	str[j+1] = reverse_string; // stores the value in the temporary register to the next character of str register
      }			    
  }
  return;
}

uint32_t get_bits( uint32_t regval, int lft_idx, int rgt_idx)// when get_bits is called this will execute and the bits the user selected
{
  int nbits;
  uint32_t one, sample;
  nbits = rgt_idx - lft_idx +1; //gets the number of bits to shift the one register over 
  one = 0xFFFFFFFF; // initializeing the one array
  one = one >> nbits-1; //shifts the one register over in order to get the correct number of bits
  regval = regval >> rgt_idx;
  regval = one & regval; // when these are & together it'll cancel out the bits to the left 
  printf("Get bits value %d\n",regval); // prints out the number of bits that were selected
  return regval; //returns the number of bits selected back to main
}

int main()
{
  // 1) reverso
  char test_str[]="xyzzy" ;
  printf("original test string %s\n", test_str); //prints the test string
  reverso(test_str); // should result in setting test_str to "yzzyx" and calls on the reverso function
  printf("reversed %s\n", test_str);
  // 2) get_bits
  get_bits(0x12345678, 11, 4); //returns 0x67 which is 103 in decimal
  getchar();
  return 0;
}


