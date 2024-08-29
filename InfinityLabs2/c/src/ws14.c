#include <stddef.h> /* size_t */
#include <assert.h> /* assert */
#include <limits.h> /* CHAR_BIT */


#include "ws14.h"


#define SYS_BITS ((sizeof(size_t) * CHAR_BIT))
#define SET (1)
#define NIBBLE_SIZE (4)
#define BIT_LUT_SIZE (16)
#define MAX_NIBBLE_VAL (15)

/*Or Kol - review by Raz*/

int BitArrGet(bitarr_t arr, size_t idx)
{
	return (arr >> idx) & (size_t)1;
}


bitarr_t BitArrSetOn(bitarr_t arr, size_t idx)
{
	return arr | ((size_t)1 << idx);
}


bitarr_t BitArrSetOff(bitarr_t arr, size_t idx)
{
	return arr & ~((size_t)1 << idx);
}


bitarr_t BitArrFlip(bitarr_t arr, size_t idx)
{
	return arr ^ ((size_t)1 << (idx));
}


bitarr_t BitArrRotateR(bitarr_t arr, size_t shift)
{
	shift = shift % SYS_BITS; 
	return (arr >> shift)|(arr << (SYS_BITS - shift));
}


bitarr_t BitArrRotateL(bitarr_t arr, size_t shift)
{
	shift = shift % SYS_BITS;
	return (arr << shift)|(arr >> (SYS_BITS - shift));
}


bitarr_t BitArrResetAll(bitarr_t arr)
{
	return (size_t)0;
}


bitarr_t BitArrSetAll(bitarr_t arr)
{
	return ~(size_t)0;
}


int BitArrCountOn(bitarr_t arr)
{
	if (32 == SYS_BITS)
	{
		int bit_mask1 = 0x55555555;
		int bit_mask2 = 0x33333333;
		int bit_mask3 = 0x0F0F0F0F;
		int bit_mask4 = 0x00FF00FF;
		int bit_mask5 = 0x0000FFFF;
		
		arr = (arr & bit_mask1) + ((arr >> 1) & bit_mask1);
		arr = (arr & bit_mask2) + ((arr >> 2) & bit_mask2);
		arr = (arr & bit_mask3) + ((arr >> 4) & bit_mask3);
		arr = (arr & bit_mask4) + ((arr >> 8) & bit_mask4);
		arr = (arr & bit_mask5) + ((arr >> 16) & bit_mask5);
	}
	else
	{
		long bit_mask1 = 0x5555555555555555;
		long bit_mask2 = 0x3333333333333333;
		long bit_mask3 = 0x0F0F0F0F0F0F0F0F;
		long bit_mask4 = 0x00FF00FF00FF00FF;
		long bit_mask5 = 0x0000FFFF0000FFFF;
		long bit_mask6 = 0x00000000FFFFFFFF;
		
		arr = (arr & bit_mask1) + ((arr >> 1) & bit_mask1);
		arr = (arr & bit_mask2) + ((arr >> 2) & bit_mask2);
		arr = (arr & bit_mask3) + ((arr >> 4) & bit_mask3);
		arr = (arr & bit_mask4) + ((arr >> 8) & bit_mask4);
		arr = (arr & bit_mask5) + ((arr >> 16) & bit_mask5);
		arr = (arr & bit_mask6) + ((arr >> 32) & bit_mask6);
	}
	
	return arr;
}


int BitArrCountOff(bitarr_t arr)
{
	return SYS_BITS - BitArrCountOn(arr);
}


char *BitArrToString(bitarr_t arr, char *dest)
{
	size_t idx = 0;
	int bit = -1;
	
	assert(NULL != dest);
	
	for(; idx < SYS_BITS; ++idx)
	{
		bit = arr & (size_t)1;
		
		if(SET == bit)
		{
			*dest = '1';
		}
		else
		{
			*dest = '0';
		}
		
		arr >>= 1;
		++dest;
	}
	
	*dest = '\0';
	
	return dest;
}


bitarr_t BitArrMirror(bitarr_t arr)
{
	if (32 == SYS_BITS)
	{
		unsigned int bit_mask1 = 0x55555555;
		unsigned int bit_mask2 = 0x33333333;
		unsigned int bit_mask3 = 0x0F0F0F0F;
		unsigned int bit_mask4 = 0x00FF00FF;
		unsigned int bit_mask5 = 0x0000FFFF;
		
		arr = ((arr >> 16) & bit_mask5) | (arr & bit_mask5) << 16;
		arr = ((arr >> 8) & bit_mask4) | (arr & bit_mask4) << 8;
		arr = ((arr >> 4) & bit_mask3) | (arr & bit_mask3) << 4;
		arr = ((arr >> 2) & bit_mask2) | (arr & bit_mask2) << 2;
		arr = ((arr >> 1) & bit_mask1) | (arr & bit_mask1) << 1;
	}
	else
	{
		
		size_t bit_mask1 = 0x5555555555555555;
		size_t bit_mask2 = 0x3333333333333333;
		size_t bit_mask3 = 0x0F0F0F0F0F0F0F0F;
		size_t bit_mask4 = 0x00FF00FF00FF00FF;
		size_t bit_mask5 = 0x0000FFFF0000FFFF;
		size_t bit_mask6 = 0x00000000FFFFFFFF;
		
		printf("d\n");
		
		arr = ((arr >> 32) & bit_mask6) | (arr & bit_mask6) << 32;
		arr = ((arr >> 16) & bit_mask5) | (arr & bit_mask5) << 16;
		arr = ((arr >> 8) & bit_mask4) | (arr & bit_mask4) << 8;
		arr = ((arr >> 4) & bit_mask3) | (arr & bit_mask3) << 4;
		arr = ((arr >> 2) & bit_mask2) | (arr & bit_mask2) << 2;
		arr = ((arr >> 1) & bit_mask1) | (arr & bit_mask1) << 1;
	}
	
	return arr;
}


int BitArrCountOnLUT(bitarr_t arr)
{
	unsigned char bit_lut[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	int counter = 0;
	
	while (0 != arr)
	{
		counter += bit_lut[arr & 0xF];
		arr >>= NIBBLE_SIZE;
	}
	
	return counter;
}


bitarr_t BitArrMirrorLUT(bitarr_t arr)
{
	unsigned char bit_lut_miror[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	size_t i = 0;
	bitarr_t mirror = 0;
	unsigned char nibble = 0, nibble_mir = 0;
	
	for ( ; i < BIT_LUT_SIZE; ++i)
	{
		nibble = (arr >> (i * NIBBLE_SIZE)) & 0xF;						/*get 4-bit nibble*/
		
		nibble_mir = bit_lut[nibble];								/* get mirrored nibble from LUT*/
		
		mirror |= ((bitarr_t)nibble_mir) << ((MAX_NIBBLE_VAL - i) * NIBBLE_SIZE);		/* Place the mirrored nibble to correct position*/
	}
	
	return mirror;
}



