#include "include\SqList.h"

Status InitList( SqListPtr L )
{
    if( L->elem != NULL ){
        L->length = 0;
        return OK;
    }
    else
        return ERROR;
}

bool ListEmpty( SqList L )
{
    return (L.length == 0);
}

Status ClearList( SqListPtr L )
{
    if( L->length != 0 )
        L->length = 0;
    return OK;
}

Status GetElem( SqList L, int pos, ElemType *elem )
{
    if( ListEmpty(L) || pos < 1 || pos > L.length )
        return ERROR;
    *elem = L.elem[pos-1];
    return OK;
}

Status ElemLocate( SqList L, ElemType elem, int *pos )
{
    int i;
    if( !ListEmpty(L) )
    {
        for( i = 0; i < L.length; i++ )
        {
            if( L.elem[i] == elem )
            {
                *pos = i + 1;
                return OK;
            }
        }
    }
    return ERROR;
}

Status ListInsert( SqListPtr L, int pos, ElemType elem )
{
    int i;
    if( L == NULL || L->length + 1 > MAXSIZE )
        return ERROR;
    if( pos < 1 || pos > L->length + 1 )
        return ERROR;

    if( pos <= L->length )
    {
        for( i = L->length; i >= pos; i-- )
            L->elem[i] = L->elem[i-1];
    }

    L->elem[pos-1] = elem;
    L->length++;
    return OK;
}

Status ListDelete( SqListPtr L, int pos, ElemType *elem )
{
    int i;
    if( L == NULL || L->length == 0 )
        return ERROR;
    if( pos < 1 || pos > L->length )
        return ERROR;

    *elem = L->elem[pos-1];

    if( pos < L->length )
    {
        for( i = pos - 1; i < L->length; i++ )
            L->elem[i] = L->elem[i+1];
    }

    L->length--;
    return OK;
}

int ListLength( SqList L )
{
    return L.length;
}

void ListPrint( SqList L )
{
    int i;
    if( L.length <= 0 || L.length > MAXSIZE )
        exit(EXIT_FAILURE);

    for( i = 0; i < L.length; i++ )
    {
        printf( "%d ", L.elem[i] );
        if( i!=0 && i%10 == 0 )
            printf("\n");
    }
    printf("\n");
}

