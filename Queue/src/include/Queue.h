#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#define bool int

#define MAXSIZE 20

typedef int QElemType;

typedef enum Status{ OK, ERROR }Status;

typedef struct Queue
{
    QElemType elem[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitQueue( SqQueue *Q );
Status ClearQueue( SqQueue *Q );
bool QueueEmpty( SqQueue Q );
bool QueueFull( SqQueue Q );
Status GetHead( SqQueue Q, QElemType *elem );
Status EnQueue( SqQueue *Q, QElemType elem );
Status DeQueue( SqQueue *Q, QElemType *elem );
int QueueLength( SqQueue Q );

void PrintQueue( SqQueue Q );

#endif



