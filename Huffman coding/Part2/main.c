#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "helper.h"

int main(int argc, char ** argv)
{
  if(argc < 2)//check if the input file name has been given or not
  {
    printf("Input filename is missing.\n");//if not, print the error message to the user
    return EXIT_FAILURE;//return the EXIT_FAILURE constant
  }
  
  FILE * inputfile = fopen(argv[1], "r");
  if(inputfile == NULL)//if the input file pointer is NULL, it means the input file cannot be opened correctly.
  {
    printf("Input file cannot be opened, or it's not correct.\n");//print the error message to the user
    return EXIT_FAILURE;
  }
 
  HuffNode * huff_tree = readInput(inputfile);//call the readInput function to get the Huffman tree based on the input command in the input file
  if(huff_tree == NULL)//if the huff_tree pointer is NULL, it means the input file is not correct.
  {
    printf("Input file is not correct.\n");//print the error message to the user
    return EXIT_FAILURE;
  }
  if(loadtree(inputfile, argv[2], huff_tree) == EXIT_FAILURE)
  {
    printf("The input cannot be decoded correctly");//Check if the input huffman decoded seires are correct or not
    return EXIT_FAILURE;
  }
  
  fclose(inputfile);//close the input file
  destroyTree(huff_tree);//deallocate the memory for the huffman tree
  return EXIT_SUCCESS;
}
