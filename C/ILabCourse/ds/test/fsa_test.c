#include <stdio.h> /* print */
#include <stdlib.h> /* malloc */

#include "fsa.h"

int main()
{
	size_t size_of_block = sizeof(size_t), num_of_blocks = 10;
	
	size_t allocate_size = FSAMinPoolSize(size_of_block, num_of_blocks);
	void *fsa = (char *)malloc(allocate_size);
	
	int *z;
	int *x;
	int *c;
	int *v;
	int *b;
	
	int res1;
	
	fsa = FSAInit(fsa, size_of_block, num_of_blocks);
	
	z = (int *)FSAAllocateBlock(fsa);
	x = (int *)FSAAllocateBlock(fsa);
	c = (int *)FSAAllocateBlock(fsa);
	v = (int *)FSAAllocateBlock(fsa);
	b = (int *)FSAAllocateBlock(fsa);
	
	if ((char *)fsa + 8 == (char *)z)
	{
		printf("Init Success\n");
		printf("Allocate Block Success\n");
		printf("Min Pool Size Success\n");
	}
	
	*z = 1;
	*x = 2;
	*c = 3;
	*v = 4;
	*b = 5;
	
	res1 = *c;
	FSAFreeBlock(fsa, c);
	if (3 == res1 && 40 != *c)
	{
		printf("Free Block Success\n");
	}
	
	if (6 == FSACountNumOfFreeBlocks(fsa))
	{
		printf("Count Num Of Free Blocks Success\n");
	}
	
	free(fsa);
	
	
	return 0;
}









