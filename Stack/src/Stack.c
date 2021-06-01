#include "include\Stack.h"

Status InitStack( StackPtr S )
{
    S->top = -1;
    return OK;
}

bool StackEmpty( Stack S )
{
    return (S.top == -1);
}

Status ClearStack( StackPtr S )
{
    S->top = -1;
    return OK;
}

Status GetTop( Stack S, SElemType *elem )
{
    *elem = S.elem[S.top];
    return OK;
}

Status Push( StackPtr S, SElemType elem )
{
    if( S->top >= MAXSIZE - 1 )
        return ERROR;

    S->elem[++S->top] = elem;
    return OK;
}

Status Pop( StackPtr S, SElemType *elem )
{
    if( S->top < 0 )
        return ERROR;
    
    *elem = S->elem[S->top--];
    return OK;
}

Status StackLength( Stack S )
{
    return S.top+1;
}

void PrintStack( Stack S )
{
    int i = 0;
    for( i = 0; i <= S.top; i++ )
    {
        printf("%d ", S.elem[i] );
        if( i!=0 && i%10 == 0 )
            printf("\n");
    }
    printf("\n");
}

