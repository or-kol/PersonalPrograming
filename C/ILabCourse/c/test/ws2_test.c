#include "ws2.h"


int main() {
	
	/*TESTS DATA*/
	/*varibles for swap values test:*/
	int a = 565, b = 8055;
	
	
	/*varibles for copy int array:*/
	int copied_arr[5];
	int arr_num[5] = {1, 2, 3, 4, 5};
	size_t i, n = 5;
	
	
	/*varibles for swap two size_t*: */
	size_t m = 15, l = 10;
	
	
	/*varibles for swap two size_t*: */
	size_t g = 15, h = 10;
	size_t *ptr3 = &g, *ptr4 = &h;
	
	
	/*varibles for string length:*/
	const char *str1 = "abcd";
	const char *str2 = "abcdef";
	
	/*test string compare: */
	const char *s1 = "abcd";
	const char *s2 = "abcd";
	const char *s3 = "xzy";
	const char *s4 = "hjk";
	const char *s5 = "kjdfd";
	const char *s6 = "ffgh2ew2";
	
	
	
	/*TESTS*/
	/*test swap values:*/
	SwapInt(&a, &b);
	assert (a == 8055);
	assert (b == 565);
	
	
	/*test copy int array*/
	CopyIntArray(arr_num, copied_arr, n);
	for (i = 0; i < n; i++){
		assert (arr_num[i] == copied_arr[i]);
	}
	
	
	/*test print var address*/
	PrintVarAddress();
	
	
	/*test swap two size_t*/
	SwapTwoSize_t(&m, &l);
	assert(l == 15);
	assert(m == 10);
	
	
	/*test swap two size_t*: */
	SwapTwoPointers(&ptr3, &ptr4);
	assert(ptr3 == &h);
	assert(ptr4 == &g);
	
	
	/*test string length: */
	assert(StrLen(str1) == 4);
	assert(StrLen(str2) == 6);
	
	
	/*test string compare: */
	assert(StrCmp(s1, s2) == 0);
	assert(StrCmp(s3, s4) > 0);
	assert(StrCmp(s4, s3) < 0);
	assert(StrCmp(s5, s6) > 0);
	assert(StrCmp(s6, s5) < 0);
	
	return 0;
}
