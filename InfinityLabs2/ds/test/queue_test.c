#include <stdio.h>

#include "queue.h"
#include "sll.h"


int main()
{
	int a = 12, b = 13, c = 2, d = 34, e = 22;
	queue_t *queue1 = QueueCreate();
	queue_t *queue2 = QueueCreate();
	
	if (1 == QueueIsEmpty(queue1))
	{
		printf("Is empty <empty> success\n");
	}
	
	
	if (0 == QueueSize(queue1))
	{
		printf("1st size success\n");
	}
	
	Enqueue(queue1, &a);
	if (12 == *(int *)QueuePeek(queue1))
	{
		printf("Create success\n");
		printf("Enqueue success\n");
		printf("Peek success\n");
	}
	
	if (0 == QueueIsEmpty(queue1))
	{
		printf("Is empty <not empty> success\n");
	}
	
	Enqueue(queue1, &b);
	Enqueue(queue1, &c);
	
	if (3 == QueueSize(queue1))
	{
		printf("2nd size success\n");
	}
	
	Enqueue(queue1, &d);
	Enqueue(queue1, &e);
	
	if (5 == QueueSize(queue1))
	{
		printf("3rd size success\n");
	}
	
	Dequeue(queue1);
	
	if (13 == *(int *)QueuePeek(queue1))
	{
		Dequeue(queue1);
		if (2 == *(int *)QueuePeek(queue1))
		{
			printf("Dequeue success\n");
		}
	}
	
	if (3 == QueueSize(queue1))
	{
		printf("4th size success\n");
	}
	
	
	Enqueue(queue2, &b);
	Enqueue(queue2, &c);
	
	QueueAppend(queue1, queue2);
	
	if (5 == QueueSize(queue2))
	{
		printf("Append success\n");
	}
	
	QueueDestroy(queue1);
	QueueDestroy(queue2);
	
	return 0;
}
