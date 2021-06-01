#include "include\ThreadBiTree.h"

int Index = 1;

void StrAssign( String T, char *chars )
{ 
	int i;
	T[0] = (char)strlen(chars);
    for(i = 1; i <= (int)T[0]; i++ )
		T[i] = *(chars+i-1);

    printf("%d", T[0]);
    for( i = 1; i <= (int)T[0]; i++ )
        printf("%c", T[i] );

    printf("\n");
}

void CreateBiThrTree( ThrBiTree *T )
{
    TElemType h;
    
    h = str[Index++];

    if( h == '#' )
        *T = NULL;
    else
    {
        *T = (ThrBiTree)malloc(sizeof(BiThrNode));
        if( (*T) == NULL )
            exit( EXIT_FAILURE );
        (*T)->data = h;
        CreateBiThrTree(&((*T)->lchild));
        if( (*T)->lchild != NULL )
            (*T)->LTag = Link;
        CreateBiThrTree(&((*T)->rchild));
        if( (*T)->rchild != NULL )
            (*T)->RTag = Link;
    }
}

void DestroyBiThrTree( ThrBiTree *T )
{
    if( *T != NULL)
    {
        if( (*T)->LTag == Link && (*T)->lchild != NULL )
            DestroyBiThrTree(&((*T)->lchild));
        if( (*T)->RTag == Link && (*T)->rchild != NULL )
            DestroyBiThrTree(&((*T)->rchild));
        free(*T);
        *T = NULL;
    }
}

ThrBiTree pre = NULL;

void InThreading( ThrBiTree p )
{
    if( p != NULL )
    {
        InThreading( p->lchild );
        if( p->lchild == NULL )
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if( pre->rchild == NULL )
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

Status InOrderThreading( ThrBiTree *Thrt, ThrBiTree T )
{
    *Thrt = (ThrBiTree)malloc(sizeof(BiThrNode));
    if( *Thrt == NULL )
        exit( EXIT_FAILURE );
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);
    if( T == NULL )
        (*Thrt)->lchild = (*Thrt);
    else
    {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T);
        pre->rchild = (*Thrt);
        pre->RTag = Thread;
        (*Thrt)->rchild = pre;
    }
    return OK;
}

Status InOrderTraverse_Thr( ThrBiTree T )
{
    ThrBiTree p;
    p = T->lchild;
    while( p != T )
    {
        while( p->LTag == Link )
            p = p->lchild;
        printf( "%c ", p->data );
        while( p->RTag == Thread && p->rchild != T )
        {
            p = p->rchild;
            printf("%c ", p->data );
        }
        p = p->rchild;
    }
    return OK;
}