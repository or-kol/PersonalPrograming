#include <stdio.h> /* print, NULL */
#include <assert.h> /* assert */
#include <ctype.h> /* isspace */

#include "ws13.h"

#define ASCII_VAL_TO_DIGIT (48)
#define ASCII_VAL_TO_BASE (87)
#define LOW_A_ASCII_VAL (97)
#define MAX_DIGIT (9)
#define NUM_OF_CHARS (26)
#define MAX_BASE (36)

/* Or Kol - reviewed by Adi*/


char *Itoa(int num, char *num_str)
{
	int i = 1, count = 0;
	char num_str_rev[MAX_STR_LEN] = {0};
	
	assert(NULL != num_str);
	
	if (0 > num)
	{
		*num_str = '-';
		++num_str;
		num = -num;
	}
	
	while (0 != num)
	{
		num_str_rev[count] = (num % DEC) + '0';
		num /= DEC;
		++count;
	}
	
	for (i = count - 1; i >= 0; --i)
	{
		*num_str = num_str_rev[i];
		++num_str;
	}
	
	return num_str;
}


char *ItoaAnyBase(size_t num, char *num_str, int base)
{
	int i = 1, count = 0;
	char num_str_rev[MAX_STR_LEN] = {0};
	
	assert(NULL != num_str);
	
	if (2 > base && base > MAX_BASE)
	{
		return NULL;
	}
	
	if (0 > num)
	{
		*num_str = '-';
		++num_str;
		num = -num;
	}
	
	while (0 != num)
	{
		if ((num % base) > MAX_DIGIT)
		{
			num_str_rev[count] = ((num % base) - DEC) + LOW_A_ASCII_VAL;
		}
		else
		{
			num_str_rev[count] = (num % base) + '0';
		}
				
		num /= base;
		++count;
	}
	
	for (i = count - 1; i >= 0; --i)
	{
		*num_str = num_str_rev[i];
		++num_str;
	}
	
	return num_str;
}


int Atoi(char *num_str)
{  
	int i = 0, num = 0, flag = 1;
	
	assert(NULL != num_str);
	
	while(isspace(*num_str))
	{
		++num_str;
	}
	
	if ('-' == *num_str)
	{
		++num_str;
		flag = -1;
	}
	
	for ( ;num_str[i] != '\0'; ++i)
	{ 
		num = num * DEC + (num_str[i] - ASCII_VAL_TO_DIGIT);
	}
	
	return num * flag;
}


int AtoiAnyBase(char *num_str, int base)
{  
	int i = 0, num = 0, flag = 1;
	
	assert(NULL != num_str);
	assert(2 <= base && MAX_BASE >= base);
	
	while(isspace(*num_str))
	{
		++num_str;
	}
	
	if ('-' == *num_str)
	{
		++num_str;
		flag = -1;
	}
	
	for ( ;num_str[i] != '\0'; ++i)
	{ 
		if (num_str[i] - ASCII_VAL_TO_BASE <= base)
		{
			if (MAX_DIGIT >= num_str[i] - ASCII_VAL_TO_DIGIT)
			{
				num = num * base + (num_str[i] - ASCII_VAL_TO_DIGIT);
			}
			else
			{
				num = num * base + (num_str[i] - ASCII_VAL_TO_BASE);
			}
		}
		else
		{
			break;
		}
	}
	
	return num * flag;
}


void PrintChars(char *arr1, char *arr2, char *arr3, size_t arr1_len, size_t arr2_len, size_t arr3_len)
{
	char letters[NUM_OF_CHARS] = {0};
	size_t i = 0;
	
	for (i = 0; i < arr1_len; ++i)
	{
		if (0 == (letters[arr1[i] - LOW_A_ASCII_VAL]))
		{
			letters[arr1[i] - LOW_A_ASCII_VAL] += 1;
		}
	}
	
	for (i = 0; i < arr2_len; ++i)
	{
		if (1 == (letters[arr2[i] - LOW_A_ASCII_VAL]))
		{
			letters[arr2[i] - LOW_A_ASCII_VAL] += 1;
		}
	}
	
	for (i = 0; i < arr3_len; ++i)
	{
		letters[arr3[i] - LOW_A_ASCII_VAL] = 0;
	}
	
	for (i = 0; i < arr3_len; ++i)
	{
		if (2 == letters[i])
		{
			printf("%c\n", (char)(i + LOW_A_ASCII_VAL));
		}
	}
}


int IsLittleEndian()
{
	int n = 1;
	if(*(char *)&n == 1)
	{
		return 0;	/* little endian */
	}
	else
	{
		return -1;
	}
}





