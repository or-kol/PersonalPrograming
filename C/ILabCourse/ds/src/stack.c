#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */
#include <string.h> /* memcmp */


#include "stack.h"

/*Or Kol - revied by Adi*/

struct stack
{
    char *peek;
    size_t size;
    size_t size_of_element;
    size_t capacity;
    stack_t *min_stack; 
};


stack_t *StackCreate(size_t capacity, size_t size_of_element)
{
	stack_t *create_stack = (stack_t *)malloc(sizeof(stack_t));
	if (NULL == create_stack)
	{
		return NULL;
	}
		
	create_stack->peek = (char *)malloc(size_of_element * capacity);
	if (NULL == create_stack->peek)
	{
		return NULL;
	}
	create_stack->size = 0;
	create_stack->capacity = capacity;
	create_stack->size_of_element = size_of_element;
	
	/************************added for min stack************************/
	create_stack->min_stack = (stack_t *)malloc(sizeof(stack_t));
	if (NULL == create_stack->min_stack)
	{
		free(create_stack->peek);
		free(create_stack);
		return NULL;
	}
	
	create_stack->min_stack->peek = (char *)malloc(size_of_element * capacity);
	if (NULL == create_stack->min_stack->peek)
	{
		free(create_stack->peek);
		free(create_stack->min_stack);
		free(create_stack);
		return NULL;
	}
	
	create_stack->min_stack->size = 0;
	create_stack->min_stack->capacity = capacity;
	create_stack->min_stack->size_of_element = size_of_element;
	/*******************************************************************/
	return create_stack;
}




void StackDestroy(stack_t *stack)
{
	if (0 != stack->size)
	{
		free(stack->peek - ((stack->size - 1) * stack->size_of_element));
	}
	else
	{
		free(stack->peek);
	}
	
	/************************added for min stack************************/
	if (stack->min_stack != NULL)
	{
		free(stack->min_stack->peek);
        	free(stack->min_stack);
	}
	/*******************************************************************/
	
	free(stack);
}


void StackPush(const void *val, stack_t *stack)
{
	size_t i = 0, j = 0;
	
	assert(stack->capacity > stack->size);
	
	if (0 != stack->size)
	{
		stack->peek += stack->size_of_element;
	}
	
	for ( ; i < stack->size_of_element; ++i)
	{
		*((char *)stack->peek + i) = *((char *)val + i);
	}
	
	/****************************************************************/
	if (StackIsEmpty(stack->min_stack) || 0 > memcmp(val, StackPeek(stack->min_stack), stack->size_of_element))
	{
		if (0 != stack->min_stack->size)
		{
			stack->min_stack->peek += stack->size_of_element;
		}
		
		for ( ; j < stack->size_of_element; ++j)
		{
			*((char *)stack->min_stack->peek + j) = *((char *)val + j);
		}
		++stack->min_stack->size;
	}
	/****************************************************************/
	
	++stack->size;
}


void StackPop(stack_t *stack)
{
	assert(0 < stack->size);
	
	if (1 < stack->size)
	{
		stack->peek -= stack->size_of_element;
	}
	
	/************************added for min stack************************/
	if (memcmp(StackPeek(stack->min_stack), StackPeek(stack), stack->size_of_element))
	{
		stack->min_stack->peek -= stack->size_of_element;
		--stack->min_stack->size;
	}
	/*******************************************************************/
	
	--stack->size;
}


void *StackPeek(const stack_t *stack)
{
	return stack->peek;
}


int StackIsEmpty(const stack_t *stack)
{
	return (0 == stack->size);
}


size_t StackSize(const stack_t *stack)
{
	return stack->size;
}


size_t StackCapacity(const stack_t *stack)
{
	return stack->capacity;
}


/************************added for min stack************************/
void *StackMin(const stack_t *stack)
{
	return StackPeek(stack->min_stack);
}
/*******************************************************************/


