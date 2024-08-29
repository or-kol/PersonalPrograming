#include <assert.h>

#include "fsa.h"

#define WORD_SIZE 8

struct fsa
{
	size_t next_free;
};


size_t FSAMinPoolSize(size_t size_of_block, size_t num_of_blocks)
{
	size_t size = size_of_block * num_of_blocks;
	
	if (size < WORD_SIZE)
	{
		size = WORD_SIZE;
	}
	
	if (0 != size % WORD_SIZE)
	{
		size = size + (WORD_SIZE - (size % WORD_SIZE));
	}
	
	return size * num_of_blocks;
}


fsa_t *FSAInit(void * memory_block, size_t size_of_block, size_t num_of_blocks)
{
	size_t i = 0, size = size_of_block * num_of_blocks;
		
	size_t *init = (size_t *)memory_block + 1;
	
	assert(0 != num_of_blocks);
	
	
	
	if(size < WORD_SIZE)
	{
		size_of_block = WORD_SIZE;
	}
	
	if (0 != size % WORD_SIZE)
	{
		size = size + (WORD_SIZE - (size % WORD_SIZE));
	}
	
	((fsa_t *)memory_block)->next_free = WORD_SIZE;
	
	for (; i < num_of_blocks - 1; i++)
	{
		*init = (i + 1) * size_of_block + WORD_SIZE;
		init = (size_t *)(((char *)init) + size_of_block);	
	}
	*init = 0;
	
	return (fsa_t *)memory_block;	 
}


void *FSAAllocateBlock(fsa_t *fsa)
{
	char *ptr = NULL;
	
	if (0 == fsa->next_free)
	{
		return NULL;
	}
	
	ptr = ((char *)fsa + (fsa->next_free));
	
	fsa->next_free = *((size_t *)ptr);
	
	return (void *)ptr;
}


void FSAFreeBlock(fsa_t *fsa, void *to_free)
{
	size_t *temp = to_free;
	
	*temp = fsa->next_free;
	
	fsa->next_free = ((size_t)fsa ^ (size_t)to_free);
}


size_t FSACountNumOfFreeBlocks(const fsa_t *fsa)
{
	size_t count = 0;
	
	size_t runner = fsa->next_free;

	while(0 != runner)
	{
		runner = *(size_t *)(((char *)fsa) +runner);
		++count;
	}
	
	return count;
}


