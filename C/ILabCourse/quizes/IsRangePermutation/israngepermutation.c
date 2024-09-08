#include <stddef.h>
#include <stdio.h>

int IsRangePermutation(const int numbers[], size_t size, int range_min)
{
	size_t i = 0;
	int res = 0;
	
	for ( ; i < size; ++i)
	{
		res ^= range_min++ ^ numbers[i];
	}
	
	return 0 == res;
}

int main()
{
	int arr1[6] = {12, 7, 10, 8, 9, 11};
	int arr2[6] = {6, 4, 7, 8, 7, 5};
	int arr3[6] = {-12, -7, -10, -8, -9, -11};
	
	printf("%d\n", IsRangePermutation(arr1, 6, 7));
	printf("%d\n", IsRangePermutation(arr2, 6, 4));
	printf("%d\n", IsRangePermutation(arr3, 6, -12));
	
	return 0;
}
