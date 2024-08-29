#include <stdio.h> /* print */

#include "ws5.h"


int main(int argc, char *argv[], char *envp[]) {
	
	int row_arr[3][5] = { {1, 2, 3, 4, 5}, {6, 4, 1, 3, 5}, {3, 6, 0, 5, 4} };
	int *sum_row_arr = RowSum((int *)row_arr, 3, 5);
	
	int i = 0;
	int soldiers[100] = {0};
	
	
	
	for (; i < 3; i++)
	{
		printf("%d\n", sum_row_arr[i]);
	}
		
	printf ("%d\n", Josephus(soldiers, 100));
		
	
	
	printf("char = %ld\n", sizeof(char));
	printf("int = %ld\n", sizeof(int));
	printf("float = %ld\n", sizeof(float));
	printf("double = %ld\n", sizeof(double));
	printf("short = %ld\n", sizeof(short));
	printf("long = %ld\n", sizeof(long));
	printf("signed char = %ld\n", sizeof(signed char));
	printf("unsigned char = %ld\n", sizeof(unsigned char));
	printf("unsigned int = %ld\n", sizeof(unsigned int));
	printf("unsigned short = %ld\n", sizeof(unsigned short));
	printf("unsigned long = %ld\n", sizeof(unsigned long));
	
	
	
	Environment(envp);
	
	
	
	return 0;
}
