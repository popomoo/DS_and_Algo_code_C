#include "include\LinkBiTree.h"

static int  Index = 1;

Status InitBiTree( BiTree *T )
{
    *T = NULL;
    return OK;
}

void DestroyBiTree( BiTree *T )
{
    if(*T)
    {
        if( (*T)->lchild != NULL )
            DestroyBiTree( &((*T)->lchild) );
        if( (*T)->rchild != NULL )
            DestroyBiTree( &((*T)->rchild) );
        free(*T);
        *T = NULL;
    }
}

bool StrAssign( String T, char *chars )
{
    int i;
    if( strlen(chars) > MAXSIZE )
        return 1;
    else
    {
        T[0] = strlen(chars);
        for( i = 1; i <= T[0]; i++ )
            T[i] = *(chars + i - 1);
        return 0;
    }
}

void CreateBiTree( BiTree *T )
{
    TElemType ch;

    ch = str[Index++];

    if( ch == '#' )
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if( !*T )
            exit(EXIT_FAILURE);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

bool BiTreeEmpty( BiTree T )
{
    return ( T == NULL );
}

int BiTreeDepth( BiTree T )
{
    int i = 0;
    int j = 0;
    if( T == NULL )
        return 0;

    if( T->lchild )
        i = BiTreeDepth( T->lchild );
    else
        i = 0;

    if( T->rchild )
        j = BiTreeDepth( T->rchild );
    else
        j = 0;

    return ( ( i > j ) ? (i + 1) : j + 1 );
}

Status Root( BiTree T, TElemType *e )
{
    if( BiTreeEmpty(T) )
        return ERROR;

    *e = T->data;

    return OK;
}

TElemType Value( BiTree p )
{
    return p->data;
}

void Assign( BiTree p, TElemType value )
{
    p->data = value;
}

void PreOrderTraverse( BiTree T )
{
    if( T == NULL )
        return;
    printf( "%c ", T->data );
    PreOrderTraverse( T->lchild );
    PreOrderTraverse( T->rchild );
}

void InOrderTraverse( BiTree T )
{
    if( T == NULL )
        return;
    InOrderTraverse( T->lchild );
    printf( "%c ", T->data );
    InOrderTraverse( T->rchild );
}

void PostOrderTraverse( BiTree T )
{
    if( T == NULL )
        return;
    PostOrderTraverse( T->lchild );
    PostOrderTraverse( T->rchild );
    printf( "%c ", T->data );
}

