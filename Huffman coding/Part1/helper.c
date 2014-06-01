#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"
#define push '1' 
#define pop '0'
/*The defined constants will be used to represent push command and pop command.*/


HuffNode * create_node(int temp)
/* This function is used to create a Huffman node, where its value is based on the temp input, and the left and right children will be initialized to NULL.*/
{
  HuffNode * node = malloc(sizeof(HuffNode));//malloc memory for Huffman node
  node -> value = temp;//assign the value of the Huffman node to the input value
  node -> left = NULL;//initialize both left and right children
  node -> right = NULL;
  return node;
}

HuffNode * stack_node(HuffNode * left, HuffNode * right)
/*This function create a HuffNode with its value to be zero and its left and right children connected to the left and right input Huffman nodes.*/
{
  HuffNode * node = create_node(0);//create a Huffman node with its value to be zero first
  node -> left = left;//assign the left input node to the left child of the node
  node -> right = right;//assign the right input node to the right child of the node
  return node;
}

int stack_count(Stack * stack)
/*This function counts how many Huffman nodes are in the stack list.*/
{
  if(stack == NULL){return 0;}//base case: return 0 since there are no nodes anymore.
  return (1 + stack_count(stack -> next));//return the increasing counting number of the number of nodes in the stack
}

Stack * stack_push(Stack * stack, HuffNode * input_node)
/*This function will push a new HuffNode into the top of the stack*/
{
  Stack * new_stack = malloc(sizeof(Stack));//allocate a piece of memory for the new stack pointer
  new_stack -> node = input_node;//assign the node of the stack to be the input node
  new_stack -> next = stack;//assign the next pointer of the stack to be the previous stack so that we can keep the stack pointer on top of the stack
  return new_stack;
}

Stack * stack_pop(Stack * stack)
/*This function will pop out a node stored on top of the stack pointer, and free the memory allocated the the stack pointer.*/
{
  Stack * temp = stack -> next;//create a temp stack pointer to store the next pointer of the current stack
  free(stack);//free the current stack pointer
  return temp;//return the rest of the stack
}

HuffNode * stack_peek(Stack * stack)
/*This function can return the pointer of the Huffman node in the current stack.*/
{
  if(stack == NULL){return NULL;}//if there are nothing in the stack, then there are nothing to return with.
  HuffNode * temp = stack -> node;//return the node stored on the current stack
  return temp;
}

HuffNode * readInput(char* filename)
/*This function read the input file, and create a Huffman tree based on the command of the input file.*/
{
  FILE * inputfile = fopen(filename, "r");//open the file first
  if(inputfile == NULL){return NULL;}//if the file cannot be opened,return NULL pointer to indicate the user with an error message.

  int temp = fgetc(inputfile);//get the first character of the input file
  Stack * stack = NULL;//create a stack pointer with NULL content
  while(temp != EOF)//if the first character of the input is not end of the file, then we can run the following command.
  {
    if(temp == push)//if the command is push, then run the following.
    {
      temp = fgetc(inputfile);//get the value which needs to be pushed onto the stack
      if(temp == EOF)//if the value is end of the file, then there is something wrong with input file.
      {
        fclose(inputfile);//close the file and return NULL to indicate the user with an error message.
        return NULL;
      }
      HuffNode * temp_node = create_node(temp);//create a temparary Huffman node
      stack = stack_push(stack, temp_node);//push the node into the top of the stack
    }
    else if(temp == pop)//if the command is pop, then run the following
    {
      if(stack_count(stack) == 1){break;}//There must be two nodes on the stack to do the pop command.If not, then just stop and do nothing.
      HuffNode * right = stack_peek(stack);//check the what in the current stack, which contains the right child of the new Huffman node
      stack = stack_pop(stack);//then pop out the current stack
      HuffNode * left = stack_peek(stack);//do the same thing to check the left child of the new Huffman node
      stack = stack_pop(stack);//then pop out the nonused stack
      HuffNode * new_node = stack_node(left, right);//create a new HUffman node, and assign the left and right to the Huffmand node
      stack = stack_push(stack, new_node);//then push the new Huffman node on top of the stack
    }
    temp = fgetc(inputfile);//get the next character with file pointer
  }

  fclose(inputfile);//after reading all the input commands, close the input file
  HuffNode * input_list = stack_peek(stack);//get the node contained in the current stack
  destroyStack(stack);//deallocate the memory used to contain the stack
  return input_list;
}

void destroyTree(HuffNode * tree)
/*This function deallocates the memory allocated by the Huffman tree.*/ 
{
  if(tree == NULL){return;}//base case:reach the leaf of the tree, return to free the leaf
  destroyTree(tree -> left);//check all the left children
  destroyTree(tree -> right);//check all the right children
  free(tree);//free the memory of the tree
}

void destroyStack(Stack * stack)
/*This function deallocates the memory allocated by the stack.*/
{
  if(stack == NULL){return;}//base case: return to free the current stack
  destroyStack(stack -> next);//check all the nodes on the stack
  free(stack);//free the memory
}
