#include <stdio.h> /* print */


#include "stack.h"



int main() {
	
	stack_t *new_stack;
	int x = 5;
	int y = 7;
	
	new_stack = StackCreate(10, sizeof(int));
	
	StackPush((char *)&x, new_stack);
	StackPush((char *)&y, new_stack);
	
	printf("%d\n", *(int *)StackPeek(new_stack));
	
	StackPop(new_stack);
	
	printf("%d\n", *(int *)StackPeek(new_stack));
	
	printf("%d\n", StackIsEmpty(new_stack));
	
	printf("%ld\n", StackSize(new_stack));
	
	printf("%ld\n", StackCapacity(new_stack));
	
	printf("%d\n", *(int *)StackMin(new_stack));
	
	StackDestroy(new_stack);
	
	
	
	return 0;
}
