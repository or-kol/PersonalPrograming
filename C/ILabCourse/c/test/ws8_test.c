#include <stdio.h> /* print */


#include "ws8.h"


int main() {
	
	unsigned int v = 128, w = 255, x = 2, y = 2, z = 7;
	
	unsigned int num_3_ones[] = {7, 49, 259, 256, 8, 20};
	
	unsigned char byte = 10, a = 255, b = 2, c = 32, d = 24;
	
	int swap_x = 25, swap_y = 13;
	
	float f_bits = 65.125;
	
	
	
	printf("%ld\n", Pow2(x, y));
	printf("%ld\n", Pow2(x, z));
	
	printf("%d\n", IsPowerOf2Loop(x));
	
	printf("%d\n", IsPowerOf2Loop(z));
	
	
	if (IsPowerOf2Loop(x) == 1)
	{
		printf("%d is a power of 2\n", x);
	}
	else
	{
		printf("%d is not a power of 2\n", x);
	}
	
	if (IsPowerOf2Loop(z) == 1)
	{
		printf("%d is a power of 2\n", z);
	}
	else
	{
		printf("%d is not a power of 2\n", z);
	}
	
	
	printf("%d\n", IsPowerOf2(x));
	printf("%d\n", IsPowerOf2(v));
	printf("%d\n", IsPowerOf2(z));
	printf("%d\n", IsPowerOf2(w));
	
	
	Add1(x);
	Add1(v);
	Add1(z);
	Add1(w);
	
	
	Print3BitsOn(num_3_ones, 6);
	
	
	
	printf("%d\n", ByteMirrorLoop(byte));
	printf("%d\n", ByteMirror(byte));
	
	
	
	printf("%d\n", SecondAndSixthOn(a));
	printf("%d\n", SecondAndSixthOn(b));
	printf("%d\n", SecondAndSixthOn(c));
	printf("%d\n", SecondAndSixthOn(d));
	
	
	printf("%d\n", SecondOrSixthOn(a));
	printf("%d\n", SecondOrSixthOn(b));
	printf("%d\n", SecondOrSixthOn(c));
	printf("%d\n", SecondOrSixthOn(d));
	
	
	
	printf("%d\n", Swap3and5(d));
	printf("%d\n", Swap3and5(a));
	
	
	
	printf("%d\n", ClosestDevisbleBy16(w));
	printf("%d\n", ClosestDevisbleBy16(z));
	
	
	
	SwapNoTemp(swap_x, swap_y);
	printf("%d <--> %d\n", swap_x, swap_y);
	
	
	
	printf("%d\n", CountSetBits(v));
	printf("%d\n", CountSetBits(z));
	printf("%d\n", CountSetBits(w));
	
	
	
	PrintFloatBits(&f_bits);
	
	
	
	return 0;
}









