#include <stdio.h>
#include <stddef.h>

#define ROWS 20
#define COLS 20

void MissingNum()
{
	int arr[10] = {6, 1, 5, 3, 2, 0, 8, 9, 10, 7}; /*missing 4*/
	
	int lut[11] = {0};
	size_t i = 0;
	int res = -1;
	for( ; i < 11; ++i)
	{
		++lut[arr[i]];
	}
	
	for(i = 0; i < 10; ++i)
	{
		if(lut[i] == 0)
		{
			res = i;
		}
	}
	
	printf("%d\n", res);
}


int IsInside(int arr[ROWS][COLS], int wid, int len) /* (3) */
{
	
	size_t count_before_row = 0, count_after_row = 0, count_before_col = 0, count_after_col = 0;
	int i = 0, j = 0, inside = 0;
	if (wid < 0 || wid >= ROWS || len < 0 || len >= COLS) 
	{
		return 0;
	}
	
	i = wid - 1;
	j = wid + 1;
	while (1)
	{
		if (i >= 0)
		{
			if (1 == arr[i][len])
			{
				count_before_row = 1;
				
			}
			--i;
		}
		
		if (j < COLS)
		{
			if (1 == arr[j][len])
			{
				count_after_row = 1;
				
			}
			++j;
		}
		
		if (1 == arr[j][len] && 1 == arr[i][len] || i < 0 && j == COLS)
		{
			break;
		}
	}
	
	if (0 == count_before_row || 0 == count_after_row)
	{
		return 0;
	}
	
	i = len - 1;
	j = len + 1;
	while (1)
	{
		if (i >= 0)
		{
			if (1 == arr[wid][i])
			{
				count_before_col = 1;
			}
			--i;
		}
		
		if (j < ROWS)
		{
			if (1 == arr[wid][j])
			{
				count_after_col = 1;
			}
			++j;
		}
		
		if (1 == arr[wid][i] && 1 == arr[wid][j] || i < 0 && j == ROWS)
		{
			break;
		}
		
	}
	
	printf("%ld, %ld, %ld, %ld\n", count_before_row, count_after_row, count_before_col, count_after_col);
	
	return (4 == count_before_row + count_after_row + count_before_col + count_after_col);
}


int main()
{
	int shape[ROWS][COLS] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	int x = 10 , y = 10; /*in*/
	
	if (IsInside(shape, x, y))
	{
		printf("The point (%d, %d) is inside the shape.\n", x, y);
	}
	else
	{
		printf("The point (%d, %d) is outside the shape.\n", x, y);
	}
	
	x = 4 , y = 5; /*in*/
	if (IsInside(shape, x, y))
	{
		printf("The point (%d, %d) is inside the shape.\n", x, y);
	}
	else
	{
		printf("The point (%d, %d) is outside the shape.\n", x, y);
	}
	
	x = 2 , y = 5; /*out*/
	if (IsInside(shape, x, y))
	{
		printf("The point (%d, %d) is inside the shape.\n", x, y);
	}
	else
	{
		printf("The point (%d, %d) is outside the shape.\n", x, y);
	}
	
	x = 2 , y = 2; /*out*/
	if (IsInside(shape, x, y))
	{
		printf("The point (%d, %d) is inside the shape.\n", x, y);
	}
	else
	{
		printf("The point (%d, %d) is outside the shape.\n", x, y);
	}
	
	x = 4 , y = 8; /*out*/
	if (IsInside(shape, x, y))
	{
		printf("The point (%d, %d) is inside the shape.\n", x, y);
	}
	else
	{
		printf("The point (%d, %d) is outside the shape.\n", x, y);
	}
	
	MissingNum();
	
	
	return 0;
}


