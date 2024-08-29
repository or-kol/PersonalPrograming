#include <stdio.h> /* print */
#include <stddef.h> /* size_t */

int BestPrice(int *prices, size_t prices_len, int *min, int *max)
{
	int i = 1, min_price = *prices, current_profit = 0, max_profit = 0;
	
	for ( ; i < prices_len; ++i)
	{
		if (prices[i] < min_price)
		{
			min_price = prices[i];
			*min = i;
		}
	
		current_profit = prices[i] - min_price;
		
		if (current_profit > max_profit)
		{
			max_profit = current_profit;
			*max = i;
		}
	}
	
	return max_profit;
}


int main()
{
	int prices[8] = {6, 12, 3, 5, 1, 4, 9, 2};
	
	int x, y, result = BestPrice(prices, 8, &x, &y);
	printf("%d == %d == %d\n", result, x, y);

	return 0;
}
