#ifndef BINARY_TREE_SORT_H
#define BINARY_TREE_SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef enum Status{ FALSE, TRUE }Status;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

Status SearchBST( BiTNode *T, int key, BiTNode *f, BiTree *p );
Status InsertBST( BiTree *T, int key );
Status DeleteBST( BiTree *T, int key );
Status Delete( BiTNode *p );

#endif