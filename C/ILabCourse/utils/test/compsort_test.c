#include <stddef.h> /* size_t */
#include <stdio.h> /* print */
#include <time.h> /* time / clock_t */
#include <stdlib.h> /* rand */

#include "compsort.h"

static void TestBubbleSortFunctional();
static void TestSelectionSortFunctional();
static void TestInsertionSortFunctional();

static void TestBubbleSortNonfunctional();
static void TestSelectionSortNonfunctional();
static void TestInsertionSortNonfunctional();

static void CreateArr(int *arr, size_t size);
static int Compare(const void *var1, const void *var2);
static void CopyArr(int *source, int *target, size_t size);

enum status {fail, success};

int main()
{
	/* Functional tests*/
	printf("Functional Tests:\n");
	
	TestBubbleSortFunctional();
	
	TestSelectionSortFunctional();
	
	TestInsertionSortFunctional();
	
	
	/* Nonfunctional tests*/
	printf("\n");
	printf("Nonfunctional Tests:\n");
	
	TestBubbleSortNonfunctional();
	
	TestSelectionSortNonfunctional();
	
	TestInsertionSortNonfunctional();
	
	return 0;
}


static void TestBubbleSortFunctional()
{
	int arr[5000] = {0};
	size_t i = 1;
	
	CreateArr(arr, 5000);
	
	BubbleSort(arr, 5000);
	
	while(arr[i] >= arr[i - 1] && i < 5000)
	{
		++i;
	}
	
	if (5000 == i)
	{
		printf("Bubble Sort Functional Success\n");
	}
	else
	{
		printf("Bubble Sort Functional Fail\n");
	}
}


static void TestSelectionSortFunctional()
{
	int arr[5000] = {0};
	size_t i = 1;
	
	CreateArr(arr, 5000);
	
	SelectionSort(arr, 5000);
	
	while(arr[i] >= arr[i - 1] && i < 5000)
	{
		++i;
	}
	
	if (5000 == i)
	{
		printf("Bubble Sort Functional Success\n");
	}
	else
	{
		printf("Bubble Sort Functional Fail\n");
	}
}


static void TestInsertionSortFunctional()
{
	int arr[5000] = {0};
	size_t i = 1;
	
	CreateArr(arr, 5000);
	
	InsertionSort(arr, 5000);
	
	while(arr[i] >= arr[i - 1] && i < 5000)
	{
		++i;
	}
	
	if (5000 == i)
	{
		printf("Bubble Sort Functional Success\n");
	}
	else
	{
		printf("Bubble Sort Functional Fail\n");
	}
}


static void TestBubbleSortNonfunctional()
{
	int arr1[5000] = {0};
	int arr2[5000] = {0};
	clock_t start1 = 0, end1 = 0, start2 = 0, end2 = 0, interval = 0;
	
	CreateArr(arr1, 5000);
	
	CopyArr(arr1, arr2, 5000);
	
	start1 = clock();
	BubbleSort(arr1, 5000);
	end1 = clock();
	
	start2 = clock();
	qsort(arr2, 5000, sizeof(int), Compare);
	end2 = clock();
	
	interval = (end1-start1) - (end2-start2);
	
	if (0 > interval)
	{
		printf("Bubble Sort is faster than qsort\n");
	}
	else if (0 < interval)
	{
		printf("qsort is faster than Bubble Sort\n");
	}
	else
	{
		printf("qsort and Bubble Sort has equal run time\n");
	}
}


static void TestSelectionSortNonfunctional()
{
	int arr1[5000] = {0};
	int arr2[5000] = {0};
	clock_t start1 = 0, end1 = 0, start2 = 0, end2 = 0, interval = 0;
	
	CreateArr(arr1, 5000);
	
	CopyArr(arr1, arr2, 5000);
	
	start1 = clock();
	SelectionSort(arr1, 5000);
	end1 = clock();
	
	start2 = clock();
	qsort(arr2, 5000, sizeof(int), Compare);
	end2 = clock();
	
	interval = (end1-start1) - (end2-start2);
	
	if (0 > interval)
	{
		printf("Bubble Sort is faster than qsort\n");
	}
	else if (0 < interval)
	{
		printf("qsort is faster than Bubble Sort\n");
	}
	else
	{
		printf("qsort and Bubble Sort has equal run time\n");
	}
}


static void TestInsertionSortNonfunctional()
{
	int arr1[5000] = {0};
	int arr2[5000] = {0};
	clock_t start1 = 0, end1 = 0, start2 = 0, end2 = 0, interval = 0;
	
	CreateArr(arr1, 5000);
	
	CopyArr(arr1, arr2, 5000);
	
	start1 = clock();
	InsertionSort(arr1, 5000);
	end1 = clock();
	
	start2 = clock();
	qsort(arr2, 5000, sizeof(int), Compare);
	end2 = clock();
	
	interval = (end1-start1) - (end2-start2);
	
	if (0 > interval)
	{
		printf("Bubble Sort is faster than qsort\n");
	}
	else if (0 < interval)
	{
		printf("qsort is faster than Bubble Sort\n");
	}
	else
	{
		printf("qsort and Bubble Sort has equal run time\n");
	}
}


static void CreateArr(int *arr, size_t size)
{
	size_t i = 0;
	
	srand(time(0));
	
	for ( ; i < size; i++)
	{
		arr[i] = rand() % 5000; 
	} 
}


static int Compare(const void *var1, const void *var2)
{
	return *(int*)var1 - *(int*)var2;
}

static void CopyArr(int *source, int *target, size_t size)
{
	size_t i = 0;
	
	for( ; i < size; ++i)
	{
		target[i] = source[i];
	}
}

