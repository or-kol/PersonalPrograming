#include <stdio.h> /* print */

#include "ws10.h"


#define MAX2(A, B)  (A > B ? A : B)
#define MAX3(a, b, c)  ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define SIZE_OF_VAR(VAR) ((char *)(&VAR + 1) - (char *)(&VAR))

#define SIZE_OF_TYPE(TYPE) ((char *)((TYPE *)0 + 1) - (char *)(TYPE *)0)


int main() {
	
	element_t arr[10];
	
	
	int max2_a = MAX2(2, 7);
	int max2_b = MAX2(2, 7);
	int max3_a = MAX3(4, 2, 7);
	int max3_b = MAX3(2, 7, 4);
	int max3_c = MAX3(7, 2, 4);
	
	
	int x = 5;
	char c = 'a';
	char *s = "Hello";
	char s_arr[] = "Hello";
	float f = 1.5;
	double d = 1.5;
	long l = 5;
	
	
	int size_of_x_var = SIZE_OF_VAR(x);
	int size_of_c_var = SIZE_OF_VAR(c);
	int size_of_s_var = SIZE_OF_VAR(s);
	int size_of_s_arr_var = SIZE_OF_VAR(s_arr);
	int size_of_f_var = SIZE_OF_VAR(f);
	int size_of_d_var = SIZE_OF_VAR(d);
	int size_of_l_var = SIZE_OF_VAR(l);
	
	
	int size_of_int = SIZE_OF_TYPE(int);
	int size_of_char = SIZE_OF_TYPE(char);
	int size_of_charptr = SIZE_OF_TYPE(char *);
	int size_of_float = SIZE_OF_TYPE(float);
	int size_of_double = SIZE_OF_TYPE(double);
	int size_of_long = SIZE_OF_TYPE(long);
	
	
	
	InitInt(5, &arr[0]);
	InitFloat(3.5, &arr[1]);
	InitString("Or", &arr[2]);
	PrintAll(arr, 3);
	
	printf("A\n");
	AddAll(arr, 3, 10);
	
	printf("B\n");
	PrintAll(arr, 3);
	
	CleanAll(arr, 3);
	PrintAll(arr, 2);
	
	
	printf("%d\n", max2_a);
	printf("%d\n", max2_b);
	printf("%d\n", max3_a);
	printf("%d\n", max3_b);
	printf("%d\n", max3_c);
	
	
	printf("%d\n", size_of_x_var);
	printf("%d\n", size_of_c_var);
	printf("%d\n", size_of_s_var);
	printf("%d\n", size_of_s_arr_var);
	printf("%d\n", size_of_f_var);
	printf("%d\n", size_of_d_var);
	printf("%d\n", size_of_l_var);
	
	
	printf("%d\n", size_of_int);
	printf("%d\n", size_of_char);
	printf("%d\n", size_of_charptr);
	printf("%d\n", size_of_float);
	printf("%d\n", size_of_double);
	printf("%d\n", size_of_long);
	
	return 0;
}
