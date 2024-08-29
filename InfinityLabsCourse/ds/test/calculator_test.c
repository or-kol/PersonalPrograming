#include <stdio.h>



#include "calculator.h"



int main()
{
	char *math_exp = "3 * 3 + 4 - 5 / -2 * (5 + 5) + 4 * 3";
	double res = 9999999; 
	Calculator(math_exp, &res);

	printf("%f\n", res);

	return 0;
}
