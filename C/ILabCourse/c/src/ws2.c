#include "ws2.h"

void SwapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void CopyIntArray(int *arr_num, int *copied_arr, size_t n)
{
	size_t i;
	
	for (i = 0; i < n; i++)
	{
		copied_arr[i] = arr_num[i];
	}
}


void PrintVarAddress()
{
	static int s_i = 7;
	int i = 7;
	int *ptr = &i;
	int *ptr2 = (int *)malloc(sizeof(int));
	
	if (ptr)
	{
		int **ptr3 = &ptr;
		printf("%p\n", (void *)ptr3);
	}
	
	printf("%p\n", (void *)&s_i);
	printf("%p\n", (void *)&i);
	printf("%p\n", (void *)ptr);
	printf("%p\n", (void *)ptr2);
	
	
	free(ptr2);
}



void SwapTwoSize_t(size_t *ptr1, size_t *ptr2)
{
	size_t temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}



void SwapTwoPointers(size_t **ptr3, size_t **ptr4)
{
	SwapTwoSize_t((size_t *)ptr3, (size_t *)ptr4);
}


size_t StrLen(const char *str)
{
	size_t counter = 0;
	
	while ('\0' != *str)
	{
		counter++;
		str++;
	}
		
	return counter;
}

int StrCmp(const char* s1, const char* s2)
{
	while ('\0' != *s1 && '\0' != *s2 && *s1 == *s2){
		s1++;
		s2++;
		
	}
	
	return (int)*s1 - (int)*s2;
}






