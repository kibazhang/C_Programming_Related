
#include <stdio.h>
#include <stdlib.h>
/*
 * Functions on solving integer partition, subset, and permutation problem.
 */
void parti_integer(int, int[]);
void printarray(int[]);
void deleteinarray(int[], int, int);
void addtoarray(int[], int);

void partition(int value)
{
  //local variables
  int array[MAXLENGTH + 1] = {0};//create a new array used to store the partitioned integers

  //executive statements
  printf("partition %d\n", value);
  parti_integer(value, array);//calling the recursive function
}

void parti_integer(int value, int array[])
{
  //local variables
  int lcv;//loop control variable to control the recursive calling times
  int i = 0;//cotrol variable to check every element in the array

  //executive statements
  if(value == 1)//base case
  {
    while(array[i])//reach the end of the array, then add 1 to the array at the end
    {
      i++;
    }
    array[i] = 1;
    printarray(array);//after adding 1, print the array
  }
  else if(value == 0)//when the value = 0, where the remaining value called the partioned value are the same,such as 2 call f(2) in the partition of 4 case, print the array
  {
    printarray(array);
  }
  else//Inductive case
  {
    for(lcv = 1;lcv <= value;lcv++)
    {
      addtoarray(array, lcv);//add the value of loop control variable to the array, it will compensate what have been deleted by using deleteinarray function 
      parti_integer(value - lcv, array);//recursively call itself 
      deleteinarray(array, lcv, value);//delete the last calling form of the partition so that the addtoarray function can add new form of partition permutation into the array, such as (partition of 4)1 1 1 1, delete the last two, and add the new 2, so we get 1 1 2, more like f(2) call f(1) and f(1), and then call f(2)
    }
  }
}

void addtoarray(int array[], int lcv)
{
  //local variable
  int i = 0;//control variable to check every element in the array

  //executive statements
  while(array[i])//add the value of the loop control variable to the end of the array, to get a new partition
  {
    i++;
  }
  array[i] = lcv;
}

void deleteinarray(int array[], int lcv, int value)
{
  //local variable
  int i = 0;//loop control variable to check all the elements in the array

  //executive statements
  if(lcv == value)//if the passing parameter lcv is equal to value, then we don't need to deal with it, because when it returns, there will be another deleteinarray function to deal with it
  {
    return;
  }
  else
  {
    while(array[i])//to get to the last element in the array
    {
      i++;
    }
    if(i - 1 >= 0)//check the possible case when the number of elements in the array is decreasing and reaching to one
    {
      array[i - 1] = 0;
    }
    if(i - 2 >= 0)//check another cases
    {
      array[i - 2] = 0;
    }
  }
}

void printarray(int array[])
{
  //local variable
  int lcv = 0;//loop control control variable to check every elements in the array

  //executive statement
  while(array[lcv])//check where in the array has numbers
  {
    printf("%d ", array[lcv]);//print the number
    lcv++;//keep checking until the end of the array
  }
  printf("\n");//start a new line
}
/*
 * =================================================================
 */
void sub_set(char*, int, int[], int);

void subset(char * charset, int length)
{
  int sequence[length];//the integer array keep tracking which element in the charset should be print out
  int lcv;//loop control variable to check all the elements in the integer array and character array 
  int position_count = 0;//the position count variable to represent which position in the character array needed to be printed out

  for(lcv = 0;lcv < length;lcv++)//initialize the integer array
  {
    sequence[lcv] = 0; 
  } 
  printf("subset of ");
  for(lcv = 0;lcv < length;lcv++)//first print out all the characters in the charset array
  {
    printf("%c ", charset[lcv]);
  }
  sub_set(charset, position_count, sequence, length);//call the recursive function
}

void sub_set(char* charset, int position_count, int sequence[], int length)
{
  int lcv;//loop control variable to check every elements in the array
 
  if(position_count == length)//Base case: if the sequence array has been fully updated then print the array
  {
    for(lcv = 0; lcv < length; lcv++)//print out the elements in the character array which have been selected by the sequence integer array
    {
      if(sequence[lcv])//if the value at the same position in the integer array is one, then we can print this character
      {
        printf("%c ", charset[lcv]);
      }
    }
    printf("\n");
  }
  else//Inductive case: if not,we need to keep updating the sequency array to select which characters in the charset array to print out
  {
    sequence[position_count] = 0;//first case:set the value to zero, so that we don't print the character
    sub_set(charset, position_count + 1, sequence, length);//recursive call to deal with the rest characters in the charset array
    sequence[position_count] = 1;//second case:set the value to one, so that we can print the character
    sub_set(charset, position_count + 1, sequence, length);//recursively call to deal with the rest characters in the charset array
  }
}
/*
 * =================================================================
 */
void permutation(char*, int, int);
void swap(char*, int, int, int);

void printcharset(char* charset, int length)
{
  //local variables
  int lcv;//loop control variable to check all the elements in the array

  //executive statements
  for(lcv = 0; lcv <= length - 1; lcv++)//print all the characters in the character array
  {
    printf("%c ", charset[lcv]);//print the character
  }
  printf("\n");//start a new line
}

void permute(char * charset, int length)
{
  int changing_length = length;//create a new variable to be changed after every recursively calling

  printf("permute ");
  printcharset(charset, length);//first print out the character set needed to be permutated
  permutation(charset, changing_length, length);//call the recursive function
}

void permutation(char* charset, int length, int real_length)
{
  int lcv;//loop control variable to check all the elements in the array

  if(length == 1)//base case: if we reach the point that length equaling to 1 means all the characters in the array have been swapped into the right positions
  {
    printcharset(charset, real_length);//print the character array
  }
  else//Inductive case
  {
    for(lcv = 1; lcv <= length; lcv ++)//for a character array containing n characters, print all the n! possible permutations
    {
      swap(charset, length, lcv, real_length);//first swap the array to get a new permutation
      permutation(charset, length - 1, real_length);//recursively call itself
      swap(charset, length, lcv, real_length);//swap back to get ready for the new swap after
    }
  }
}

void swap(char* charset, int length, int lcv, int real_length)
{
  char temp;//temp value to store the character which need to be swapped
 
  temp = charset[real_length - length];//let the temp value equal to the character that need to be swapped
  charset[real_length - length] = charset[real_length - length + lcv - 1];//swap that character with the character on the right withe lcv - 1 distance, e.g. if lcv = 2, then swap the character with the first character on the right
  charset[real_length - length + lcv - 1] = temp;//finish the swap process
}
