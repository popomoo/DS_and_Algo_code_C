#include "include\Queue.h"

int main()
{
	Status j;
	int i=0,l;
	QElemType d;
	SqQueue Q;

	j = InitQueue(&Q);
    if( j == ERROR )
    {
        exit(EXIT_FAILURE);
    }
	printf("Is the Queue empty after the initial of the Queue? %u (1:Empty 0: No)\n", QueueEmpty(Q));

	do
	{
		d = i + 100;
		i++;
		EnQueue(&Q, d);
	}while(i < MAXSIZE - 1 );

	printf("The length of the Queue is %d\n", QueueLength(Q));
	printf("Is the Queue empty or not? %u (1:Empty 0:No)\n", QueueEmpty(Q));
	printf("Delete by %d cycles the element from the Queue, insert the elements from the tail of the Queue :\n", MAXSIZE);
	for( l = 1; l <= MAXSIZE; l++ )
	{
		DeQueue(&Q, &d);
		printf("The deleted element is %d, the element inserted is : %d \n",d, l + 1000);

		d = l + 1000;
		EnQueue(&Q, d);
	}

	l = QueueLength(Q);

	printf("The elements in the Queue now are : \n");
	PrintQueue(Q);

	printf("Totally inserted %d elements into the queue.\n", i + MAXSIZE);
	if( l - 2 > 0 )
		printf("Deleted %d elements from the head of the Queue.\n", l - 2);
	
    while(QueueLength(Q)>2)
	{
		DeQueue(&Q, &d);
		printf("The value of the element deleted is %d\n",d);
	}

	j = GetHead(Q,&d);
	if( j == OK )
		printf("The head of the Queue now is : %d\n", d);


	ClearQueue( &Q );
	printf("After clearing the queue, is the queue empty or not? %u(1:Empty 0:No)\n", QueueEmpty(Q));

    system("PAUSE");
	return 0;
}