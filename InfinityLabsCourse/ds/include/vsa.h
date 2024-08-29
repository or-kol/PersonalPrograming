#ifndef __VSA_H__
#define __VSA_H__

#include <stddef.h> /* size_t */
#include <stdlib.h> /* abs */

/* type of the variable size allocator */
typedef struct header vsa_t;



/* VSAInit:
Description - generate capacity to allocat.
Params:
	void *memory_block
	size_t size_of_memory
return value - vsa_t *
time complexity - O(1)
space complexity - O(1)
*/
vsa_t *VSAInit(void *memory_block, size_t size_of_memory);


/* VSAAllocateBlock:
Description - allocate block for the user.
Params:
	vsa_t *vsa
	size_t size_of_block
return value - void *
time complexity - O(n)
space complexity - O(1)
*/
void *VSAAllocateBlock(vsa_t *vsa, size_t size_of_block);


/* VSAFreeBlock:
Description - free block from user.
Params:
	void *to_free - pointer to data to free
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void VSAFreeBlock(void *to_free);


/* VSALargestBlockSize:
Description - returns larget block available.
Params:
	vsa_t *vsa
return value - size_t.
time complexity - O(n)
space complexity - O(1)
*/
size_t VSALargestFreeBlock(const vsa_t *vsa);

#endif
