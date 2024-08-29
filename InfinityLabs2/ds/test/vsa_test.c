#include <stdlib.h> /* malloc / free */
#include <stdio.h> /* print */

#include "vsa.h"

int main()
{
	size_t size_of_memory = 200;
	
	vsa_t *vsa = (void *)malloc(size_of_memory);
	
	size_t size1, size2, size3, size4;
	
	void *res_z;
	void *res_x;
	void *res_c;
	void *res_v;
	void *res_b;
	void *res_n;
	void *res_m;
	
	vsa = VSAInit(vsa, size_of_memory);
	
	size1 = VSALargestFreeBlock(vsa);
	
	res_z = VSAAllocateBlock(vsa, 4);
	res_v = VSAAllocateBlock(vsa, 12);
	res_x = VSAAllocateBlock(vsa, 2);
	
	if (NULL != res_z)
	{
		printf("Init Success\n");
		printf("Allocate Success\n");
	}
	
	size2 = VSALargestFreeBlock(vsa);
	
	if (168 == size1 && 88 == size2)
	{
		printf("Largest Free Block Success\n");
	}
	
	res_c = VSAAllocateBlock(vsa, 4);
	
	VSAFreeBlock(res_c);
	
	size3 = VSALargestFreeBlock(vsa);
	
	if (72 == size3)
	{
		printf("Free Block Success\n");
	}
	
	res_b = VSAAllocateBlock(vsa, 20);
	res_n = VSAAllocateBlock(vsa, 40);
	res_m = VSAAllocateBlock(vsa, 40);
	
	if (NULL == res_m)
	{
		printf("Allocate Negative Test Success\n");
	}
	
	VSAFreeBlock(res_v);
	VSAFreeBlock(res_x);
	
	size4 = VSALargestFreeBlock(vsa);
	if (40 == size4)
	{
		printf("Defragmentation Success\n");
	}
		
	free(vsa);
	
	return 0;
}
