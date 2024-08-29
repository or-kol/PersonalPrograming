/****************************************************
* FILE NAME : dll.c
*
* PURPOSE : Functions doubly linked list.
*
* MAINTAINER: Or Kol
*
* Reviewer: Noam
*
* LAST UPDATED : 17/07/2024
****************************************************/

#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */

#include "dll.h"

struct node
{
	void *data;
	node_t *next;
	node_t *prev;
};

struct dll
{
	node_t *head;
	node_t *tail;
};



dll_t *DLLCreate(void)
{
	node_t *dummy_head = NULL;
	node_t *dummy_tail = NULL;
	
	dll_t *create_dll = (dll_t *)malloc(sizeof(dll_t));
	if (NULL == create_dll)
	{
		return NULL;
	}
	
	dummy_head = (node_t *)malloc(sizeof(node_t));
	if (NULL == dummy_head)
	{
		return NULL;
	}
	
	dummy_tail = (node_t *)malloc(sizeof(node_t));
	if (NULL == dummy_tail)
	{
		return NULL;
	}
	
	dummy_head->data = NULL;
	dummy_head->next = dummy_tail;
	dummy_head->prev = NULL;
	
	dummy_tail->data = NULL;
	dummy_tail->next = NULL;
	dummy_tail->prev = dummy_head;
	
	create_dll->tail = dummy_tail;
	create_dll->head = dummy_head;
	
	return create_dll;
}

void DLLDestroy(dll_t *dll)
{
	node_t *curr_node = dll->head;
	node_t *runner = curr_node->next;
	
	assert(NULL != dll);
	
	free(curr_node);
	curr_node = runner;
	while (NULL != curr_node)
	{
		runner = curr_node->next;
		free(curr_node);
		curr_node = runner;
	}
	
	free(dll);
}

dll_iterator_t DLLInsert(dll_iterator_t iter, const void *data, dll_t *dll)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	if (NULL == new_node)
	{
		return DLLEnd(dll);
	}
	
	if (iter == dll->head)
	{
		DLLNext(iter);
	}
	
	assert(NULL != iter);
	assert(NULL != data);
	
	new_node->data = (void *)data;
	new_node->next = iter;
	new_node->prev = iter->prev;
	
	iter->prev->next = new_node;
	iter->prev = new_node;
	
	return new_node;
}


void DLLSetData(dll_iterator_t iter, const void *data)
{
	assert(NULL != iter);
	assert(NULL != data);
	
	iter->data = (void *)data;
}


void *DLLGetData(const dll_iterator_t iter)
{
	assert(NULL != iter);
	
	return iter->data;
}


dll_iterator_t DLLFind(dll_iterator_t from, const dll_iterator_t to, is_match_t is_match, void *param)
{
	dll_iterator_t iter = from;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	
	while (iter != to)
	{
		if (1 == is_match(iter->data, param))
		{ 
			return iter;
		}
		
		iter = DLLNext(iter);
	}
	
	return DLLPrev(iter);
}


size_t DLLSize(const dll_t *dll)
{
	size_t counter = 0;
	dll_iterator_t iter = DLLBegin(dll);
	
	assert(NULL != dll);
	
	while (iter != dll->tail)
	{
		iter = DLLNext(iter);
		++counter;
	}
	
	return counter;
}

int DLLIsEmpty(const dll_t *dll)
{
	assert(NULL != dll);
	
	return (DLLNext(dll->head) == dll->tail);
}


dll_iterator_t DLLPrev(dll_iterator_t iter)
{
	assert(NULL != iter);
	
	return (dll_iterator_t)iter->prev;
}


dll_iterator_t DLLBegin(const dll_t *dll)
{
	assert(NULL != dll);
	
	return (dll_iterator_t)(dll->head->next);
}


dll_iterator_t DLLEnd(const dll_t *dll)
{
	assert(NULL != dll);
	
	return (dll_iterator_t)dll->tail;
}


dll_iterator_t DLLNext(dll_iterator_t iter)
{
	assert(NULL != iter);
	
	return (dll_iterator_t)iter->next;
}


dll_iterator_t DLLRemove(dll_iterator_t iter, dll_t *dll)
{
	node_t *node = iter;
	node_t *next_node = iter->next;
	assert(NULL != dll);
	assert(NULL != iter);
	
	if (iter == dll->head || iter == dll->tail)
	{
		return iter;
	}
	
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	
	free(node);
	
	node = NULL;
	
	return next_node;

}


int DLLIsEqual(const dll_iterator_t iter1, const dll_iterator_t iter2)
{
	assert(NULL != iter1);
	assert(NULL != iter2);
	
	return (iter1 == iter2);
}


size_t DLLForEach(const dll_iterator_t from, const dll_iterator_t to, action_t action_func, const void *param)
{
	dll_iterator_t iter = from;
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


dll_iterator_t DLLPushFront(dll_t *dll, void *data)
{
	assert(NULL != dll);
	assert(NULL != data);
	return DLLInsert(DLLBegin(dll), data, dll);
}


dll_iterator_t DLLPushBack(dll_t *dll, void *data)
{
	assert(NULL != dll);
	assert(NULL != data);
	return DLLInsert(dll->tail, data, dll);
}

dll_iterator_t DLLPopFront(dll_t *dll)
{
	assert(NULL != dll);
	
	return DLLRemove(DLLBegin(dll), dll);
}

dll_iterator_t DLLPopBack(dll_t *dll)
{
	dll_iterator_t iter = DLLPrev(DLLEnd(dll));
	
	assert(NULL != dll);
	
	return DLLRemove(iter, dll);
}


dll_iterator_t DLLMultiFind(dll_iterator_t from, const dll_iterator_t to, is_match_t is_match, void *param, dll_t *dest)
{
	dll_iterator_t iter = (dll_iterator_t)from;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	assert(NULL != dest);
	
	while (iter != to)
	{
		if (1 == is_match(iter->data, param))
		{ 
			DLLPushBack(dest, param);
		}
		
		iter = DLLNext(iter);
	}
	
	return to;
}


dll_iterator_t DLLSpliced(dll_iterator_t from, const dll_iterator_t to, dll_iterator_t dest)
{
	dll_iterator_t slice_to = DLLPrev(to); 
	if(NULL == from->prev)
	{
		from = from->next;
	} 
	
	dest->prev->next = from;
	
	to->prev = from->prev;
	
	from->prev->next = to;
	from->prev = dest->prev;
	
	dest->prev = slice_to;
	
	slice_to->next = dest;
	
	return from;			
}




