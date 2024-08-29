/****************************************************
* FILE NAME : dvector.c
*
* PURPOSE : Functions dynamic vector.
*
* MAINTAINER: Or Kol
*
* Reviewer: Adi
*
* LAST UPDATED : 08/07/2024
****************************************************/
#include <stdlib.h> /* malloc */
#include <string.h> /* memcpy */
#include <assert.h> /* assert */

#include "dvector.h"

#define GROWTH_FACTOR (1.5)
#define SHRINK_THERESHOLD (2)

static status_t ReSize(d_vector_t *d_vector, size_t new_capacity);

struct d_vector
{
    void *d_vector_arr;
    size_t size;
    size_t size_of_element;
    size_t capacity;
};


d_vector_t *DVectorCreate(size_t capacity, size_t size_of_element)
{
	d_vector_t *create_d_vector = (d_vector_t *)malloc(sizeof(d_vector_t));
	if (NULL == create_d_vector)
	{
		return NULL;
	}
	
	if (SHRINK_THERESHOLD > capacity)
	{
		capacity = SHRINK_THERESHOLD;
	}
		
	create_d_vector->d_vector_arr = (void *)malloc(size_of_element * capacity);
	if (NULL == create_d_vector->d_vector_arr)
	{
		return NULL;
		free(create_d_vector);
	}
	
	create_d_vector->size = 0;
	create_d_vector->capacity = capacity;
	create_d_vector->size_of_element = size_of_element;
	
	
	
	return create_d_vector;
}


void DVectorDestroy(d_vector_t *d_vector)
{
	assert(NULL != d_vector);
	
	free(d_vector->d_vector_arr);
	free(d_vector);
}


void *DVectorGet(const d_vector_t *d_vector, size_t idx)
{	
	assert(NULL != d_vector);
	assert(idx <= d_vector->size);
	
	return (void *)((char *)d_vector->d_vector_arr + (d_vector->size_of_element * idx));
}


status_t DVectorPushBack(d_vector_t *d_vector, const void *val)
{
	assert(NULL != d_vector);
	assert(NULL != val);
	
	if (d_vector->size == d_vector->capacity)
	{
		if (FAIL_TO_RESIZE == DVectorReserve(d_vector, (d_vector->capacity * GROWTH_FACTOR)))
		{
			return FAIL_TO_RESIZE;
		}
	}
	
	memcpy(DVectorGet(d_vector, d_vector->size), val, d_vector->size_of_element);
	
	++d_vector->size;
	
	return SUCCESS;
}


status_t DVectorPopBack(d_vector_t *d_vector)
{
	--d_vector->size;
	return DVectorShrink(d_vector);
}


size_t DVectorSize(const d_vector_t *d_vector)
{
	return d_vector->size;
}


size_t DVectorCapacity(const d_vector_t *d_vector)
{
	return d_vector->capacity;
}


status_t DVectorShrink(d_vector_t *d_vector)
{
	status_t stauts = SUCCESS;
	
	assert(NULL != d_vector);
	
	if (SHRINK_THERESHOLD <= d_vector->capacity / d_vector->size)
	{
		stauts = ReSize(d_vector, -1);
	}
	
	return stauts;
}


status_t DVectorReserve(d_vector_t *d_vector, size_t new_capacity)
{
	status_t stauts = SUCCESS;
	
	assert(NULL != d_vector);
	
	if (SHRINK_THERESHOLD > new_capacity)
	{
		new_capacity = SHRINK_THERESHOLD;
	}
	
	if (new_capacity >= d_vector->capacity)
	{
		stauts = ReSize(d_vector, new_capacity);
	}
	
	return stauts;
}


static status_t ReSize(d_vector_t *d_vector, size_t new_capacity)
{
	void *temp = NULL;
	size_t reserve = d_vector->size_of_element * new_capacity;
	size_t shrink = 0.5 * (d_vector->capacity - d_vector->size);
	size_t resize = (size_t)-1 == new_capacity ? shrink : reserve;
	
	temp = (void *)realloc(d_vector->d_vector_arr, resize);
	
	if (NULL == temp)
	{
		return FAIL_TO_RESIZE;
	}
	
	d_vector->d_vector_arr = temp;
	
	d_vector->capacity = resize;
	
	return SUCCESS;
}












