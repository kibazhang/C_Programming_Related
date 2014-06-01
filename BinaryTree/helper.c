#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#define remove 'r'
#define insert 'i'

/*This function will create a node in the binary tree*/
Tree * node_constructor(Tree * root, int val)
{
  Tree * n_node = malloc(sizeof(Tree));//use heap memory to store the binary tree
  n_node -> value = val;
  n_node -> left = NULL;//initial the left and right children
  n_node -> right = NULL;
  return n_node;
}

/*This function will find the successor based on the right child input of the node needed to be deleted*/ 
Tree * find_successor(Tree * root)
{
  if(root -> left == NULL){return root;}//find the successor and thus return it
  return find_successor(root -> left);//recursive call to find the successor
}

/*This functions recursively print the binary tree in preOrder order*/
int preOrder_rec(FILE * output_file, Tree * root)
{
  //base case
  if(root == NULL)
  {
    return EXIT_SUCCESS;
  }
  //recursive case of the preOrder
  fprintf(output_file, "%d\n", root -> value);
  if(preOrder_rec(output_file, root -> left) == EXIT_FAILURE){return EXIT_FAILURE;}
  if(preOrder_rec(output_file, root -> right) == EXIT_FAILURE){return EXIT_FAILURE;}
  return EXIT_SUCCESS;
}

/*This functions recursively print the binary tree in inOrder order*/
int inOrder_rec(FILE * output_file, Tree * root)
{
  //base case
  if(root == NULL)
  {
    return EXIT_SUCCESS;
  }
  //recursive case of the inOrder
  if(inOrder_rec(output_file, root -> left) == EXIT_FAILURE){return EXIT_FAILURE;}
  fprintf(output_file, "%d\n", root -> value);
  if(inOrder_rec(output_file, root -> right) == EXIT_FAILURE){return EXIT_FAILURE;}
  return EXIT_SUCCESS;
}

/*This functions recursively print the binary tree in postOrder order*/
int postOrder_rec(FILE * output_file, Tree * root)
{
  //base case
  if(root == NULL)
  {
    return EXIT_SUCCESS;
  }
  //recursive case of the postOrder
  if(postOrder_rec(output_file, root -> left) == EXIT_FAILURE){return EXIT_FAILURE;}
  if(postOrder_rec(output_file, root -> right) == EXIT_FAILURE){return EXIT_FAILURE;}
  fprintf(output_file, "%d\n", root -> value);
  return EXIT_SUCCESS;
}

/*This functions recursively read all the input information*/
Tree * readTree_rec(FILE * input_file, Tree* root)
{
  char temp_command;
  int temp_value;
  if(fscanf(input_file, "%c %d\n", &temp_command, &temp_value) == 2)//if not 2, the recurisive call ends
  {
    if(temp_command == remove){root = Tree_delete(root, temp_value);}
    if(temp_command == insert){root = Tree_insert(root, temp_value);}
    root = readTree_rec(input_file, root);//recursive call
  }
  return root;
}

