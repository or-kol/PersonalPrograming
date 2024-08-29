#include <stdio.h> /* print */
#include <stdlib.h> /* atoi */
#include <arpa/inet.h> /* hstons */

#include "ws13.h"
 
#define IS_LITTLE_ENDIAN (!(1 == htons(1)))  /* return 1 = little endian*/
#define HEX (16)

int TestAtoi(char *num_str)
{
	if (Atoi(num_str) == atoi(num_str))
	{
		return 0;	/* success */
	}
	else
	{	
		return -1;
	}
}


int main()
{	
	int n_itoa = -17;
	char s_itoa[MAX_STR_LEN] = {0};
	
	int n_itoa2 = 17;
	char s_itoa2[MAX_STR_LEN] = {0};
	
	int n_atoi = 0;
	char *s_atoi = " -18";
	
	int n_atoi2 = 0;
	char *s_atoi2 = " 18";
	
	int n_itoa_any = -17;
	char s_itoa_any[MAX_STR_LEN] = {0};
	
	int n_itoa_any2 = 0x12f;
	char s_itoa_any2[MAX_STR_LEN] = {0};
	
	int n_atoi_any = 0;
	char *s_atoi_any = "18";
	
	int n_atoi_any2 = 0;
	char *s_atoi_any2 = "12f";
	
	char arr1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	char arr2[10] = {'a', 'b', 'c', 'd', 'e', 'x', 'x', 'y', 'z', 'w'};
	char arr3[10] = {'r', 'r', 'a', 'x', 'y', 'z', 'r', 'h', 'i', 'j'};
	
	
	
	Itoa(n_itoa, s_itoa);
	printf("%s\n", s_itoa);
	
	Itoa(n_itoa2, s_itoa2);
	printf("%s\n", s_itoa2);
	
	n_atoi = Atoi(s_atoi);
	printf("%d\n", n_atoi);
	
	n_atoi2 = Atoi( s_atoi2);
	printf("%d\n", n_atoi2);
	
	ItoaAnyBase(n_itoa_any, s_itoa_any, DEC);
	printf("%s\n", s_itoa_any);
	
	ItoaAnyBase(n_itoa_any2, s_itoa_any2, HEX);
	printf("%s\n", s_itoa_any2);
	
	n_atoi_any = AtoiAnyBase(s_atoi_any, DEC);
	printf("%d\n", n_atoi_any);
	
	n_atoi_any2 = AtoiAnyBase(s_atoi_any2, HEX);
	printf("%x\n", n_atoi_any2);
	
	
	printf("%d\n", TestAtoi(s_atoi));
	
	
	PrintChars(arr1, arr2, arr3, 10, 10, 10);
	
	printf("%d\n", IS_LITTLE_ENDIAN);
	
	return 0;
}
