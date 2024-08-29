#include <stdio.h> /* print */
#include <stdlib.h> /* random */
#include <time.h> /* time */

#define ASCII_MAX (256)

int ascii_lut[256] = {0};

void PrintMaxOccur(int c)
{
	int max = 0, i = 0;
	
	srand(time(0));
	
	while ('0' != c)
	{
		c = rand() % ASCII_MAX;
		++ascii_lut[c];
	}
	
	for ( ; i < ASCII_MAX; ++i)
	{
		if (max < ascii_lut[i])
		{
			max = ascii_lut[i];
		}
	}
	
	printf("%d\n", max);
}

int CountSetBit(long x)
{
	size_t counter = 0;
	
	while (0 != x)
	{
		x &= x-1;
		++counter;
	}
	
	return counter;
}

int main()
{
	
	PrintMaxOccur('d');
	
	printf("%d\n", CountSetBit(1));
	printf("%d\n", CountSetBit(7));
	printf("%d\n", CountSetBit(15));
	
	
	return 0;
}
