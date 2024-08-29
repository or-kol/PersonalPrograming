/****************************************************
* FILE NAME : sll.c
*
* PURPOSE : Functions singly linked list.
*
* MAINTAINER: Or Kol
*
* Reviewer: Raz
*
* LAST UPDATED : 14/07/2024
****************************************************/

#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */

#include "sll.h"

struct node
{
	void *data;
	node_t *next;
};

struct sll
{
	node_t *head;
	node_t *tail;
};



sll_t *SLLCreate(void)
{
	node_t *dummy = NULL;
	sll_t *create_sll = (sll_t *)malloc(sizeof(sll_t));
	if (NULL == create_sll)
	{
		return NULL;
	}
	
	dummy = (node_t *)malloc(sizeof(node_t));
	if (NULL == dummy)
	{
		return NULL;
	}
	
	dummy->data = create_sll;
	dummy->next = NULL;
	
	create_sll->tail = dummy;
	create_sll->head = dummy;
	
	return create_sll;
}

void SLLDestroy(sll_t *sll)
{
	node_t *curr_node = sll->head;
	node_t *temp = NULL;
	
	assert(NULL != sll);
	
	while (NULL != curr_node)
	{
		temp = curr_node->next;
		free(curr_node);
		curr_node = temp;
	}
	
	free(sll);
}

sll_iterator_t SLLInsert(sll_iterator_t iter, const void *data, sll_t *sll)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	if (NULL == new_node)
	{
		return SLLEnd(sll);
	}
	
	assert(NULL != iter);
	assert(NULL != data);
	assert(NULL != sll);
	
	new_node->data = iter->data;
	new_node->next = iter->next;
	
	iter->data = (void *)data;
	
	if (iter == sll->tail)
	{
		sll->tail = new_node;
	}

	iter->next = new_node;
	
	return iter;
}

void SLLSetData(sll_iterator_t iter, const void *data)
{
	assert(NULL != iter);
	assert(NULL != data);
	
	iter->data = (void *)data;
}


void *SLLGetData(const sll_iterator_t iter)
{
	assert(NULL != iter);
	
	return iter->data;
}


sll_iterator_t SLLFind(const sll_iterator_t from, const sll_iterator_t to, is_match_t is_match, void *param)
{
	sll_iterator_t iter = (sll_iterator_t)from;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	
	while (iter != to)
	{
		if (1 == is_match(iter->data, param))
		{ 
			return iter;
		}
		
		iter = SLLNext(iter);
	}
	
	return NULL;
}


size_t SLLSize(const sll_t *sll)
{
	size_t counter = 0;
	sll_iterator_t iter = SLLBegin(sll);
	
	assert(NULL != sll);
	
	while (iter != sll->tail)
	{
		iter = SLLNext(iter);
		++counter;
	}
	
	return counter;
}

int SLLIsEmpty(const sll_t *sll)
{
	assert(NULL != sll);
	
	return (sll->head == sll->tail);
}

sll_iterator_t SLLRemove(sll_iterator_t iter, sll_t *sll)
{
	node_t *next_node = iter->next;
	
	assert(NULL != sll);
	assert(NULL != iter);
	
	iter->data = (iter->next)->data;
	iter->next = next_node->next;
	
	if(next_node == sll->tail)
	{
		sll->tail = iter;
	}
	
	free(next_node);
	next_node = NULL;
	
	return iter;

}

sll_iterator_t SLLBegin(const sll_t *sll)
{
	assert(NULL != sll);
	
	return (sll_iterator_t)(sll->head);
}


sll_iterator_t SLLEnd(const sll_t *sll)
{
	assert(NULL != sll);
	
	return (sll_iterator_t)sll->tail;
}


sll_iterator_t SLLNext(sll_iterator_t iter)
{
	assert(NULL != iter);
	
	return (sll_iterator_t)iter->next;
}


int SLLIsEqual(const sll_iterator_t iter1, const sll_iterator_t iter2)
{
	assert(NULL != iter1);
	assert(NULL != iter2);
	
	return (iter1 == iter2);
}


size_t SLLForEach(const sll_iterator_t from, const sll_iterator_t to, action_t action_func, const void *param)
{
	sll_iterator_t iter = from;
	size_t failure_counter = 0;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	
	while (iter != to)
	{
		failure_counter = action_func(iter->data, (void *)param);
		iter = iter->next;
	}
	
	return failure_counter;
}


sll_t *SLLAppend(sll_t *sll_src, sll_t *sll_dest)
{
	assert(NULL != sll_src);
	assert(NULL != sll_dest);
	
	sll_dest->tail->next = sll_src->head->next;
	sll_dest->tail->data = sll_src->head->data;
	
	sll_dest->tail = sll_src->tail;
	
	sll_src->head->data = NULL;
	sll_src->head->next = NULL;
	
	sll_src->tail = sll_src->head;
	
	
	return sll_dest;	
}







