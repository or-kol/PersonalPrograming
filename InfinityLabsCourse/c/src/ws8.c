#include <stdio.h> /* print */

#include "ws8.h"



long Pow2(unsigned int x, unsigned int y)
{
	return x << y;
}


int IsPowerOf2Loop(unsigned int n)
{
	int count = 0;
	while (0 != n)
	{
		if (1 == (n & 1))
		{
			++count;
		}
		n >>= 1;
	}
	
	if (1 == count)
	{
		return 1;
	}
	
	return 0;
}


int IsPowerOf2(unsigned int n)
{
	if (n != 0 && 0 == (n & (n - 1))) 	/*every power of two binary representation has MSB on and all zeros*/
	{				  	/*if we will subtruct 1, we will get a number with all zeros as 1*/
		return 1;		  	/*the & operetor will turn all compliment bits to 0 - so we will get all zeros*/
	}
	
	return 0;
}


int Add1(int n)
{
	n = (-(~n));				/*NOT operation flip all bits*/
	return n;				/*'-' uses two's compliment which flips all bits and adds 1*/
}


void Print3BitsOn(unsigned int num_arr[], size_t arr_size)
{
	size_t i = 0;
	unsigned int n = 0, count = 0;
	
	for ( ; i < arr_size; ++i)
	{
		n = num_arr[i];
		count = 0;
		
		while (n > 0 && count <= 3)
		{	
			if (1 == n % 2)
			{
				++count;
			}
			
			n /= 2;
		}
		
		if (3 == count)
		{
			printf("%d has 3 ones in it's binary representation!\n", num_arr[i]);
		}
	}
}


int ByteMirrorLoop(unsigned char b)
{
	unsigned char reverse = 0;
	size_t i = 0;
	
	for ( ; i < (sizeof(char) * 8); ++i) 
	{
		reverse = reverse << 1;			/*move reverse left to make space for next bit*/
		reverse = reverse | (b & 1);		/*adding current bit of b to reverse*/
		b = b >> 1;				/*move b one spot right to get the next bit*/
	}
	
	return reverse;
}


int ByteMirror(unsigned char b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;		/*swap the first 4 bits and the last 4 bits of a byte.*/
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;		/*swaps the first 2 bits and last 2 bits of each set of 4 bits.*/
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;		/*swap adjacent pairs of bits.*/
	
	return b;
}


int SecondAndSixthOn(unsigned char b)
{
	return ((b >> 1) & 1) & ((b >> 5) & 1);
}


int SecondOrSixthOn(unsigned char b)
{
	return ((b >> 1) & 1) | ((b >> 5) & 1);
}


int Swap3and5(unsigned char b)
{
	unsigned char b1 = (b >> 2) & 1;		/* Move p1'th to rightmost side */ 
	
	unsigned char b2 = (b >> 4) & 1;		/* Move p2'th to rightmost side */
	
	unsigned char x = (b1 ^ b2);			/* XOR the two bits */
	
   	x = (x << 2) | (x << 4);			/* Put the xor bit back to their original positions */
	
	return b ^ x;					/* XOR 'x' with the original number so that the two sets are swapped */
}


int ClosestDevisbleBy16(unsigned int n)
{
	n >>= 4;
	n <<= 4;
	return n;
}


void SwapNoTemp(int x , int y)
{
	x = x ^ y; 
	y = x ^ y;
	x = x ^ y;
}


int CountSetBits(int n)
{
	int count = 0;
	while (n > 0)
	{
		if (1 == n % 2)
		{
			++count;
		}
		
		n /= 2;
	}
	
	return count;
}


int CountSetBitsNoLoop(unsigned int n)
{
	int bit_mask1 = 0x55555555;
	int bit_mask2 = 0x33333333;
	int bit_mask3 = 0x0F0F0F0F;
	int bit_mask4 = 0x00FF00FF;
	int bit_mask5 = 0x0000FFFF;
	
	n = (n & bit_mask1) + ((n >> 1) & bit_mask1);
	n = (n & bit_mask2) + ((n >> 2) & bit_mask2);
	n = (n & bit_mask3) + ((n >> 4) & bit_mask3);
	n = (n & bit_mask4) + ((n >> 8) & bit_mask4);
	n = (n & bit_mask5) + ((n >> 16) & bit_mask5);
	return n;
}


void PrintFloatBits(float *f)
{
	int *np = (int*)f;
	int i = sizeof(int) * 8;
	for ( ; i > 0 ; i--)
	{
		printf("%d", (*np >> i) & 1);
	}
	printf("\n");
}








