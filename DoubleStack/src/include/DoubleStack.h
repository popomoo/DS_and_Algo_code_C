#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#define SElemType int
#define MAXSIZE 40
#define bool int

typedef enum Status{ OK, ERROR }Status;
typedef struct
{
    SElemType elem[MAXSIZE];
    int top1;
    int top2;
}DoubleStack;

Status InitDoubleStack( DoubleStack *S );
Status ClearDoubleStack( DoubleStack *S );
bool DoubleStackEmpty( DoubleStack S, int stackNumber );
Status Push( DoubleStack *S, SElemType elem, int stackNumber );
Status Pop( DoubleStack *S, SElemType *elem, int stackNumber );
int DoubleStackLength( DoubleStack S, int stackNumber );

void PrintStack( DoubleStack S );


#endif