#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define LH 1
#define EH 0
#define RH -1

typedef enum Status{ FALSE, TRUE }Status;

typedef struct BiTNode
{
    int data;
    int bf;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

void R_Rotate( BiTNode **P );
void L_Rotate( BiTNode **P );
void LeftBalance( BiTree *T );
void RightBalance( BiTree *T );

Status InsertAVL( BiTree *T, int e, Status *taller );

#endif