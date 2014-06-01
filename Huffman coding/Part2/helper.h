#include "tree.h"
#ifndef HELPER_H
#define HELPER_H

typedef struct stack {
  HuffNode * node;
  struct stack * next;
}Stack;

HuffNode * readInput(FILE*);
int loadtree(FILE*, char*, HuffNode*);
void destroyTree(HuffNode*);
void destroyStack(Stack*);

#endif /* helper.h */
