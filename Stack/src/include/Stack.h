#ifndef STACK_H
#define STACK_H

#define SElemType int
#define MAXSIZE 20
#define bool int

#include <stdio.h>
#include <stdlib.h>

typedef enum Status{
    OK, ERROR
}Status;

typedef struct Stack{
    SElemType elem[MAXSIZE];
    int top;
}Stack, *Ptr;

typedef Ptr StackPtr;

Status InitStack( StackPtr S );
bool StackEmpty( Stack S );
Status ClearStack( StackPtr S );
Status GetTop( Stack S, SElemType *elem );
Status Push( StackPtr S, SElemType elem );
Status Pop( StackPtr S, SElemType *elem );
Status StackLength( Stack S );

void PrintStack( Stack S );

#endif