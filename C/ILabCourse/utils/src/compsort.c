#include <stddef.h> /* size_t */

#include "compsort.h"

static void Swap(int *var1, int *var2);

void BubbleSort(int *arr, size_t size)
{
	size_t i = 0, j = 0;
	int is_swapp = 0;
	
	for(i = 0; i < size - 1; i++)
	{
		is_swapp = 0;
		for(j = 0; j < size - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				Swap(&arr[j], &arr[j+1]);
				is_swapp = 1;
			}
		}
		
		if(0 == is_swapp)
		{
			break;
		}
	}
}


void SelectionSort(int *arr, size_t size)
{
	size_t i = 0, j = 0, min_i = 0;
	
	for(i = 0; i < size; ++i)
	{
		min_i = i;
		for (j = i; j < size; ++j)
		{
			if(arr[min_i] > arr[j])
			{
				min_i = j;
			}
		}
		
		if(min_i != i)
		{
			Swap(arr+i, arr+min_i);
		}
	}
}


void InsertionSort(int *arr, size_t size)
{
	size_t i = 1;
	int j = 0;
	
	for( ; i < size; ++i)
	{
		j = i;
		while(arr[j] < arr[j-1] && i > 0)
		{
			Swap(arr+j, arr+j-1);
			--j;
		}
	}
}


static void Swap(int *var1, int *var2)
{
	*var1 += *var2;
	*var2 = *var1 - *var2;
	*var1 -= *var2;
}

