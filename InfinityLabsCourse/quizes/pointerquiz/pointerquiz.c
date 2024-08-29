#include <stdio.h>


void foo(void)
{
	int *pi = NULL;
	int a = 1, b = 2, c = 3;
	char *c_str = "abcd";
	char *p_str = c_str;
	char arr_str[] = "abcd";
	char ch = '\0';
	
	short *ps = 0;
	
	printf("A%s\n", c_str + 1);
	printf("B%lu\n", sizeof(c_str));
	printf("C%s\n", arr_str + 1);
	printf("D%lu\n", sizeof(arr_str));
	printf("E%s\n", p_str);
	printf("F%lu\n", sizeof(p_str));
	
	
	printf("G%lu\n", sizeof(*ps));
	printf("H%lu\n", sizeof(*pi));
	
	/* *pi = a;*/
	pi = &c;
	/*&b = pi;*/
	
	/*c_str[2] = '0';*/
	printf("I%s\n", c_str);
	*(arr_str + 1) = '0';
	printf("J%s\n", arr_str);
	/*++arr_str;*/
	printf("K%s\n", arr_str);
	
	p_str= (char *)&c + 3;
	printf("X%d\n", c);
	*p_str = '1';
	printf("L%d\n", c);
	
	pi = (int *)&ch;
	*pi = 0;
	
}



int main()
{
	foo();
	return 0;
}



