#include "include\DoubleStack.h"

Status InitDoubleStack( DoubleStack *S )
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status ClearDoubleStack( DoubleStack *S )
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

bool DoubleStackEmpty( DoubleStack S, int stackNumber )
{
    if( stackNumber == 1)
        return (S.top1 == -1 );
    else if( stackNumber == 2 )
        return (S.top2 == MAXSIZE);
    
    return -1;
}

Status Push( DoubleStack *S, SElemType elem, int stackNumber )
{
    if( S->top1 + 1 == S->top2 )
        return ERROR;

    if( stackNumber == 1 )
        S->elem[++S->top1] = elem;
    else if( stackNumber == 2 )
        S->elem[--S->top2] = elem;
    else
        return ERROR;

    return OK;
}

Status Pop( DoubleStack *S, SElemType *elem, int stackNumber )
{
    if( stackNumber == 1 )
    {
        if( S->top1 == -1 )
            return ERROR;
        *elem = S->elem[S->top1--];
    }
    else if( stackNumber == 2 )
    {
        if( S->top2 == MAXSIZE )
            return ERROR;
        *elem = S->elem[S->top2++];
    }
    else    
        return ERROR;

    return OK;
}

int DoubleStackLength( DoubleStack S, int stackNumber )
{
    if( stackNumber != 1 && stackNumber != 2 )
        exit( EXIT_FAILURE );
    return ((stackNumber == 1) ? ( S.top1 + 1 ) : ( MAXSIZE - S.top2 ));
}

void PrintStack( DoubleStack S )
{
    int i, j;
    printf( " Stack1 : \n");
    for( i = 0; i <= S.top1; i++ )
    {
        printf("%d ", S.elem[i] );
        if( i != 0 && i%10 == 0 )
            printf("\n");
    }
    printf( "\n" );
    printf( " Stack2 : \n");
    for( j = MAXSIZE-1; j >= S.top2; j-- )
    {
        printf("%d ", S.elem[j] );
        if( j != 0 && j%10 == 0 )
            printf("\n");
    }
    printf( "\n" );
}