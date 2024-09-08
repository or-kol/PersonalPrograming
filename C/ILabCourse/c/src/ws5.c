#include <stdlib.h> /* size_t */
#include <string.h> /* strcpy */
#include <ctype.h> /* tolower*/
#include <assert.h> /* assert */

#include "ws5.h"


/*
int *RowSum(int arr[3][5], size_t column_len, size_t row_len)
{
	size_t i = 0, j = 0;
	static int sum_arr[3] = {0}, sum = 0;
	
	for ( ; i < column_len; i++)
	{
		for (j = 0 ; j < row_len; j++)
		{
			sum += arr[i][j];
		}
		sum_arr[i] = sum;
		sum = 0;
		
	}
	
	return sum_arr;
}
*/


int *RowSum(int *arr, size_t column_len, size_t row_len)
{
	size_t i = 0, j = 0;
	static int sum_arr[3] = {0};
	int sum = 0;
	
	for ( ; i < column_len; i++)
	{
		for (j = 0 ; j < row_len; j++)
		{
			sum += *((arr + (i * row_len)) + j);
		}
		
		sum_arr[i] = sum;
		sum = 0;
		
	}
	
	return sum_arr;
}


/*
int Josephus(int sold_arr[], size_t size) {
	size_t idx = 0, i = 0, n = 1, remaine = size;
	
	while (remaine > 1) {
		if (idx >= size) {
			idx = 0;
			n *= 2;
			printf("n = %ld\n", n);
		}
		
		idx += n;
		
		while (sold_arr[idx] != 0) {
			idx++;
			
			if (idx >= size) {
				idx = 0;
				n *= 2;
				printf("n = %ld\n", n);
				break;
			}
		}
		
		if (0 == sold_arr[idx])
		{
			sold_arr[idx] = 1;
			printf("%ld\n", idx);
			idx += n;
			remaine--;
		}
		
		if (n >= 32)
		{
			n = 1;
		}
        }
        
	for (; i < size; i++) {
		if (sold_arr[i] == 0) {
			return i;
		}
	}

	return -1;
}
*/


int Josephus(int sold_arr[], size_t size)
{
	size_t i = 0;
	int idx = 0;
	
	for ( ; i < size; i++)
	{
		sold_arr[i] = i+1;
	}
	
	sold_arr[99] = 0;
	
	while (idx != sold_arr[idx])
	{
		sold_arr[idx] = sold_arr[sold_arr[idx]];
		idx = sold_arr[idx];
	}
	
	return idx;
}


char **Environment(char **envp)
{
	size_t envp_len = 0, i = 0, j = 0, k = 0;
	char **envp_arr = NULL;
	
	assert(envp);
	
	while (NULL != *(envp + envp_len))
	{
		++envp_len;
	}
	
	envp_arr = (char **)malloc(sizeof(char *) * envp_len);
	
	if (NULL == envp_arr)
	{
		return;
	}
	
	for ( ; i < envp_len; i++)
	{
		*(envp_arr + i) = (char *)malloc(sizeof(char) * (strlen(*(envp + i)) + 1));
		
		if (NULL == envp_arr[i])
		{
			return;
		}
		
		strcpy(*(envp_arr + i), *(envp + i));
		
		for (j = 0; j < strlen(*(envp + i)); j++)
		{
			envp_arr[i][j] = tolower(envp_arr[i][j]);
		}
		
		printf("%s\n", *(envp_arr + i));		
	}

	for ( ; k < envp_len; k++)
	{
		free(*(envp_arr + k));
	}
	
	free(envp_arr);
	
}









