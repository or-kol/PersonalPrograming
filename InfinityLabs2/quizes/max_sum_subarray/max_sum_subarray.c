#include <stdio.h>


int FindMaxSubarray(int arr[], int n, int *start, int *end)
{
	int i = 0, current_start = 0, current_sum = *arr, max_sum = *arr;
	
	for (; i < n; ++i)
	{
		if ((current_sum + arr[i]) < arr[i])
		{
			current_sum = arr[i];
			current_start = i;
		}
		else
		{
			current_sum += arr[i];
		}
		
		if (current_sum > max_sum)
		{
			max_sum = current_sum;
			*start = current_start;
			*end = i;
		}
	}
	
	return max_sum;
}

int main()
{
	int arr[] = {-2, 1, -3, 4, -1, 2, 3, -5, 4};
	int n = 9, max_sum = 0, start = 0, end = 0;
	
	max_sum = FindMaxSubarray(arr, n, &start, &end);
	
	printf("sum: %d\n", max_sum);
	printf("indexes: %d to %d\n", start, end);
	
	return 0;
}
