#ifndef __STACK_H__
#define __STACK_H__
#include <stddef.h> /* size_t */


/* type of the stack management struct */
typedef struct stack stack_t;


/* StackCreate:
Description - create the stack data structure.
Params:
	size_t capasity - how many variables can the stack contain.
	size_t size_of_element - size of each elment in bytes.
return value - stack_t *
time complexity - O(1)
space complexity - O(1)
*/
stack_t *StackCreate(size_t capacity, size_t size_of_element);


/* StackDestroy:
Description - delete the stack.
Params:
	stack_t *stack - management struct.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void StackDestroy(stack_t *stack);


/* StackPush:
Description - push new element to stack.
Params:
	stack_t *stack - management struct.
	const void *val - pointer to the vlue to push.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void StackPush(const void *val, stack_t *stack);


/* StackPop:
Description - pop element from stack.
Params:
	stack_t *stack - management struct.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void StackPop(stack_t *stack);


/* StackPeek:
Description - returns the pointer to the value in the top of the stack.
Params:
	const stack_t *stack - management struct.
return value - void *.
time complexity - O(1)
space complexity - O(1)
*/
void *StackPeek(const stack_t *stack);


/* StackIsEmpty:
Description - returns 1 if empty 0 if not.
Params:
	const stack_t *stack - management struct.
return value - int.
time complexity - O(1)
space complexity - O(1)
*/
int StackIsEmpty(const stack_t *stack);


/* StackSize:
Description - returns how many elements in the stack.
Params:
	const stack_t *stack - management struct.
return value - size_t.
time complexity - O(1)
space complexity - O(1)
*/
size_t StackSize(const stack_t *stack);


/* StackCapacity:
Description - Max number of items the stack can store.
Params:
	const stack_t *stack - management struct.
return value - size_t.
time complexity - O(1)
space complexity - O(1)
*/
size_t StackCapacity(const stack_t *stack);


void *StackMin(const stack_t *stack);

#endif /*__STACK_H__*/



