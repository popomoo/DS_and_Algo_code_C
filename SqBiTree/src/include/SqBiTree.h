#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 400
#define bool int

typedef int TElemType;
typedef TElemType SqBiTree[MAXSIZE];

typedef struct 
{
    int level, order;
}Position;

typedef enum Status{OK, ERROR}Status;

Status InitBiTree( SqBiTree T );
Status DestroyBiTree( SqBiTree T );
Status CreateBiTree( SqBiTree T );
Status ClearBiTree( SqBiTree T );
bool BiTreeEmpty( SqBiTree T );
int BiTreeDepth( SqBiTree T );
Status Root( SqBiTree T, TElemType *r );
TElemType Value( SqBiTree T, Position e );
Status Assign( SqBiTree T, Position e, TElemType value );
TElemType Parent( SqBiTree T, TElemType e );
TElemType LeftChild( SqBiTree T, TElemType e );
TElemType RightChild( SqBiTree T, TElemType e );
TElemType LeftSibling( SqBiTree T, TElemType e );
TElemType RightSibling( SqBiTree T, TElemType e );

void PreTraverse( SqBiTree T, int e );
void InTraverse( SqBiTree T, int e );
void PostTraverse( SqBiTree T, int e );

Status PreOrderTraverse( SqBiTree T );
Status InOrderTraverse( SqBiTree T );
Status PostOrderTraverse( SqBiTree T );

void LevelOrderTraverse( SqBiTree T );
void Print( SqBiTree T );

#endif