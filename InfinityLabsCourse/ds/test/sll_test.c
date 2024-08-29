#include <stdio.h> /* print */
#include <string.h> /* memcmp */

#include "sll.h"


int IsMatch(void *val1, void *val2)
{
	size_t size = 4;
	if (0 == memcmp(val1, val2, size))
	{
		return 1;
	}
	return 0;
}

size_t operation_add(void *current_val, void *add_val)
{
	*(int *)current_val += *(int *)add_val;
	return 0;
}

size_t operation_print(void *current_val, void *add_val)
{
	(void)add_val;
	printf("%d\n", *(int *)current_val);
	return 0;
}


int main() {
	
	int x = 3, y = 4, z = 5, a = 14, b = 8, c = 12;
	sll_t *new_sll = SLLCreate();
	sll_iterator_t arr[] = {NULL};
	
	
	sll_iterator_t iter1 = SLLBegin(new_sll);
	sll_iterator_t iter2 = SLLBegin(new_sll);
	
	if (1 == SLLIsEmpty(new_sll))
	{
		printf("Is empty <empty> success\n");
	}
	
	
	SLLInsert(iter1, &x, new_sll);
	
	if (3 == *(int *)SLLGetData(iter1))
	{
		printf("Create success\n");
		printf("Insert success\n");
		printf("Get success\n");
		printf("Begin success\n");
	}
	
	SLLInsert(iter1, &y, new_sll);
	SLLInsert(iter1, &z, new_sll);
	SLLInsert(iter1, &a, new_sll);
	SLLInsert(iter1, &b, new_sll);	
	
	
	iter1 = SLLNext(iter1);
	if (14 == *(int *)SLLGetData(iter1))
	{
		printf("Next success\n");
	}
	
	
	SLLSetData(iter1, &c);
	if (12 == *(int *)SLLGetData(iter1))
	{
		printf("Set success\n");
	}
	
	
	iter2 = SLLNext(iter2);
	iter2 = SLLNext(iter2);
	iter2 = SLLNext(iter2);
	iter2 = SLLFind(iter1, iter2, IsMatch, &z);
	if (5 == *(int *)SLLGetData(iter2))
	{
		printf("Find positive test success\n");
	}
	
	
	iter2 = SLLBegin(new_sll);
	iter2 = SLLNext(iter2);
	iter2 = SLLNext(iter2);
	iter2 = SLLNext(iter2);
	iter2 = SLLFind(iter1, iter2, IsMatch, &x);
	if (NULL == iter2)
	{
		printf("Find negative test success\n");
	}
	
	
	iter1 = SLLBegin(new_sll);
	iter2 = SLLBegin(new_sll);
	
	
	if (5 == SLLSize(new_sll))
	{
		printf("count success\n");
	}
	
	
	if (0 == SLLIsEmpty(new_sll))
	{
		printf("Is empty <not empty> success\n");
	}
	
	
	iter1 = SLLNext(iter1);
	iter1 = SLLNext(iter1);
	
	iter2 = SLLRemove(iter1, new_sll);
	
	if (4 == *(int *)SLLGetData(iter2))
	{
		printf("Remove success\n");
	}
	
	
	iter1 = SLLBegin(new_sll);
	iter2 = SLLBegin(new_sll);
	
	
	iter2 = SLLEnd(new_sll);
	if (NULL == (void *)SLLGetData(iter2))
	{
		printf("End success\n");
	}
	
	
	iter1 = SLLBegin(new_sll);
	iter2 = SLLBegin(new_sll);
	
	
	if (1 == SLLIsEqual(iter1, iter2))
	{
		printf("Is equal positive test success\n");
	}
	
	iter2 = SLLNext(iter2);
	if (0 == SLLIsEqual(iter1, iter2))
	{
		printf("Is equal negative test success\n");
	}
	
	
	iter1 = SLLBegin(new_sll);
	iter2 = SLLBegin(new_sll);
	
	
	iter1 = SLLNext(iter1);
	iter2 = SLLNext(iter2);
	iter2 = SLLNext(iter2);
	iter2 = SLLNext(iter2);
	SLLForEach(iter1, iter2, operation_add, &x);
	if (15 == *(int *)SLLGetData(iter1))
	{
		iter1 = SLLNext(iter1);
		if (7 == *(int *)SLLGetData(iter1))
		{
			iter1 = SLLNext(iter1);
			if (3 == *(int *)SLLGetData(iter1))
			{
				printf("For each success\n");
			}
		}	
	}
	
	iter1 = SLLBegin(new_sll);
	iter2 = SLLEnd(new_sll);
	
	
	iter1 = SLLFindNthFromLast(new_sll, 3, arr);
	
	if (15 == *(int *)SLLGetData(iter1))
	{
		printf("Find nth success\n");
		
	}
	
	iter1 = SLLBegin(new_sll);
	SLLForEach(iter1, iter2, operation_print, &x);
	
	
	
	
	SLLDestroy(new_sll);
	
	return 0;
}









