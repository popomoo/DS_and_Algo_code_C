#ifndef LINKBITREE_H
#define LINKBITREE_H

#define bool int

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXSIZE  100

/**********************************/
typedef char String[24];
String str;

bool StrAssign( String T, char *chars );

/***********************************/

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

typedef enum Status{ OK, ERROR }Status;

Status InitBiTree( BiTree *T );
void DestroyBiTree( BiTree *T );
void CreateBiTree( BiTree *T );
bool BiTreeEmpty( BiTree T );
int BiTreeDepth( BiTree T );
Status Root( BiTree T , TElemType *e );
TElemType Value( BiTree p );
void Assign( BiTree p, TElemType value );

void PreOrderTraverse( BiTree T );
void InOrderTraverse( BiTree T );
void PostOrderTraverse( BiTree T );

#endif