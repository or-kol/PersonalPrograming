#ifndef __FSA_H__
#define __FSA_H__

#include <stddef.h>

/* type of the fixed size allocator */
typedef struct fsa fsa_t;


/* FSAMinPoolSize:
Description - generate capacity to allocat.
Params:
	size_t size_of_block
	size_t num_of_blocks
return value - size_t
time complexity - O(1)
space complexity - O(1)
*/
size_t FSAMinPoolSize(size_t size_of_block, size_t num_of_blocks);


/* FSAInit:
Description - generate capacity to allocat.
Params:
	void * memory_block - allocated memory.
	size_t size_of_block
	size_t num_of_blocks
return value - fsa_t *
time complexity - O(n)
space complexity - O(1)
*/
fsa_t *FSAInit(void * memory_block, size_t size_of_block, size_t num_of_blocks);


/* FSAAllocateBlock:
Description - allocate block for the user.
Params:
	fsa_t *fsa
return value - void *
time complexity - O(1)
space complexity - O(1)
*/
void *FSAAllocateBlock(fsa_t *fsa); /*O(1)*/


/* FSAFreeBlock:
Description - free block from user.
Params:
	fsa_t *fsa
	void *to_free - pointer to free data.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void FSAFreeBlock(fsa_t *fsa, void *to_free);  /*O(1)*/


/* FSACountNumOfFreeBlocks:
Description - returns ammount of free blocks.
Params:
	fsa_t *fsa
return value - size_t.
time complexity - O(n)
space complexity - O(1)
*/
size_t FSACountNumOfFreeBlocks(const fsa_t *fsa); /*O(n)*/

#endif
