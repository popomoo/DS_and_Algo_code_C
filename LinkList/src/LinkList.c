#include "include\LinkList.h"

Status InitList( LinkList *L )
{
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L))
        return ERROR;
    
    (*L)->next = NULL;
    return OK;
}

bool ListEmpty( LinkList L )
{
    return (L->next == NULL);
}

Status ClearList( LinkList *L )
{
    LinkList p, q = NULL;
    p = (*L)->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

Status GetElem( LinkList L, int pos, ElemType *elem )
{
    LinkList p;
    p = L->next;
    int i = 1;
    while( p && i < pos)
    {
        p = p->next;
        i++;
    }

    if( !p || i > pos )
        return ERROR;
    
    *elem = p->elem;
    return OK;
}

Status ElemLocate( LinkList L, ElemType elem, int *pos )
{
    LinkList p;
    p = L->next;
    int i = 1;
    while( p && p->elem != elem )
    {
        p = p->next;
        i++;
    }

    if( !p )
        return ERROR;
    
    *pos = i;
    return OK;
}

Status ListInsert( LinkList *L, int pos, ElemType elem )
{
    LinkList p, q = NULL;
    p = *L;/*在L中第i个位置之前插入元素*/
    int i = 1;
    while( p && i < pos )
    {
        p = p->next;
        i++;
    }

    if( !p || i > pos )
        return ERROR;
    
    q = (LinkList)malloc(sizeof(Node));
    q->elem = elem;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status ListDelete( LinkList *L, int pos, ElemType *elem )
{
    LinkList p, q = NULL;
    p = *L;
    int i = 1;
    while( p && i < pos )
    {
        p = p->next;
        i++;
    }

    if( !p || i > pos )
        return ERROR;

    q = p->next;
    p->next = q->next;
    *elem = q->elem;
    free(q);
    return OK;
}

int ListLength( LinkList L )
{
    LinkList p = L->next;
    int i = 0;
    while( p )
    {
        i++;
        p = p->next;
    }

    return i;
}

void ListPrint( LinkList L )
{
    LinkList p = L->next;
    while( p )
    {
        printf("%d ", p->elem );
        p = p->next;
    }
    printf("\n");
}

void CreateListHead( LinkList *L, int n )
{
    LinkList p = NULL;
    int i = 0;
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L))
        exit(EXIT_FAILURE);
    (*L)->next = NULL;
    srand(time(NULL));
    for( i = 0; i < n; i++ )
    {
        p = (LinkList)malloc(sizeof(Node));
        p->elem = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail( LinkList *L, int n )
{
    LinkList p, r;
    int i = 0;
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    r = *L;
    for( i = 0; i < n; i++ )
    {
        p = (Node *)malloc(sizeof(Node));
        p->elem = rand()%100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}