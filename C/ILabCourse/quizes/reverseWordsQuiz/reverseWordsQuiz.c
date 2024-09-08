#include <stdio.h>
#include <string.h>

/* function to reverse portion of string */
void Reverse(char *str, int start, int end)
{
	char temp;
	
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;	
	}
}

void FlipOrderOfWords(char *str)
{
	int len = strlen(str);
	int start = 0;
	int end = len - 1;
	int word_start = 0;
	int i = 0;
	
	/*Reverse entire string*/
	Reverse(str, start, end);
	
	/* Reverse each word */
	for ( ; i <= len; ++i)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			Reverse(str, word_start, i - 1);
			word_start = i + 1;
		}
	}
}



int main()
{
	char str[] = "i am student";
	char str2[] = "character to be tested";
	FlipOrderOfWords(str);
	FlipOrderOfWords(str2);
	
	printf("%s\n", str);
	printf("%s\n", str2);
	
	return 0;
}









