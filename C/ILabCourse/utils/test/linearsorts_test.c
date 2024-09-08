#include <stddef.h> /* size_t */
#include <stdio.h> /* print */
#include <time.h> /* time */
#include <stdlib.h> /* rand */



#include "linearsorts.h"


static void TestCountSort();
static void TestRadixSort();

static void CreateCountingArr(int *arr, size_t size);
static void CreateRadixArr(int *arr, size_t size);

int main()
{
	
	TestCountSort();
	TestRadixSort();
	
	return 0;
}


static void TestCountSort()
{
	int arr[5000] = {0};
	size_t i = 1;
	
	CreateCountingArr(arr, 5000);
	
	CountSort(arr, 5000);
	
	while(arr[i] >= arr[i - 1] && i < 5000)
	{
		++i;
	}
	
	if (5000 == i)
	{
		printf("Count Sort Success\n");
	}
	else
	{
		printf("Count Sort Fail\n");
	}

}


static void TestRadixSort()
{
	int arr[10] = {0};
	size_t i = 1;
	
	CreateRadixArr(arr, 10);
	
	RadixSort(arr, 10);
	
	while(arr[i] >= arr[i - 1] && i < 10)
	{
		++i;
	}
	
	if (10 == i)
	{
		printf("Radix Sort Success\n");
	}
	else
	{
		printf("Radix Sort Fail\n");
	}

}


static void CreateCountingArr(int *arr, size_t size)
{
	size_t i = 0;
	
	srand(time(0));
	
	for ( ; i < size; i++)
	{
		arr[i] = (rand() % 100) + 1; 
	} 
}


static void CreateRadixArr(int *arr, size_t size)
{
	size_t i = 0;
	
	srand(time(0));
	
	for ( ; i < size; i++)
	{
		arr[i] = (rand() % (9999999 - 1000000)) + 1000000; 
	} 
}




