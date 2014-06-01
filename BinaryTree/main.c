
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "helper.h"
int main(int argc, char ** argv)
{
  /* 
   * This program takes two additional arguments
   * argv[1] is the name of the input file
   * argv[2] is the name of the output file
   */
     
  /* 
   * check whether there are enough arguments. Before using argv[1]
   * and argv[2], the program must check whether argc is large enough.
   * If there are not enough arguments, the program returns
   * EXIT_FAILURE;
   */
  if(argc < 3){return EXIT_FAILURE;}//if there are not enough arguments, the function will return EXIT_FAILURE.

  Tree * root = readTree(argv[1]);
  int rval = writeTree(argv[2], root);
  destroyTree(root);
  return rval;
}
