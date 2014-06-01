#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "helper.h"

Tree * Tree_insert(Tree * root, int val)
{
  //base case: to create a new node with value val
  if(root == NULL){return node_constructor(root, val);}
  //inductive case
  //first case: there already exists the node with value val
  if(val == (root -> value)){return root;}//just return the node
  //second case: no existing node with value val
  if(val < (root -> value)){root -> left = Tree_insert(root -> left, val);}//find all the left children of the node
  else{root -> right = Tree_insert(root -> right, val);}//find all the right children of the node
  return root; 
}

Tree * Tree_delete(Tree * root, int val)
{
  if(root == NULL){return NULL;}
  if(val < root -> value)
  {
    root -> left = Tree_delete(root -> left, val);//search all the left children of the node
    return root;
  }
  if(val > root -> value)
  {
    root -> right = Tree_delete(root -> right, val);//search all the right children of the node
    return root;
  }
  if(root -> left == NULL && root -> right == NULL)//first case: the node has no children
  {
    free(root);//free the node then return NULL
    return NULL;
  }
  if(root -> left == NULL)//second case: the node has no left children
  {
    Tree * left_temp = root -> right;//set a temp node equal to the right child of the node
    free(root);//free the node
    return left_temp;//return the right child of the node
  }
  if(root -> right == NULL)//third case: the node has no right children
  {
    Tree * right_temp = root -> left;//set a temp node equal to the left child of the node
    free(root);//free the node
    return right_temp;//return the left child of the node
  }
  //fifth case: the node has both left and right children
  Tree * successor = find_successor(root -> right);//find the successor of the node
  root -> value = successor -> value;//swap the value of the successor and the node
  successor -> value = val;
  root -> right = Tree_delete(root -> right, val);//then recursive call the function to delete the successor
  return root;
}

Tree * readTree(char * infile)
/*
 * The function opens a file whose name is given by the argument.
 * If fopen fails, this function returns NULL.
 *
 * The input fiLE'S format:
 * Each line contains a command an an integer.
 * c n
 * c is a command, either i (insert) or r (remove)
 * n is an integer
 *
 * If the input file contains an empty line (i.e., does not have a
 * command and an integer), the tree is not changed.
 *
 */
{ 
  FILE * input_file = fopen(infile, "r");//open the input file
  if(input_file == NULL){return NULL;}//check if it can be opened
  Tree * root = NULL;//create the first NULL root
  root = readTree_rec(input_file, root);//call the recursive function to implement without while loop
  fclose(input_file);//close the input file
  return root;
}

int preOrder(char * outfile, Tree * root)
{
  FILE * output_file = fopen(outfile, "w");//first time open the outfile, use 'w' to overwrite the existing files
  if(output_file == NULL){return EXIT_FAILURE;}//if the output file can't be opened, then return EXIT_FAILURE
  if(preOrder_rec(output_file, root) == EXIT_FAILURE){return EXIT_FAILURE;}//if the preOrder returns EXIT_FAILURE, then return EXIT_FAILURE
  fclose(output_file);//close the output file
  return EXIT_SUCCESS;
}

int inOrder(char * outfile, Tree * root)
{
  FILE * output_file = fopen(outfile, "a");//second open the file, just append the output to the end of the file
  if(output_file == NULL){return EXIT_FAILURE;}//check if the output file can or can't be opened
  if(inOrder_rec(output_file, root) == EXIT_FAILURE){return EXIT_FAILURE;}
  fclose(output_file);//close the file
  return EXIT_SUCCESS;
}

int postOrder(char * outfile, Tree * root)
{
  FILE * output_file = fopen(outfile, "a");//append the output to the end of the file
  if(output_file == NULL){return EXIT_FAILURE;}//check if the output file can or can't be opened
  if(postOrder_rec(output_file, root) == EXIT_FAILURE){return EXIT_FAILURE;}
  fclose(output_file);//close the file
  return EXIT_SUCCESS;
}

int writeTree(char * outfile, Tree * root)
/*
 * If the tree is empty, the function creates an empty file
 * and returns EXIT_SUCCESS.
 *
 * The function opens a file whose name is given by the argument.
 *
 * If fopen fails, this function returns EXIT_FAILURE;
 *
 * The function writes the root in three traverse orders:
 * pre-order, in-order, and post-order.  
 *
 * The function closes the file and returns EXIT_SUCCESS.
 *
 */
{
  //if the tree is empty, then just create an empty file
  if(root == NULL)
  {
    FILE * output_file = fopen(outfile, "w");
    if(output_file == NULL){return EXIT_FAILURE;}
    fclose(output_file);
    return EXIT_SUCCESS;
  }
  //if the tree is not empty, then create a file to print the binary tree in the three desired orders
  if(preOrder(outfile, root) == EXIT_FAILURE){return EXIT_FAILURE;}//print the preOrder
  if(inOrder(outfile, root) == EXIT_FAILURE){return EXIT_FAILURE;}//print the inOrder
  if(postOrder(outfile, root) == EXIT_FAILURE){return EXIT_FAILURE;}//print the postOrder
  return EXIT_SUCCESS;
}

/*This function destroy all the memory allocated for the binary tree*/
void destroyTree(Tree * root)
{
  //base case
  if(root == NULL){return;}
  //inductive case to find all the nodes
  destroyTree(root -> left);//find all the left children
  destroyTree(root -> right);//find all the right children
  free(root);//free all the memory
}
