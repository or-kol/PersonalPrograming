#include <stdio.h> /* print */
#include <stddef.h> /* size_t */


void SumIntPairsToLongs(int *arr, size_t size)
{
	size_t i = 0;
	long sum = 0;
	
	for ( ; i < size - 1; i += 2)
	{
		sum = (long)arr[i] + (long)arr[i + 1];
		arr[i / 2] = sum;
	}
}

int main ()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	size_t size = 10, i = 0;
	
	SumIntPairsToLongs(arr, size);
	
	for ( ; i < size/2; ++i)
	{
		printf("%ld\n", (long)arr[i]);
	}
	
	return 0;
}
