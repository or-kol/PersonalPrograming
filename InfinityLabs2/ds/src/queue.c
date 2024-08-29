/****************************************************
* FILE NAME : queue.c
*
* PURPOSE : Functions queue.
*
* MAINTAINER: Or Kol
*
* Reviewer: Noam
*
* LAST UPDATED : 14/07/2024
****************************************************/

#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */


#include "queue.h"
#include "sll.h"

struct queue
{
	sll_t *list;
};


queue_t *QueueCreate(void)
{
	queue_t *creat_queue = (queue_t *)malloc(sizeof(queue_t));
	if (NULL == creat_queue)
	{
		return NULL;
	}
	
	creat_queue->list = SLLCreate();
	return creat_queue;
}


void QueueDestroy(queue_t *queue)
{
	assert(NULL != queue);
	SLLDestroy(queue->list);
	free(queue);
}


int Enqueue(queue_t *queue, const void *val)
{
	assert(NULL != queue);
	assert(NULL != val);
	if (NULL == SLLInsert(SLLEnd(queue->list), val, queue->list))
	{
		return 1;
	}
	
	return 0;
}


void Dequeue(queue_t *queue)
{
	assert(NULL != queue);
	SLLRemove(SLLBegin(queue->list), queue->list);
}


void *QueuePeek(const queue_t *queue)
{
	assert(NULL != queue);
	return SLLGetData(SLLBegin(queue->list));
}


int QueueIsEmpty(const queue_t *queue)
{
	assert(NULL != queue);
	return SLLIsEmpty(queue->list);
}


size_t QueueSize(const queue_t *queue)
{
	assert(NULL != queue);
	return SLLSize(queue->list);
}


queue_t *QueueAppend(queue_t *src, queue_t *dest)
{
	assert(NULL != src);
	assert(NULL != dest);
	SLLAppend(src->list, dest->list);
	return dest;
}






