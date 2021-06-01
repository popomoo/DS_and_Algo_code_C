#include "include\BinaryTreeSort.h"

Status SearchBST( BiTNode *T, int key, BiTNode *f, BiTree *p )
{
    if( T == NULL )
    {
        *p = f;
        return FALSE;
    }
    else if( key == T->data )
    {
        *p = T;
        return TRUE;
    }
    else if( key < T->data )
    {
        return SearchBST(T->lchild, key, T, p);
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);
    }
}

Status InsertBST( BiTree *T, int key )
{
    BiTNode *p, *s;
    if( SearchBST(*T, key, NULL, &p) == FALSE )
    {
        s = (BiTNode*)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;

        if( p == NULL )
            *T = s;
        else if( key < p->data )
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;
    }
    else
        return FALSE;
}

Status DeleteBST( BiTree *T, int key )
{
    if( !*T )
        return FALSE;
    else
    {
        if( key == (*T)->data )
            return Delete(*T);
        else if( key < (*T)->data )
            return DeleteBST( &((*T)->lchild), key );
        else
            return DeleteBST( &((*T)->rchild), key );
    }
}

Status Delete(BiTNode *p)
{
    BiTNode *q, *s;

    if( p->rchild == NULL )
    {
        q = p;
        p = p->lchild;
        free(q);
    }
    else if( p->lchild == NULL )
    {
        q = p;
        p = p->rchild;
        free(q);
    }
    else
    {
        q = p;
        s = p->lchild;
        while( s->rchild )
        {
            q = s;
            s = s->rchild;
        }
        p->data = s->data;

        if( q == p )
            q->lchild = s->lchild;
        else
            q->rchild = s->lchild;
        free(s);
    }
    return TRUE;
}