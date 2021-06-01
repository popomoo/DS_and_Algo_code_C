#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

#define m 3
#define N 17
#define MAX 5

typedef enum Status{ FALSE, TRUE }Status;

typedef struct BTNode
{
    int keynum;
    struct BTNode *parent;
    struct Node
    {
        int key;
        struct BTNode *ptr;
        int recptr;
    }node[m+1];
}BTNode, *BTree;

typedef struct 
{
    BTNode *pt;
    int i;
    int tag;
}Result;

int Search( BTree p, int K );
Result SearchBTree( BTree T, int K );
void Insert( BTree *q, int i, int key, BTree ap );
void split( BTree *q, BTree *ap );
void NewRoot( BTree *T, int key, BTree ap );
void InsertBTree( BTree *T, int key, BTree q, int i );
void print( BTNode c, int i );

#endif