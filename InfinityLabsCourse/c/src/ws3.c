#include "ws3.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t StrLen(const char *str)
{
	size_t counter = 0;
	
	while (*str)
	{
		counter++;
		str++;
	}
		
	return counter;
}


int StrNCmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;
	
	while (*str1 && *str1 == *str2 && i < n)
	{
		++str1;
		++str2;
		++i;
	}
	
	return (int)*str1 - (int)*str2;
}


int StrCmp(const char* s1, const char* s2)
{
	size_t n = StrLen(s1) > StrLen(s2) ? StrLen(s1) : StrLen(s2);
	return StrNCmp(s1, s2, n);
}


int StrCaseCmp(const char *str1, const char *str2)
{	
	size_t i = 0;
	while (*str1 && (0 == *str1 - *str2 || -32 == *str1 - *str2 || 32 == *str1 - *str2))
	{
		str1++;
		str2++;		
		i++;
	}
		
	return (int)*str1 - (int)*str2;
}


char *StrNCpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;
	while (('\0' != *src) && i < n)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	
	dest -= i;
	
	return dest;
	
}


char *StrCpy(char *dest, const char *src)
{
	size_t str_len = StrLen(src);
	
	dest = StrNCpy(dest, src, str_len);
	
	return dest;
}


char *StrDup(const char *s)
{
	
	size_t s_len = StrLen(s);
	char * dest = (char *)malloc(s_len * (sizeof(char) + 1));
	
	printf("f");
	
	dest = StrNCpy(dest, s, s_len);
	
	return dest;
}


char *StrChr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{	
			break;
		}
		s++;
	}
	
	return (char *)s;
}


char *StrNCat(char *dest, const char *src, size_t size)
{	
	size_t i = 0, dest_len = StrLen(dest), comb_len = dest_len + size;
	
	dest += dest_len;

	while (src && i < size)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	
	dest -= comb_len;
	
	return dest;
}


char *StrCat(char *dst, const char *src)
{
	size_t src_len = StrLen(src);
	
	dst = StrNCat(dst, src, src_len);
	
	return dst;
}


char *StrStr(const char *haystack, const char *needle)
{
	size_t needle_len = StrLen(needle) - 1;
	
	while ('\0' != *haystack)
	{
		if (*haystack == *needle)
	        {
			if (0 == StrNCmp(needle, haystack, needle_len))
            		{
            			return (char *)needle;
            		}
        	}
        	haystack++;
    	}
    	return (char *)haystack;
}



size_t StrSpn(const char *s, const char *accept)
{
	
	size_t n = StrLen(StrStr(s, accept));
	
	return n;
}


int IsPolindrome(char *s)
{
	char *str_s = s;
	char *end_s = s;
	
	while ('\0' != *end_s)
	{
		end_s++;
	}
	
	end_s--;
	
	while (end_s > str_s)
	{
		if (tolower(*end_s) != tolower(*str_s))
		{
			return -1;
		}
		
		str_s++;
		end_s--;
	}
	
	return 0;

}


char *RevieWhiteSpaces(char *s)
{
	char *begin_s = s;
	char *end_s = s + strlen(s) -1;
	int idx = 0;
		
	while (0 != isspace(*begin_s)){
		begin_s++;
	}
	
	while (0 != isspace(*end_s)){
		end_s--;
	}
	
	while (begin_s <= end_s){
		if (0 == isspace(*begin_s)){
			*s = *begin_s;
			s++;
			idx++;
			begin_s++;
		}
		else{
			*s = *begin_s;
			s++;
			idx++;
			
			while(0 != isspace(*begin_s)){
				begin_s++;
			}	
		}
	}
	
	s -= idx;
	return s;
}
























