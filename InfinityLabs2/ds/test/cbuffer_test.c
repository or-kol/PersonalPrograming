#include <stdio.h> /* print */
#include <string.h> /* memcmp */


#include "cbuffer.h"



int main()
{
	char str1[] = "Hello World";
	char str2[] = "My name is Or";
	char read1[20] = "iiiiiiiiiiiiiiiiiiii";
	
	ssize_t write = 0;
	ssize_t read = 0;
	
	cbuffer_t *cbuff1 = CBufferCreate(15);
	
	if (1 == CBufferIsEmpty(cbuff1))
	{
		printf("Is empty <empty> success\n");
	}
	
	CBufferWrite(cbuff1, 5, str1);
	
	write = CBufferWrite(cbuff1, 5, str2);
	
	if (5 == CBufferFreeSpace(cbuff1))
	{
		printf("Free space success\n");
	}
	
	read = CBufferRead(cbuff1, 10, read1);
	
	if (0 == memcmp("HelloMy na", read1, 10) && 5 == write && 10 == read)
	{
		printf("Create success\n");
		printf("Write success\n");
		printf("Read success\n");
	}
	
	if (15 == CBufferBufSize(cbuff1))
	{
		printf("BufSize success\n");
	}
	
	CBufferWrite(cbuff1, 10, str2);
	
	if (0 == CBufferIsEmpty(cbuff1))
	{
		printf("Is empty <not empty> success\n");
	}
	
	if (5 == CBufferFreeSpace(cbuff1))
	{
		printf("Free space success\n");
	}
	
	
	CBufferDestroy(cbuff1);
	
	return 0;
}
