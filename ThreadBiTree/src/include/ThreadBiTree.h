#ifndef THREAD_BITREE_H
#define THREAD_BITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define MAXSIZE 100

/************************************/
typedef char String[24]; /*  0号单元存放串的长度 */
String str;

void StrAssign(String T,char *chars);
/************************************/

typedef char TElemType;
typedef enum PointerTag{Link, Thread}PointerTag;
typedef enum Status{ OK, ERROR }Status;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag RTag;
    PointerTag LTag;
}BiThrNode, *ThrBiTree;

void CreateBiThrTree( ThrBiTree *T );
void DestroyBiThrTree( ThrBiTree *T );
void InThreading( ThrBiTree p );
Status InOrderThreading( ThrBiTree *Thrt, ThrBiTree T );
Status InOrderTraverse_Thr( ThrBiTree T );

#endif