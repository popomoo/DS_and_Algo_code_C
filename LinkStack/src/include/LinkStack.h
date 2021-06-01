#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define SElemType int
#define bool int

typedef struct StackNode
{
    SElemType elem;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

typedef enum Status{ OK, ERROR }Status;

Status InitStack( LinkStack *S );
Status ClearStack( LinkStack *S );
bool StackEmpty( LinkStack S );
Status GetTop( LinkStack S, SElemType *elem );
Status Push( LinkStack *S, SElemType elem );
Status Pop( LinkStack *S, SElemType *elem );
int StackLength( LinkStack S );

void PrintStack( LinkStack S );

#endif


