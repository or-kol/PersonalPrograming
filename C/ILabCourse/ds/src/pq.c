#include <stdlib.h> /* malloc */
#include <assert.h>


#include "pq.h"


struct pq 
{
	sl_t *list;
};


pq_t *PQCreate(compare_func_t compare_func)
{
	pq_t *create_pq = (pq_t *)malloc(sizeof(pq_t));
	if (NULL == create_pq)
	{
		return NULL;
	}
	
	create_pq->list = SLCreate(compare_func);
	if (NULL == create_pq->list)
	{
		free(create_pq);
		return NULL;
	}
	return create_pq;
}


void PQDestroy(pq_t *pq)
{
	assert(NULL != pq);
	
	SLDestroy(pq->list);
	
	free(pq);
}


int PQEnqueue(const void *data, pq_t *pq)
{
	assert(NULL != pq);
	assert(NULL != data);
	
	if (SLIsEqual(SLInsert(data, pq->list), SLEnd(pq->list)))
	{ 
		return 1;
	}
	
	return 0;
}


void *PQDequeue(pq_t *pq)
{
	assert(NULL != pq);
	
	return SLPopFront(pq->list);
}


int PQIsEmpty(const pq_t *pq)
{
	assert(NULL != pq);
	
	return SLIsEmpty(pq->list);
}


size_t PQSize(const pq_t *pq)
{
	assert(NULL != pq);
	
	return SLSize(pq->list);
}


void *PQPeek(const pq_t *pq)
{
	assert(NULL != pq);
	
	return SLGetData(SLBegin(pq->list));
}


void PQClear(pq_t *pq)
{
	size_t size = PQSize(pq);
	assert(NULL != pq);
	
	while (0 != size)
	{
		PQDequeue(pq);
		--size;
	}
}


void *PQErase(pq_t *pq, is_match_t is_match, void *param)
{
	assert(NULL != pq);
	assert(NULL != param);
	
	return SLGetData(SLRemove(SLFindCustom(SLBegin(pq->list), SLEnd(pq->list), is_match, param), pq->list));
}



