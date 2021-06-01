#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define bool int

typedef int QElemType;

typedef enum Status{ OK, ERROR }Status;

typedef struct QNode
{
    QElemType elem;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue
{
    QueuePtr front, rear;
}LinkQueue;

Status InitLinkQueue( LinkQueue *Q );
Status DestroyLinkQueue( LinkQueue *Q );
Status ClearLinkQueue( LinkQueue *Q );
bool LinkQueueEmpty( LinkQueue Q );
Status GetHead( LinkQueue Q, QElemType *elem );
Status EnQueue( LinkQueue *Q, QElemType elem );
Status DeQueue( LinkQueue *Q, QElemType *elem );
int QueueLength( LinkQueue Q );

void PrintQueue( LinkQueue Q );

#endif