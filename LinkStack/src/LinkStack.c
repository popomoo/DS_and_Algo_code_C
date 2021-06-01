#include "include\LinkStack.h"


Status InitStack( LinkStack *S )
{
    S->count = -1;
    S->top = NULL;
    return OK;
}

Status ClearStack( LinkStack *S )
{
    if( S->count < 0 )
        return ERROR;
        
    LinkStackPtr p, q;
    p = S->top;
    while(p)
    {
        q = p;
        p = p->next;
        free(q);
        S->count--;
    }

    return OK;
}

bool StackEmpty( LinkStack S )
{
    return (S.count == -1);
}

Status GetTop( LinkStack S, SElemType *elem )
{
    if( S.top == NULL)
        return ERROR;

    *elem = (S.top)->elem;
    return OK;
}

Status Push( LinkStack *S, SElemType elem )
{
    LinkStackPtr node;
    node = (LinkStackPtr)malloc(sizeof(StackNode));
    if( !node || !S )
        return ERROR;
    
    node->elem = elem;
    node->next = S->top;
    S->top = node;
    S->count++;
    return OK;
}

Status Pop( LinkStack *S, SElemType *elem )
{
    LinkStackPtr p;

    if( S->count < 0 )
        return ERROR;

    p = S->top;
    *elem = p->elem;

    S->top = p->next;
    free(p);
    S->count--;
    return OK;
    
}

int StackLength( LinkStack S )
{
    return (S.count + 1);
}

void PrintStack( LinkStack S )
{
    LinkStackPtr p;
    p = S.top;
    while(p)
    {
        printf("%d ", p->elem );
        p = p->next;
    }
    printf("\n");
}