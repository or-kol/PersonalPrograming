#include <stdio.h>
#include <stddef.h>


int IsSumFound(int *array, int size, int sum, int *index1, int *index2)
{
	int left = 0, right = size - 1, current_sum = array[left] + array[right];
	
	while (left < right)
	{
		current_sum = array[left] + array[right];
		printf ("%d\n", left);
		printf ("%d\n", right);
		if (current_sum == sum)
		{
			*index1 = left;
			*index2 = right;
			return 1;  /* sum found */
		}
		else if (current_sum < sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	
	return 0; /* sum not found */
}



int main()
{
	int arr[] = {2,4,7,12,14};
	int num1, num2;
	
	printf("sum = 21:\nreturn = %d\n", IsSumFound(arr, 5, 21, &num1, &num2));
	printf("num1 = %d, num2 = %d\n", num1, num2);
	printf("\n");
	
	num1 = 0;
	num2 = 0;
	printf("sum = 30:\nreturn = %d\n", IsSumFound(arr, 5, 30, &num1, &num2));
	printf("num1 = %d, num2 = %d\n", num1, num2);
	
	return 0;
}
