#include <stdio.h>
#include <stdlib.h>

void TF(int num)
{
	int i = 0;
	for (; i < num; i++)
	{
		if (0 == i % 3)
		{
			printf("T\n");
		}
		else if (0 == i % 5)
		{
			printf("F\n");
		}
		else if (0 == i % 3 && 0 == i % 5)
		{
			printf("TF\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}


void RevStr(const char *str, char *rev_s, size_t s_len)
{
	size_t i = s_len + 1;
	rev_s = (char*)malloc(s_len*(sizeof(char)));
	
	if (!rev_s)
	{
		printf("malloc error!");
	}
	
	str += s_len;
	
	while (0 != i)
	{
		*rev_s = *str;
		printf("%c\n", *rev_s);
		rev_s++;
		str--;
		i--;
	}
	
	rev_s -= s_len;
	printf("%s\n", rev_s);
	
	free(rev_s);
}


int main()
{
	int x = 10;
	
	const char *str = "Etaoin Shrdlu";
	char *rev_s = "";
	size_t s_len = 13;
	
	
	/*EX 1*/
	TF(x);
	
	
	/*EX 2*/
	RevStr(str, rev_s, s_len);

	
	return 0;
}



