#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ElemType int
#define bool int 

typedef enum Status{
    OK, ERROR
}Status;

typedef struct SqList{
    
    ElemType elem[MAXSIZE];
    int length;
}SqList, *Ptr;

typedef Ptr SqListPtr;

Status InitList( SqListPtr L );
bool ListEmpty( SqList L );
Status ClearList( SqListPtr L );
Status GetElem( SqList L, int pos, ElemType *elem );
Status ElemLocate( SqList L, ElemType elem, int *pos );
Status ListInsert( SqListPtr L, int pos, ElemType elem );
Status ListDelete( SqListPtr L, int pos, ElemType *elem );
int ListLength( SqList L );
void ListPrint( SqList L );
#endif