#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bool int
#define ElemType int

typedef enum Status{
    OK, ERROR
}Status;

typedef struct Node{
    ElemType elem;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

Status InitList( LinkList *L );
bool ListEmpty( LinkList L );
Status ClearList( LinkList *L );
Status GetElem( LinkList L, int pos, ElemType *elem );
Status ElemLocate( LinkList L, int elem, int *pos );
Status ListInsert( LinkList *L, int pos, int elem );
Status ListDelete( LinkList *L, int pos, ElemType *elem );
int ListLength( LinkList L );
void ListPrint( LinkList L );

void CreateListHead( LinkList *L, int n );
void CreateListTail( LinkList *L, int n );


#endif