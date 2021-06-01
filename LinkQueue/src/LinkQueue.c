#include "include\LinkQueue.h"

Status InitLinkQueue( LinkQueue *Q )
{
    Q->front = (QueuePtr)malloc(sizeof(QNode));
    Q->rear = Q->front;
    if( Q->front == NULL )
        exit(EXIT_FAILURE);
    Q->front->next = Q->rear->next = NULL;
    return OK;
}

Status DestroyLinkQueue( LinkQueue *Q )
{
    while( Q->front != NULL )
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status ClearLinkQueue( LinkQueue *Q )
{
    QueuePtr p, q = NULL;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while( p != NULL )
    {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

bool LinkQueueEmpty( LinkQueue Q )
{
    return ( Q.front == Q.rear );
}

Status GetHead( LinkQueue Q, QElemType *elem )
{
    QueuePtr p;
    if( LinkQueueEmpty(Q) )
        return ERROR;
    
    p = Q.front->next;
    *elem = p->elem;
    return OK;
}

Status EnQueue( LinkQueue *Q, QElemType elem )
{
    QueuePtr s;
    s = (QueuePtr)malloc(sizeof(QNode));
    if( s == NULL )
        exit(EXIT_FAILURE);

    s->elem = elem;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}

Status DeQueue( LinkQueue *Q, QElemType *elem )
{
    QueuePtr s;
    if( LinkQueueEmpty(*Q) )
        return ERROR;

    s = Q->front->next;
    *elem = s->elem;
    Q->front->next = s->next;

    if( Q->rear == s )
        Q->rear = Q->front;
    free(s);
    return OK;
}

int QueueLength( LinkQueue Q )
{
    QueuePtr p;
    int i = 0;
    p = Q.front;

    while(p != Q.rear)
    {
        i++;
        p = p->next;
    }

    return i;
}

void PrintQueue( LinkQueue Q )
{
    QueuePtr p;
    p = Q.front->next;

    while( p != Q.rear->next )
    {
        printf( "%d ", p->elem );
        p = p->next;
    }
    printf("\n");
}