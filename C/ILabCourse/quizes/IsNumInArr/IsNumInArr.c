#include <stddef.h> /* size_t */
#include <stdio.h> /* print */


int IsNumInArray(int *arr, size_t size, int num)
{
	size_t i = 0;
	int sum = 1;
	
	for ( ;i < size; ++i)
	{
		sum *= arr[i] - num;
	}
	
	return (0 == sum);
}


int main ()
{
	int array[6] = {1, 2, 6, 7, 8, 10};
	
	int x = 20, y = 7;
	
	if (1 == IsNumInArray(array, 6, x))
	{
		printf("Num in array\n");
	}
	else
	{
		printf("Num not in array\n");
	}
	
	if (1 == IsNumInArray(array, 6, y))
	{
		printf("Num in array\n");
	}
	else
	{
		printf("Num not in array\n");
	}
	
	return(0);
}




