#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
#define bool int
#define ElemType int

typedef enum Status{
    success, fail, fatal, range_error
}Status;

typedef struct Node
{
    ElemType elem;
    struct Node *next;
}Node, *Ptr;

typedef Ptr *SqListPtr;

Status List_Init( SqListPtr L );
void List_Destroy( SqListPtr L );
void List_Clear( SqListPtr L);
bool List_Empty( SqListPtr L );
int List_Size( SqListPtr L );
Status List_Retrival( SqListPtr L, int pos, ElemType *elem );
Status List_Locate( SqListPtr L, ElemType elem, int *pos );
Status List_Insert( SqListPtr L, int pos, ElemType elem );
Status List_delete( SqListPtr L, int pos );
Status List_Find( SqListPtr L, int pos, Ptr *pAddr );
Status List_Prior( SqListPtr L, int pos, ElemType *elem );
Status List_Next( SqListPtr L, int pos, ElemType *elem );

void List_Print( SqListPtr L );
#endif