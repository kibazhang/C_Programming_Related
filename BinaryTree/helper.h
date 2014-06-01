#ifndef _HELPER_H_
#define _HELPER_H_
#include "tree.h"
Tree * node_constructor(Tree*, int);
Tree * find_successor(Tree*);
int preOrder_rec(FILE*, Tree*);
int inOrder_rec(FILE*, Tree*);
int postOrder_rec(FILE*, Tree*);
Tree * readTree_rec(FILE*, Tree*);
Tree * Tree_insert(Tree*, int);
Tree * Tree_delete(Tree*, int);
#endif
