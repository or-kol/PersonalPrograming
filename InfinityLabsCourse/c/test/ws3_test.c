#include "ws3.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	
	/*TESTS DATA*/
	/*data for string length:*/
	const char *str1 = "abcd";
	const char *str2 = "abcdef";
	

	/*data for string n compare: */
	const char *s_n_compare1 = "Hello";
	const char *s_n_compare2 = "Hello";
	size_t n1 = 3;
	
	const char *s_n_compare3 = "Hello ";
	const char *s_n_compare4 = "Hellob";
	size_t n2 = 4;
	
	const char *s_n_compare5 = "Hello World";
	const char *s_n_compare6 = "hello World";
	size_t n4 = 7;
	size_t n5 = 3;
	
	
	/*data for string compare: */
	const char *s_compare1 = "Hello";
	const char *s_compare2 = "Hello";
	
	const char *s_compare3 = "Hello ";
	const char *s_compare4 = "Hellob";
	
	const char *s_compare5 = "Hello World";
	const char *s_compare6 = "hello World";
	
	
	/*data for string case compare: */
	const char *s_case_compare1 = "Hello World";
	const char *s_case_compare2 = "hello World";
	
	const char *s_case_compare3 = "HelloWorld";
	const char *s_case_compare4 = "hello World";
	
	const char *s_case_compare5 = "Hel.lo World";
	const char *s_case_compare6 = "hello World";
	
	
	/*data for string n copy: */
	const char copy_s2[] = "Hello World!";
	
	char copied_s2[10];
	size_t n = 5;
	
	
	/*data for string copy: */
	const char copy_s1[] = "Hello World!";
	char copied_s1[20];
	
	
	/*data for strdup: */
	const char *copy_s3 = "Etaoin Shrdlu";
	char copied_s3[15];
	
	
	/*data for strchr: */
	const char *s_c1 = "Etaoin Shrdlu";
	int s_c_c1 = 'E';
	char *s_c_c1_res = "";
	
	int s_c_c2 = ' ';
	char *s_c_c2_res = "";
	
	int s_c_c3 = 'd';
	char *s_c_c3_res = "";
	
	int s_c_c4 = 'x';
	char *s_c_c4_res = "";
	
	int s_c_c5 = 's';
	char *s_c_c5_res = "";
	
	
	/*data for strncat: */
	const char *str_src = " Shrdlu";
	char str_dest[15] = "Etaoin";
	size_t size = 3;
	char *strncat_returned_value = "";
	
	
	/*data for strcat: */
	const char *str_src2 = " Shrdlu";
	char str_dest2[15] = "Etaoin";
	char *strcat_returned_value = "";
	
	
	/*data for strstr: */
	const char *str_haystack1 = "Etaoin Shrdlu";
	char *str_needle1 = "aoi";
		
	const char *str_haystack2 = "Etaoin Shrdlu";
	char *str_needle2 = "aoS";
	
	const char *str_haystack3 = "Etaoin Shrdlu";
	char *str_needle3 = "aoin ";
	
	
	/*data for StrSpn: */
	const char *str_haystack4 = "Etaoin Shrdlu";
	const char *str_needle4 = "aoin ";
	size_t expect_res = 5;
	
	
	/*data for IsPolindrome: */
	char *polindrome1 = "asdfdsa";
	char *polindrome2 = "asddsa";
	char *polindrome3 = "asxfdsa";
	char *polindrome4 = "asdfdya";
	
	
	/*data for RevieWhiteSpaces: */
	char x[] = "   as   as e   x		b  ";
	
	
		/*TESTS*/	
	/*test string length: */
	assert(StrLen(str1) == strlen(str1));
	assert(StrLen(str2) == strlen(str2));
	
	
	/*test string n compare:*/
	
	assert(StrNCmp(s_n_compare1, s_n_compare2, n1) == strncmp(s_n_compare1, s_n_compare2, n1));
	assert(StrNCmp(s_n_compare3, s_n_compare4, n2) == strncmp(s_n_compare3, s_n_compare4, n2));	
	assert(StrNCmp(s_n_compare5, s_n_compare6, n4) == strncmp(s_n_compare5, s_n_compare6, n4));
	assert(StrNCmp(s_n_compare6, s_n_compare5, n5) == strncmp(s_n_compare6, s_n_compare5, n5));
	
	
	/*test string compare: */
	assert(StrCmp(s_compare1, s_compare2) == strcmp(s_compare1, s_compare2));
	assert(StrCmp(s_compare3, s_compare4) == strcmp(s_compare3, s_compare4));
	assert(StrCmp(s_compare4, s_compare3) == strcmp(s_compare4, s_compare3));
	assert(StrCmp(s_compare5, s_compare6) == strcmp(s_compare5, s_compare6));
	assert(StrCmp(s_compare6, s_compare5) == strcmp(s_compare6, s_compare5));
	
	
	/*test string case compare: */
	assert(StrCaseCmp(s_case_compare1, s_case_compare2) == 0);
	assert(StrCaseCmp(s_case_compare2, s_case_compare1) == 0);
	
	assert(StrCaseCmp(s_case_compare3, s_case_compare4) > 0);
	assert(StrCaseCmp(s_case_compare4, s_case_compare3) < 0);
	
	assert(StrCaseCmp(s_case_compare5, s_case_compare6) < 0);
	assert(StrCaseCmp(s_case_compare6, s_case_compare5) > 0);
	
	
	/*test string n copy: */
	StrNCpy(copied_s2, copy_s2, n);
	printf("%s\n", copied_s2);
	
	
	/*test string copy: */
	StrCpy(copied_s1, copy_s1);
	printf("%s\n", copied_s1);
	
	
	/*test strdup: */
	StrCpy(copied_s3, copy_s3);
	printf("%s\n", copied_s3);
	
	
	/*test strchr: */
	s_c_c1_res = StrChr(s_c1, s_c_c1);
	assert(s_c_c1 == *s_c_c1_res);
	
	s_c_c2_res = StrChr(s_c1, s_c_c2);
	assert(s_c_c2 == *s_c_c2_res);
		
	s_c_c3_res = StrChr(s_c1, s_c_c3);
	assert(s_c_c3 == *s_c_c3_res);
		
	s_c_c4_res = StrChr(s_c1, s_c_c4);	
	assert('\0' == *s_c_c4_res);
		
	s_c_c5_res = StrChr(s_c1, s_c_c5);
	assert('\0' == *s_c_c5_res);
	
	
	/*test strncat: */
	strncat_returned_value = StrNCat(str_dest, str_src, size);
	printf("strncat: %s\n", strncat_returned_value);
	
	
	/*test strcat: */
	strcat_returned_value = StrCat(str_dest2, str_src2);
	printf("strcat: %s\n", strcat_returned_value);
	
	
	/*test StrStr: */
	/*test StrStr: */
	printf("%s\n", StrStr(str_haystack1, str_needle1));
	printf("%s\n", StrStr(str_haystack2, str_needle2));
	printf("%s\n", StrStr(str_haystack3, str_needle3));
	
	
	/*test StrSpn: */
	assert(StrSpn(str_haystack4, str_needle4) == expect_res);
	
	
	/*test IsPolindrome: */
	assert(IsPolindrome(polindrome1) == 0);
	assert(IsPolindrome(polindrome2) == 0);
	assert(IsPolindrome(polindrome3) == -1);
	assert(IsPolindrome(polindrome4) == -1);
	
	
	/*test RevieWhiteSpaces: */
	RevieWhiteSpaces(x);
	printf("%s\n", x);
	
	
	
	
	return 0;
}
