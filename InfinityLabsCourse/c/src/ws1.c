#include "ws1.h"

void PrintHello()
{
	const char say_hello_hex[14] = {0x22, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 
	0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x22};
	
	printf("%s\n", say_hello_hex);
}


double PowerOfTen(int exp){
	int i, base = 10;
	double sum = 1.0;
	
	if (exp >= 0)
	{ 					
		for (i = 0; i < exp; i++)
		{
			sum *= base;
		}
	}
	else	/*if n is negative */
	{
		int minus_exp = -(exp);			
		for (i = 0; i < minus_exp; i++){
			sum /= base;
		} 
	}
	
	return sum;
}


int FlipIntOrder(int n)
{
	int res = 0;
	
	/* take the resedue of deviding by ten and add it in reverse order.*/
	do
	{
		res = (res * 10) + n%10;
		n /= 10;
	} while (n != 0);
	
	
	if (n >= 0)
	{
		return res;
	}
	else
	{
		return -res;
	}
}


void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

