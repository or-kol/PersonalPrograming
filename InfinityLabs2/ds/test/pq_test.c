#include <string.h>
#include <stdio.h>

#include "pq.h"

struct pq_val
{
	void *data;
	int priority;
};

typedef struct pq_val pq_val_t;

int CompareFunc(const void *data, const void *param)
{
	if (((pq_val_t *)(data))->priority <= ((pq_val_t *)(param))->priority)
	{
		return -1;
	}
	
	return 0;
}


int IsMatch(const void *data, const void *param)
{
	return (pq_val_t *)data == ((pq_val_t *)param);
}


int main()
{
	pq_t *pq1 = PQCreate(CompareFunc);
	
	int q = 1, w = 2, e = 3, r = 4;
	pq_val_t pq_val1, pq_val2, pq_val3, pq_val4;
	pq_val_t pq_res1, pq_res2, pq_res3, pq_res4;
	pq_val_t pq_pop1, pq_pop2;
	
	pq_val1.data = &q;
	pq_val1.priority = 2;
	
	pq_val2.data = &w;
	pq_val2.priority = 1;
	
	pq_val3.data = &e;
	pq_val3.priority = 3;
	
	pq_val4.data = &r;
	pq_val4.priority = 3;
	
	
	if (1 == PQIsEmpty(pq1))
	{
		printf("Is Empty <empty> Success\n");
	}
	
	
	PQEnqueue(&pq_val1, pq1);
	pq_res1 = *(pq_val_t *)PQPeek(pq1);
	
	PQEnqueue(&pq_val2, pq1);
	pq_res2 = *(pq_val_t *)PQPeek(pq1);
	
	PQEnqueue(&pq_val3, pq1);
	pq_res3 = *(pq_val_t *)PQPeek(pq1);
	
	if (w == *(int *)pq_res3.data)
	{
		printf("Create Success\n");
		printf("Insert Success\n");
		printf("Peek Success\n");
	}
	
	PQEnqueue(&pq_val4, pq1);
	pq_res4 = *(pq_val_t *)PQPeek(pq1);
	
	
	pq_pop1 = *(pq_val_t *)PQDequeue(pq1);
	pq_pop2 = *(pq_val_t *)PQDequeue(pq1);
	pq_res4 = *(pq_val_t *)PQPeek(pq1);
	if (e == *(int *)pq_res4.data)
	{
		printf("Pop Success\n");
	}
	
	
	if (0 == PQIsEmpty(pq1))
	{
		printf("Is Empty <not empty> Success\n");
	}
	
	
	if (2 == PQSize(pq1))
	{
		printf("Size Success\n");
	}
	
	
	PQErase(pq1, IsMatch, pq_val3.data);
	
	pq_res4 = *(pq_val_t *)PQPeek(pq1);
	if (e == *(int *)pq_res4.data)
	{
		printf("Erase Positivetive Test Success\n");
	}
	
	if (1 == PQErase(pq1, IsMatch, &q))
	{
		printf("Erase Negative Test Success\n");
	}
	
	PQClear(pq1);
	
	if (0 == PQSize(pq1))
	{
		printf("Clear Success\n");
	}
	
	
	PQDestroy(pq1);
	
	return 0;
}



























