#ifndef __PQ_H__
#define __PQ_H__

#include "sl.h"

/* type of the priority queue management struct */
typedef struct pq pq_t;


/* PQCreate:
Description - create priority queue management struct.
Params:
	compare_func_t compare_func - priority criteria.
return value - pq_t *
time complexity - O(1)
space complexity - O(1)
*/
pq_t *PQCreate(compare_func_t compare_func);


/* PQDestroy:
Description - delete priority queue.
Params:
	pq_t *pq - management struct.
return value - NONE
time complexity - O(n)
space complexity - O(1)
*/
void PQDestroy(pq_t *pq);


/* PQEnqueue:
Description - insert new value to priority queue.
Params:
	const void *data - data pointer.
	pq_t *pq - management struct.
return value - int - boolean value.
time complexity - O(n)
space complexity - O(1)
*/
int PQEnqueue(const void *data, pq_t *pq);


/* PQDequeue:
Description - Dequeue a value from the priority queue.
Params:
	pq_t *pq - management struct.
return value - void *.
time complexity - O(1)
space complexity - O(1)
*/
void *PQDequeue(pq_t *pq);


/* PQIsEmpty:
Description - is the priority queue empty.
Params:
	const pq_t *pq - management struct.
return value - int - 1 if empty else 0.
time complexity - O(1)
space complexity - O(1)
*/
int PQIsEmpty(const pq_t *pq);


/* PQSize:
Description - return list size.
Params:
	pq_t *pq - management struct.
return value - size_t.
time complexity - O(n)
space complexity - O(1)
*/
size_t PQSize(const pq_t *pq);


/* SLCreate:
Description - returns the value in the head of the queue.
Params:
	pq_t *pq - management struct.
return value - void *
time complexity - O(1)
space complexity - O(1)
*/
void *PQPeek(const pq_t *pq);


/* PQClear:
Description - erase all elements form priority queue.
Params:
	pq_t *pq - management struct.
return value - void *
time complexity - O(n)
space complexity - O(1)
*/
void PQClear(pq_t *pq);


/* PQErase:
Description - erase chosen element form priority queue.
Params:
	pq_t *pq - management struct.
	is_match_t is_match - compare func to find param in priority queue.
	void *param - param to find in priority queue.
return value - int
time complexity - O(n)
space complexity - O(1)
*/
void *PQErase(pq_t *pq, is_match_t is_match, void *param);

#endif





