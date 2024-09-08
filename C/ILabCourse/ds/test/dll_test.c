#include <stdio.h> /* print */
#include <string.h> /* memcmp */

#include "dll.h"


int IsMatch(const void *val1, const void *val2)
{
	size_t size = sizeof(int);
	return (0 == memcmp(val1, val2, size));
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
	
	int x = 3, y = 4, z = 5, a = 14, b = 8, c = 12, d = 15;
	dll_t *new_dll = DLLCreate();
	dll_t *new_dll2 = DLLCreate();
	
	dll_iterator_t iter1 = DLLBegin(new_dll);
	dll_iterator_t iter2 = DLLBegin(new_dll);
	
	dll_iterator_t iter3 = DLLBegin(new_dll2);
	dll_iterator_t iter4 = DLLEnd(new_dll2);
	
	if (1 == DLLIsEmpty(new_dll))
	{
		printf("Is empty <empty> success\n");
	}
	
	
	iter1 = DLLInsert(iter1, &x, new_dll);
	
	if (3 == *(int *)DLLGetData(iter1))
	{
		printf("Create success\n");
		printf("Insert success\n");
		printf("Get success\n");
		printf("Begin success\n");
	}
	
	DLLInsert(iter1, &y, new_dll);
	DLLInsert(iter1, &z, new_dll);
	DLLInsert(iter1, &a, new_dll);
	DLLInsert(iter1, &b, new_dll);	
	
	
	iter1 = DLLBegin(new_dll);
	iter1 = DLLNext(iter1);
	
	if (5 == *(int *)DLLGetData(iter1))
	{
		printf("Next success\n");
	}
	
	
	DLLSetData(iter1, &c);
	if (12 == *(int *)DLLGetData(iter1))
	{
		printf("Set success\n");
	}
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	DLLForEach(iter1, iter2, operation_print, &x);
	
	
	iter2 = DLLBegin(new_dll);
	iter2 = DLLNext(iter2);
	iter2 = DLLNext(iter2);
	iter2 = DLLNext(iter2);
	
	
	
	iter1 = DLLFind(iter1, iter2, IsMatch, &c);
	
	if (12 == *(int *)DLLGetData(iter1))
	{
		printf("Find positive test success\n");
	}
	
	
	iter2 = DLLBegin(new_dll);
	iter2 = DLLNext(iter2);
	iter2 = DLLNext(iter2);
	iter2 = DLLNext(iter2);
	iter2 = DLLFind(iter1, iter2, IsMatch, &z);
	if (8 == *(int *)DLLGetData(iter2))
	{
		printf("Find negative test success\n");
	}
	
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLBegin(new_dll);
	
	
	if (5 == DLLSize(new_dll))
	{
		printf("Size success\n");
	}
	
	
	if (0 == DLLIsEmpty(new_dll))
	{
		printf("Is empty <not empty> success\n");
	}
	
	
	iter1 = DLLNext(iter1);
	iter1 = DLLNext(iter1);
	
	
	iter2 = DLLRemove(iter1, new_dll);
	
	if (8 == *(int *)DLLGetData(iter2))
	{
		printf("Remove success\n");
	}
	
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLBegin(new_dll);
	
	
	iter2 = DLLEnd(new_dll);
	if (NULL == (void *)DLLGetData(iter2))
	{
		printf("End success\n");
	}
	
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLBegin(new_dll);
	
	
	if (1 == DLLIsEqual(iter1, iter2))
	{
		printf("Is equal positive test success\n");
	}
	
	iter2 = DLLNext(iter2);
	if (0 == DLLIsEqual(iter1, iter2))
	{
		printf("Is equal negative test success\n");
	}
	
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLBegin(new_dll);
	
	
	iter1 = DLLNext(iter1);
	iter2 = DLLNext(iter2);
	iter2 = DLLNext(iter2);
	iter2 = DLLNext(iter2);
	DLLForEach(iter1, iter2, operation_add, &x);
	
	if (15 == *(int *)DLLGetData(iter1))
	{
		iter1 = DLLNext(iter1);
		if (11 == *(int *)DLLGetData(iter1))
		{
			iter1 = DLLNext(iter1);
			if (3 == *(int *)DLLGetData(iter1))
			{
				printf("For each success\n");
			}
		}	
	}
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	
	
	
	DLLPushBack(new_dll, &x);
	
	iter1 = DLLEnd(new_dll);
	iter1 = DLLPrev(iter1);
	
	if (3 == *(int *)DLLGetData(iter1))
	{
		printf("Push back success\n");
		printf("Previous success\n");
	}
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	
	DLLPushFront(new_dll, &c);
	iter1 = DLLBegin(new_dll);
	
	
	if (15 == *(int *)DLLGetData(iter1))
	{
		printf("Push front success\n");
	}
	
	
	DLLPopFront(new_dll);
	
	iter1 = DLLBegin(new_dll);
	
	if (4 == *(int *)DLLGetData(iter1))
	{
		printf("Pop front success\n");
	}
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	
	DLLPopBack(new_dll);
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	iter2 = DLLPrev(iter2);
	
	if (3 == *(int *)DLLGetData(iter2))
	{
		printf("Pop back success\n");
	}
	
	
	DLLPushFront(new_dll, &c);
	DLLPushFront(new_dll, &c);
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	
	DLLMultiFind(iter1, iter2, IsMatch, &d, new_dll2);
	
	iter3 = DLLBegin(new_dll2);
	iter4 = DLLEnd(new_dll2);
	
	if (15 == *(int *)DLLGetData(iter3))
	{
		iter1 = DLLNext(iter1);
		if (15 == *(int *)DLLGetData(iter3))
		{
			iter1 = DLLNext(iter1);
			if (15 == *(int *)DLLGetData(iter3))
			{
				printf("Multi find success\n");
			}
		}	
	}
	
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	
	iter1 = DLLNext(iter1);
	iter2 = DLLPrev(iter2);	
	
	iter3 = DLLBegin(new_dll2);
	iter4 = DLLEnd(new_dll2);
	
	iter3 = DLLNext(iter3);
	
	DLLSpliced(iter1, iter2, iter3);
	
	
	iter1 = DLLBegin(new_dll);
	iter2 = DLLEnd(new_dll);
	
	iter3 = DLLBegin(new_dll2);
	iter4 = DLLEnd(new_dll2);	
	
	if (15 == *(int *)DLLGetData(iter1))
	{
		iter1 = DLLNext(iter1);
		if (3 == *(int *)DLLGetData(iter1))
		{
			if (15 == *(int *)DLLGetData(iter3))
			{
				iter3 = DLLNext(iter3);
				iter3 = DLLNext(iter3);
				if (4 == *(int *)DLLGetData(iter3))
				{
					iter3 = DLLNext(iter3);
					iter3 = DLLNext(iter3);
					if (11 == *(int *)DLLGetData(iter3))
					{
						printf("Spliced success\n");
					}
				}
			}
		}	
	}
	
	
	DLLDestroy(new_dll);
	DLLDestroy(new_dll2);
	return 0;
}









