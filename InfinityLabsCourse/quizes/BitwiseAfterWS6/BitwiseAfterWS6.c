#include <stdio.h>

int CountPairsOfSetBits(unsigned char b)
{
	int count = 0, count_pairs = 0;
	
	while (0 != b)
	{
		if (1 == (b & 1))
		{
			++count;
		}
		else
		{
			count = 0;
		}
		
		if (2 == count)
		{
			++count_pairs;
			count = 1;
		}
		
		b >>= 1;
	}
	
	return count_pairs;
}

void Swap1(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Swap2(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void Swap3(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

int CountSetBitsInLong(long int l)
{
	int count = 0;
	while (0 != l)
	{
		++count;
		l = l & (l - 1);
	}
	
	
	return count;
}


int main()
{
	int x = 3, y = 5;
	unsigned char b = 7;
	long int l = 169548973;
	
	printf("%d\n", CountPairsOfSetBits(b));
	
	Swap1(&x, &y);
	printf("%d  <--> %d\n", x, y);
	
	Swap2(&x, &y);
	printf("%d  <--> %d\n", x, y);
	
	Swap3(&x, &y);
	printf("%d  <--> %d\n", x, y);
	
	
	printf("%d\n", CountSetBitsInLong(l));
	
	return 0;
}









