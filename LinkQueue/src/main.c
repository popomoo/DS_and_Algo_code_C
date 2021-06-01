#include "include\LinkQueue.h"

int main()
{
	Status s;
	QElemType d;
	LinkQueue q;

	s = InitLinkQueue( &q );
	if( s == OK )
		printf("Successed for the creation of a Link Queue!\n");
	printf("The Queue is empty or not? %d (1:Empty 0:Not Empty) ", LinkQueueEmpty( q ));
	printf("The length of the Queue is %d.\n", QueueLength( q ));

	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("After inserted 3 elements(-5,5,10), the length of the Queue is %d.\n",QueueLength( q ));
	printf("Is the Queue empty? %d(1: Empty 0: Not Empty) ", LinkQueueEmpty( q ));
	printf("The elements of the Link Queue are : \n");
	PrintQueue( q );

	s = GetHead(q, &d);
	if(s == OK)
	    printf("The head element of the LinkQueue is %d.\n",d);

	DeQueue(&q, &d);
	printf("Deleted the head element %d.\n", d);

	s = GetHead(q, &d);
	if(s == OK)
		printf("The new head element is %d.\n", d);

	ClearLinkQueue( &q );
	printf("After clearing the Queue, q.front = %u q.rear = %u q.front->next = %u\n", q.front, q.rear, q.front->next);

	DestroyLinkQueue(&q);
	printf("After destroying the Queue, q.front = %u q.rear=%u\n", q.front, q.rear);
	
    system("PAUSE");
	return 0;

}