#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

#define MAX3(a, b, c)  ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define TO_LOWER(c) (tolower(c))
#define OFF_SET(s, f) ((char *)&f - (char *)(&s))


struct s
{
	int num;
	char ch1;
	int *ptr;
	char ch2;
};

struct s s_1 = {1, 's', &s_1.num, 'e'};

int main()
{
	printf("%d\n", MAX3(1,2,3));
	printf("%d\n", MAX3(3,2,1));
	printf("%d\n", MAX3(2,3,1));
	
	printf("%c\n", TO_LOWER('V'));
	printf("%c\n", TO_LOWER('v'));
	
	printf("%ld\n", OFF_SET(s_1, s_1.ch1));
	printf("%ld\n", offsetof(struct s, ch1));
	
	
}



