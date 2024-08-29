#include <stddef.h> /* size_t */
#include <assert.h> /* assert */

#include "vsa.h"

#define MIN_MEMORY_SIZE 24
#define BLOCK_ALIGNMENT sizeof(vsa_t)
#define WORD_SIZE 8
#define KEY 1234567890

struct header
{
	long size;
	#ifndef NDBUG
	size_t magic_num;
	#endif
};

static long AbsVal(long x);
static size_t AlignBlockSize(size_t size);
static long Max_Val(long a , long b);


vsa_t *VSAInit(void *memory_block, size_t mem_size)
{
	if (mem_size < 2 * BLOCK_ALIGNMENT + WORD_SIZE)
	{
		return NULL;
	}

	((vsa_t *)memory_block)->size = mem_size - (2 * BLOCK_ALIGNMENT) - (mem_size % WORD_SIZE);
	
	((vsa_t *)((char *)memory_block + (((vsa_t *)memory_block)->size) + BLOCK_ALIGNMENT))->size = 0;
	
	return (vsa_t *)memory_block;
}


void *VSAAllocateBlock(vsa_t *vsa, size_t size_of_block)
{
	vsa_t *runner = vsa;
	long temp = 0;
	
	size_of_block = AlignBlockSize(size_of_block);
	
	while (0 != ((vsa_t *)(((char *)runner) + AbsVal(runner->size) + BLOCK_ALIGNMENT))->size && (runner->size < (long)size_of_block))
	{
		if(runner->size < 0)
		{
			runner = (vsa_t *)(((char *)runner) + AbsVal(runner->size) + BLOCK_ALIGNMENT);
		}
		else
		{
			if (((vsa_t *)(((char *)runner) + runner->size + BLOCK_ALIGNMENT))->size > 0)
			{
				runner->size += ((vsa_t *)(((char *)runner) + runner->size + BLOCK_ALIGNMENT))->size + BLOCK_ALIGNMENT;
			}
			else
			{
				runner = (vsa_t *)(((char *)runner) + AbsVal(runner->size) + BLOCK_ALIGNMENT);
			}
		}
	}
	
	if(runner->size >= ((long)size_of_block))
	{
		temp = runner->size - BLOCK_ALIGNMENT - size_of_block;
		
		if (runner->size != (long)size_of_block)
		{
			((vsa_t *)(((char *)runner) + size_of_block + BLOCK_ALIGNMENT))->size = temp;
		}
		
		#ifndef NDBUG
		runner->magic_num = KEY;
		#endif
		
		if (temp > 0)
		{
			runner->size = -size_of_block;
		}
		else
		{
			runner->size *= -1;
		}
		
		return (void *)(((char *)runner) + BLOCK_ALIGNMENT);
	}
	else
	{
		return NULL;
	}
}


void VSAFreeBlock(void *to_free)
{
	assert(KEY == (((vsa_t *)to_free) - 1)->magic_num);
	assert(0 > (((vsa_t *)to_free) - 1)->size);
	
	((vsa_t *)((char *)to_free - BLOCK_ALIGNMENT))->size *= -1;
}


size_t VSALargestFreeBlock(const vsa_t *vsa)
{
	vsa_t *runner = (vsa_t *)vsa;
	long maxblock = 0;
	
	while(0 != ((vsa_t *)(((char *)runner) + AbsVal(runner->size) + BLOCK_ALIGNMENT))->size)
	{
		if(runner->size < 0)
		{
			runner = (vsa_t *)(((char *)runner) + AbsVal(runner->size) + BLOCK_ALIGNMENT);
		}
		else
		{
			if (((vsa_t *)(((char *)runner) + runner->size + BLOCK_ALIGNMENT))->size > 0)
			{
				runner->size += ((vsa_t *)(((char *)runner) + runner->size + BLOCK_ALIGNMENT))->size + BLOCK_ALIGNMENT;
			}
			else
			{
				maxblock = Max_Val(maxblock, runner->size);
				
				runner = (vsa_t *)(((char *)runner) + AbsVal(runner->size) + BLOCK_ALIGNMENT);
			}
		}
	}
	
	maxblock = Max_Val(maxblock, runner->size);
	
	return (size_t)maxblock;
}


static long Max_Val(long a , long b)
{
	return a > b ? a : b;
}

static long AbsVal(long x)
{
	return x < 0 ? -1 * x : x;
}

static size_t AlignBlockSize(size_t size)
{
	if (size < WORD_SIZE)
	{
		size = WORD_SIZE;
	}
	
	if (0 != size % WORD_SIZE)
	{
		size = size + (WORD_SIZE - (size % WORD_SIZE));
	}
	
	return size;
}





