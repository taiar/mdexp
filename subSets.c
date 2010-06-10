/**
 * Subsets
 *
 * 10 Jun 2010
 *
 * This is a try for an efficient way to generate all the subsets of a set of
 * integers. 
 *
 * Andre Taiar < taiar ( ao ) hotmail com >
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Returns the value of the position from the binary representation of an
 * integer.
 *
 * unsigned int number - the integer number
 * unsigned int position - the position we need
 */
char getBinaryPos(unsigned int number, unsigned int position)
{
  char otherBuff;
  
  //get the position by giving a shift right and doing a AND with a binary mask
  unsigned int buff = (number >> position) & 1;

  //converts int to char
  sprintf(&otherBuff,"%d",buff);

  return otherBuff;
}

/**
 * Returns a string with the binary representation of an integer with the
 * especified bit range. The string returned got the number "inverted". It means
 * that the less significative algarism of the number is in the first position
 * of the string and the most significative is the last one.
 *
 * unsigned int number - the integer number
 * unsigned short int range - the bit range of the number
 */
char* getBinaryStringInverted(unsigned int number, unsigned short int range)
{
  int i = 0;
  char *theString = (char*) malloc((sizeof(char) * range) + 1);

  for(; i < range; i += 1)
    theString[i] = getBinaryPos(number, i);

  theString[range + 1] = '\0';

  return theString;
}

/**
 * Returns a int array with size "n" and with it's elements variating by 1 from
 * 1 to "n".
 *
 * int n - the size of the array
 */
int* makeSet(int n)
{
  int i;
  int *conj = (int*) malloc(sizeof(int) * n);

  for(i = 0;i < n;i += 1)
    conj[i] = (i + 1);

  return conj;
}

/**
 * Prints an array of integers.
 *
 * int *vec - the array
 * int tam - the size of the array
 */
void printVec(int *vec, int size)
{
  int i = 0;

  for(; i < size; i += 1)
    printf("%d ", vec[i]);

  printf("\n");
}

/**
 * Apply a binary mask over and integer array and prints it.
 *
 * int *set - the integer array
 * int setSize - the size of the set
 * int maskVal - the value of the number of the binary mask
 */
void applyMask(int *set, int setSize, int maskVal)
{
  int i;
  char *mask = getBinaryStringInverted(maskVal, 32);
  
  printf("{ ");    
  
  for(i = 0; i < setSize; i += 1)
    if(mask[i] == '1')
      printf("%d ", set[i]);
  
  printf("}\n");    
}

/**
 * Calculates n^e
 */
int powa(int n, int e)
{
  int i = 0;
  int saida = 1;

  for(;i < e; i += 1)
    saida = saida * n;

  return saida;
}

int main (int argc, char *argv[])
{
  int i;
  int sSize = 6;
  int *conj = makeSet(sSize);

  for(i = 0; i < powa(2, sSize); i += 1)
    applyMask(conj, sSize, i);

  return 1;
}

