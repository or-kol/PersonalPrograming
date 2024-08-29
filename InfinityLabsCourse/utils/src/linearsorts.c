#include <stddef.h> /* size_t */
#include <stdlib.h> /* calloc */
#include <stdio.h> /* print */

#include "linearsorts.h"

static int GetMax(int *arr, size_t size);

void CountSort(int *arr, size_t size)
{
	int i = 0;
	int *count_arr;
	int *output_arr;
	int max = GetMax(arr, size);
	
	count_arr = (int *)calloc(max + 1, sizeof(int));
	output_arr = (int *)calloc(size, sizeof(int));
	
	for(i = 0; i < size; ++i)
	{
		++count_arr[arr[i]];
	}
	
	for(i = 1; i <= max; ++i)
	{
		count_arr[i] += count_arr[i-1];
	}
	
	for(i = size - 1; i >= 0; --i)
	{
		output_arr[count_arr[arr[i]] - 1] = arr[i];
		--count_arr[arr[i]];
	}
	
	for (i = 0; i < size; i++)
	{
		arr[i] = output_arr[i];
	}
	
	free(count_arr);
	free(output_arr);	
}



static void RdixCountingSort(int *arr, size_t size, int digit, int base)
{
	int *count_arr;
	int *output_arr;
	int i = 0;
	
	count_arr = (int *)calloc(base + 1, sizeof(int));
	output_arr = (int *)calloc(size, sizeof(int));
	
	for (i = 0; i < size; i++)
	{
		count_arr[(arr[i] / digit) % base]++;
	}
	
	for (i = 1; i < base; i++)
	{
		count_arr[i] += count_arr[i - 1];
	}
	
	for (i = size - 1; i >= 0; i--)
	{
		output_arr[count_arr[(arr[i] / digit) % base] - 1] = arr[i];
		--count_arr[(arr[i] / digit) % base];
	}
	
	for (i = 0; i < size; i++)
	{
		arr[i] = output_arr[i];
	}
	
	free(count_arr);
	free(output_arr);
}


void RadixSort(int arr[], size_t size) 
{
	int max = GetMax(arr, size); 
	int digit = 1, base = 10;
	
	for ( ; max / digit > 0; digit *= 10)
	{
		RdixCountingSort(arr, size, digit, base);
	}
}


static int GetMax(int *arr, size_t size)
{
	size_t i = 0;
	int max = arr[i];
	
	for( ; i < size; ++i)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}




