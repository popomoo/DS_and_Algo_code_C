#include "include\SqBiTree.h"

TElemType Nil = 0;

Status InitBiTree( SqBiTree T )
{
    int i;
    for( i = 0; i < MAXSIZE; i++ )
        T[i] = Nil;
    return OK;
}

Status CreateBiTree( SqBiTree T )
{
    int i = 0;
    printf( "Please input the value of the nodes according to the order of the levels, 0 means empty node, intput 999 when finished. Number of nodes : <= %d.", MAXSIZE );

    while( i < 10 )
    {
        T[i] = i + 1;
        if( i != 0 && T[(i+1)/2-1] == Nil && T[i] != Nil )
        // Number of node = (i + 1), node parent = (i + 1)/2, index of parent = parent - 1 = (i + 1)/2 - 1
        {
            printf("A node not root and without the parent present %d,\n", T[i] );
            exit( EXIT_FAILURE );
        }
        i++;
    }
    while( i < MAXSIZE )
    {
        T[i] = Nil;
        i++;
    }

    return OK;
}

Status ClearBiTree( SqBiTree T )
{
    int i;
    for( i = 0; i < MAXSIZE; i++ )
        T[i] = Nil;
    return OK;
}

bool BiTreeEmpty( SqBiTree T )
{
    return (T[0] == Nil);
}

int BiTreeDepth( SqBiTree T )
{
    int i;
    int j = 0;
    for( i = MAXSIZE - 1; i >= 0 && T[i] == Nil; i-- );/* Find the last node */

    while( (i + 1) > powl(2, j) )
        j++;

    return j;
}

Status Root( SqBiTree T, TElemType *r )
{
    if( BiTreeEmpty(T) )
        return ERROR;
    else{
        *r = T[0];
        return OK;
    }
}

TElemType Value( SqBiTree T, Position e )
{
    return T[(int)powl(2, e.level-1) + e.order - 2];
}

Status Assign( SqBiTree T, Position e, TElemType value )
{
    int i = (int)powl(2, e.level - 1) + e.order - 2;
    if( value != Nil && T[(i+1)/2 - 1] == Nil )
        return ERROR;
    else if( value == Nil && (T[i*2+1] != Nil || T[i*2 + 2] != Nil) )
        return ERROR;
    else    
    {
        T[i] = value;
        return OK;
    }
}

TElemType Parent( SqBiTree T, TElemType e )
{
    int i;
    if( T[0] == Nil )
        return Nil;
    
    for( i = 1; i < MAXSIZE; i++ )
        if( T[i] == e )
            return T[(i + 1)/2 - 1];

    return Nil;
}

TElemType LeftChild( SqBiTree T, TElemType e )
{
    int i;
    if( T[0] == Nil )
        return Nil;
    
    for( i = 1; i*2+1 < MAXSIZE; i++ )
        if( T[i] == e )
            return T[i*2+1];

    return Nil;
}

TElemType RightChild( SqBiTree T, TElemType e )
{
    int i;
    if( T[0] == Nil )
        return Nil;

    for( i = 1; i*2 + 2 < MAXSIZE; i++ )
        if( T[i] == e )
            return T[i*2 + 2];
    
    return Nil;
}

TElemType LeftSibling( SqBiTree T, TElemType e )
{
    int i;
    if( T[0] == Nil )
        return Nil;

    for( i = 1; i < MAXSIZE; i++ )
        if( T[i] == e && i%2 == 0 )
            return T[i-1];
    
    return Nil;
}

TElemType RightSibling( SqBiTree T, TElemType e )
{
    int i;
    if( T[0] == Nil )
        return Nil;
    
    for( i = 1; (i + 1) < MAXSIZE; i++ )
        if( T[i] == e && i%2 )
            return T[i+1];

    return Nil;
}

void PreTraverse( SqBiTree T, int e )
{
    printf("%d ", T[e] );
    if( T[2*e + 1] != Nil )
        PreTraverse( T, 2*e + 1 );
    if( T[2*e + 2] != Nil )
        PreTraverse( T, 2*e + 2 );
}

Status PreOrderTraverse( SqBiTree T )
{
    if( !BiTreeEmpty(T) )
    {
        PreTraverse( T, 0 );
    }
    printf("\n");
    return OK;
}

void InTraverse( SqBiTree T, int e )
{
    if( T[2*e + 1] != Nil )
        InTraverse( T, 2*e + 1 );
    printf("%d ", T[e] );
    if( T[2*e + 2] != Nil )
        InTraverse( T, 2*e + 2 );
}

Status InOrderTraverse( SqBiTree T )
{
    if( !BiTreeEmpty(T) )
    {
        InTraverse( T, 0 );
    }
    printf("\n");
    return OK;
}

void PostTraverse( SqBiTree T, int e )
{
    if( T[2*e + 1] != Nil )
        PostTraverse( T, 2*e + 1 );
    if( T[2*e + 2] != Nil )
        PostTraverse( T, 2*e + 2 );
    printf("%d ", T[e] );
}

Status PostOrderTraverse( SqBiTree T )
{
    if( !BiTreeEmpty(T) )
        PostTraverse( T, 0 );
    printf("\n");
    return OK;
}

void LevelOrderTraverse( SqBiTree T )
{
    int i = MAXSIZE - 1;
    int j;

    while( T[i] == Nil )
        i--;
    for( j = 0; j <= i; j++ )
        if( T[j] != Nil )
            printf("%d ", T[j]);
    printf("\n");
}

void Print( SqBiTree T )
{
    int j, k;
    Position p;
    TElemType e;
    for( j = 1; j <= BiTreeDepth(T); j++ )
    {
        printf("The %d level : ", j );
        for( k = 1; k <= powl(2, j - 1); k++ )
        {
            p.level = j;
            p.order = k;
            e = Value( T, p );
            if( e != Nil )
                printf(" %d : %d ", k, e );
        }
        printf("\n");
    }
}