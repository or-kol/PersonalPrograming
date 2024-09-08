#include <stdio.h>
#include <math.h>


double Sqrt(double number)
{
	double guess = number / 2.0; /* Initial guess */
	double epsilon = 0.00001; /* Tolerance level */
	
	if (number < 0)
	{
		return -1;
	}
	
	if (number == 0 || number == 1)
	{
		return number;
	}

	/* Iterate till the guess is close enough */
	while ((guess * guess - number) > epsilon || (number - guess * guess > epsilon))
	{
		guess = (guess + (number / guess)) / 2.0;
	}
	
	return guess;
}



int main()
{
	double x = 10000;
	double y = 365;
	
	printf("%lf\n", sqrt(x));
	printf("%lf\n", Sqrt(x));
	printf("%lf\n", sqrt(y));
	printf("%lf\n", Sqrt(y));
	
	return 0;
}
