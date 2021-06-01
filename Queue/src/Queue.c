#include "include\Queue.h"

Status InitQueue( SqQueue *Q )
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status ClearQueue( SqQueue *Q )
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

bool QueueEmpty( SqQueue Q )
{
    return ( Q.front == Q.rear );
}

bool QueueFull( SqQueue Q )
{
    return ( (Q.rear + 1)%MAXSIZE == Q.front );
}

Status GetHead( SqQueue Q, QElemType *elem )
{
    if( QueueEmpty(Q) )
        return ERROR;

    Q.front = Q.front%MAXSIZE;
    *elem = Q.elem[Q.front];
    return OK;
}

Status EnQueue( SqQueue *Q, QElemType elem )
{
    if( QueueFull(*Q) )
        return ERROR;
    
    Q->elem[Q->rear] = elem;
    Q->rear = (Q->rear + 1)%MAXSIZE;
    return OK;
}

Status DeQueue( SqQueue *Q, QElemType *elem )
{
    if( QueueEmpty(*Q) )
        return ERROR;

    *elem = Q->elem[Q->front];
    Q->front = (Q->front + 1)%MAXSIZE;

    return OK;
}

int QueueLength( SqQueue Q )
{
    return (( Q.rear - Q.front + MAXSIZE )%MAXSIZE );
}

void PrintQueue( SqQueue Q )
{
    int i = Q.front;
    while( i%MAXSIZE != Q.rear )
    {
        printf( "%d ", Q.elem[i] );
        i++;
    }

    printf("\n");
}
