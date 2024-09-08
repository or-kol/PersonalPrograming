#include <stddef.h>

typedef struct Result
{
	int missings[2];
} result_ty;

result_ty TwoMissingNumbers(const int numbers[], size_t array_size)
{
	result_ty result = { 0 };
	int j = 0, i = 0, k = 0, act_size = array_size + 2;
	
	for (j = act_size ; j > 0 && k < 2; --j)
	{
		for (i = 0; i < array_size; ++i)
		{
			if (0 == (j ^ numbers[i]))
			{
				break;
			}
		}
		
		if (array_size == i)
		{
			result.missings[k] = j;
			++k;
		}
	}
	
	return result;
}


int main()
{ 	
	int numbers[10] = {4, 11, 2, 12, 5, 3, 6, 8, 9, 10};
	result_ty result;
	result = TwoMissingNumbers(numbers, 10);
	
	printf("%d, %d\n", result.missings[0], result.missings[1]);
	
	return 0; 
} 






