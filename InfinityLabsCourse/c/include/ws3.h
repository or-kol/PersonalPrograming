#ifndef __WS3_H__
#define __WS3_H__

#include <stdlib.h>



size_t StrLen(const char * str);

int StrNCmp(const char *str1, const char *str2, size_t n);

int StrCmp(const char* s1, const char* s2);

char *StrNCpy(char *dest, const char *src, size_t n);

char *StrCpy(char *dest, const char *src);

int StrCaseCmp(const char *s1, const char *s2);

char *StrChr(const char *s, int c);

char *StrDup(const char *s);

char *StrCat(char *dst, const char *src);

char *StrNCat(char *dst, const char *src, size_t ssize);

char *StrStr(const char *haystack, const char *needle);

size_t StrSpn(const char *s, const char *accept);

int IsPolindrome(char *s);

char *RevieWhiteSpaces(char *s);




#endif 
__WS3_H__

