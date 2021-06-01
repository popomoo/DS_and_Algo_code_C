#include "include\BTree.h"

int Search( BTree p, int K )
{
    int i = 0;
    int j;

    for( j = 1; j <= p->keynum; j++ )
        if( p->node[j].key <= K )
            i = j;
    
    return i;
}

Result SearchBTree( BTree T, int K )
{
    BTree p = T, q = NULL;
    Status found = FALSE;
    int i = 0;
    Result r;

    while( p && found == FALSE )
    {
        i = Search(p, K);
        if( i > 0 && p->node[i].key == K )
            found = TRUE;
        else
        {
            q = p;
            p = p->node[i].ptr;
        }
    }

    r.i = i;

    if( found == TRUE )
    {
        r.pt = p;
        r.tag = 1;
    }
    else
    {
        r.pt = q;
        r.tag = 0;
    }

    return r;
}

void Insert( BTree *q, int i, int key, BTree ap )
{
    int j;

    for( j = (*q)->keynum; j > i; j-- )
        (*q)->node[j+1] = (*q)->node[j];

    (*q)->node[i+1].key = key;
    (*q)->node[i+1].ptr = ap;
    (*q)->node[i+1].recptr = key;
    (*q)->keynum++;
}

void split( BTree *q, BTree *ap )
{
    int i;
    int s = (m+1)/2;

    *ap = (BTree)malloc( sizeof(BTNode) );
    (*ap)->node[0].ptr = (*q)->node[s].ptr;

    for( i = s+1; i <= m; i++ )
    {
        (*ap)->node[i-s] = (*q)->node[i];
        if((*ap)->node[i-s].ptr)
            (*ap)->node[i-s].ptr->parent = *ap;
    }

    (*ap)->keynum = m - s;
    (*q)->keynum = s - 1;
    (*ap)->parent = (*q)->parent;
}

void NewRoot( BTree *T, int key, BTree ap )
{
    BTree p;
    p = (BTree)malloc(sizeof(BTNode));
    p->node[0].ptr = *T;

    *T = p;

    if( (*T)->node[0].ptr != NULL )
        (*T)->node[0].ptr->parent = *T;
    
    (*T)->parent = NULL;
    (*T)->keynum = 1;
    (*T)->node[1].key = key;
    (*T)->node[1].recptr = key;
    (*T)->node[1].ptr = ap;

    if( (*T)->node[1].ptr )
        (*T)->node[1].ptr->parent = *T;
}

void InsertBTree( BTree *T, int key, BTree q, int i )
{
    BTree ap = NULL;
    Status finished = FALSE;
    int s;
    int rx;
    rx = key;

    while( q && !finished )
    {
        Insert( &q, i, rx, ap );
        if( q->keynum < m )
            finished = TRUE;
        else
        {
            s = (m + 1)/2;
            rx = q->node[s].recptr;
            split( &q, &ap );
            q = q->parent;

            if( q != NULL )
                i = Search( q, key );
        }
    }
    if( finished == FALSE )
        NewRoot( T, rx, ap );
}

void print( BTNode c, int i )
{
    printf("(%d)", c.node[i].key );
}