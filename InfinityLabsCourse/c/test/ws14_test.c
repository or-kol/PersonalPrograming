#include <stdio.h> /* print */
#include <assert.h> /* assert */


#include "ws14.h"
 

int main()
{
	
	
	
	bitarr_t exam = 5698651042273698762;
	
	int result = 0;
	
	char c1[65] = {0};
	char c2[65] = {0};
	
	
	
	
	char c3[65] = {0};
	char c4[65] = {0};
	
	
	
	printf("%d\n", BitArrGet(exam, 5));
	printf("%d\n", BitArrGet(exam, 58));
	
	result = BitArrSetOn(exam, 6);
	printf("before: %d\n", BitArrGet(exam, 6));
	printf("set on: %d\n", BitArrGet(result, 6));
	
	result = BitArrSetOff(exam, 7);
	printf("before: %d\n", BitArrGet(exam, 7));
	printf("set off: %d\n", BitArrGet(result, 7));
	
	result = BitArrFlip(exam, 7);
	printf("before: %d\n", BitArrGet(exam, 7));
	printf("flip off: %d\n", BitArrGet(result, 7));
	
	result = BitArrFlip(exam, 6);
	printf("before: %d\n", BitArrGet(exam, 6));
	printf("flip on: %d\n", BitArrGet(result, 6));
	
	assert(BitArrRotateR(4, 2) == 1);
	assert(BitArrRotateL(4, 2) == 16);
	
	printf("reset all: %lu\n", BitArrResetAll(exam));
	
	printf("set all: %lu\n", BitArrSetAll(exam));
	
	printf("%d\n", BitArrCountOn(7));
	printf("%d\n", BitArrCountOff(7));
	
	exam = 5698651042273698762;
	
	BitArrToString(exam, c1);
	printf("%s\n", c1);
	
	BitArrToString(BitArrMirrorLUT(exam), c2);
	printf("%s\n", c2);
	
	
	printf("%d\n", BitArrCountOnLUT(64));
	
	
	BitArrToString(exam, c3);
	printf("%s\n", c3);
	
	BitArrToString(BitArrMirrorLUT(exam), c4);
	printf("%s\n", c4);
	
	
	return 0;
}
