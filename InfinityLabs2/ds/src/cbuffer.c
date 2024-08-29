/****************************************************
* FILE NAME : cbuffer.c
*
* PURPOSE : Functions cbuffer.
*
* MAINTAINER: Or Kol
*
* Reviewer: Tamir
*
* LAST UPDATED : 16/07/2024
****************************************************/
#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */

#include "cbuffer.h"

struct cbuffer
{
	size_t capacity;
	size_t front;
	size_t rear;
	char buffer[1];
};


static int MakeFrontZero(cbuffer_t *cbuffer);
static int IsBufferFull(cbuffer_t *cbuffer);

cbuffer_t *CBufferCreate(size_t capacity)
{
	cbuffer_t *new_cbuff = (cbuffer_t *)malloc(sizeof(cbuffer_t) + (capacity-1));
	
	new_cbuff->capacity = capacity;
	new_cbuff->front = -1;
	new_cbuff->rear = -1;
	
	return new_cbuff;
}


void CBufferDestroy(cbuffer_t *cbuffer)
{
	assert(NULL != cbuffer);
	
	free(cbuffer);
}


ssize_t CBufferWrite(cbuffer_t *cbuffer, size_t n_bytes, const void *src)
{
	size_t i = 0;
	
	assert(cbuffer->capacity >= n_bytes);
	
	if (NULL == src || NULL == cbuffer)
	{
		return i;
	}
	
	for (i = 0; i < n_bytes; ++i)
	{
		++(cbuffer->rear);
		
		if (1 == IsBufferFull(cbuffer))
		{
			return i;
		}
		
		(void)((size_t)-1 == cbuffer->front && MakeFrontZero(cbuffer));
		
		*(cbuffer->buffer + cbuffer->rear) = *((char *)src + i);		
		
		if(cbuffer->rear == cbuffer->capacity)
		{
			cbuffer->rear = 0;
			
			if (1 == IsBufferFull(cbuffer))
			{
				return i;
			}
		}
	}
	
	return i;
}


ssize_t CBufferRead(cbuffer_t *cbuffer, size_t n_bytes, void *dest)
{
	size_t i = 0;
	
	assert(cbuffer->capacity >= n_bytes);
	
	if (NULL == dest || NULL == cbuffer)
	{
		return -1;
	}
	
	*((char *)dest + 0) = *(cbuffer->buffer + cbuffer->front);
	
	for (i = 1; i < n_bytes; ++i)
	{
		++(cbuffer->front);
		*((char *)dest + i) = *(cbuffer->buffer + cbuffer->front);
		
		(void)((!CBufferFreeSpace(cbuffer)) && MakeFrontZero(cbuffer));
	}
	
	if (1 == IsBufferFull(cbuffer))
	{
		cbuffer->rear = -1;
		cbuffer->front = -1;
	}
	
	return i;
}



int CBufferIsEmpty(const cbuffer_t *cbuffer)
{
	assert(NULL != cbuffer);
	
	return (((size_t)-1 == cbuffer->rear) && ((size_t)-1 == cbuffer->front));
}


size_t CBufferBufSize(const cbuffer_t *cbuffer)
{
	assert(NULL != cbuffer);
	
	return cbuffer->capacity;
}


size_t CBufferFreeSpace(const cbuffer_t *cbuffer)
{	
	assert(NULL != cbuffer);
	
	if (cbuffer->rear < cbuffer->front)
	{
		return  cbuffer->front - cbuffer->rear;
	}
	
	return (cbuffer->capacity - (cbuffer->rear - (cbuffer->front -1)));
}



static int MakeFrontZero(cbuffer_t *cbuffer)
{
	cbuffer->front = 0;
	
	return 1;
}

static int IsBufferFull(cbuffer_t *cbuffer)
{
	return cbuffer->rear == cbuffer->front;
}

