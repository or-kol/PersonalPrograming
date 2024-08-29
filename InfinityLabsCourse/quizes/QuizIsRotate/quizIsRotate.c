#include <stdio.h>
#include <string.h>

int IsRotation(const char *s1, const char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char s1s1[2 * len1 + 1];
	
	// Check lengths equal and non-zero
	if (len1 != len2 || len1 == 0)
	{
		return 0;
	}
	
	// Concatenate s1 with itself
	strcpy(s1s1, s1);
	strcat(s1s1, s1);
	
	// Check if s2 substring of s1s1
	if (strstr(s1s1, s2) != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	char str1[] = "12345";
	char str2[] = "45123";
	
	char str3[] = "121234";
	char str4[] = "125412";
	
	printf("%d\n", IsRotation(str1, str2));
	printf("%d\n", IsRotation(str3, str4));
	return 0;
}














	
	
