#include <stdint.h> /* intptr_t */
#include <stdio.h> /* print */
#include <string.h> /* strcpy */
#include <stdlib.h> /* realloc */


#include "ws10.h"

#define MAX_NUM_LEN (10)

/* print functions*/
static void PrintInt(element_t *el)
{
	printf("%d\n", *(int*)&el->data);
}


static void PrintFloat(element_t *el)
{
        printf("%f\n", *(float*)&el->data);
}


static void PrintString(element_t *el)
{
	printf("%s\n", (char *)el->data);
}



/* Add functions*/
static int AddInt(element_t *el, int add_int)
{
	*(int*)&el->data += add_int;
	
	return SUCCESS;
}


static int AddFloat(element_t *el, int add_int)
{
	*(float*)&el->data += add_int;
	return SUCCESS;

	
}


static int AddString(element_t *el, int add_int)
{
	size_t data_len = strlen((char*)el->data) + 1;

	char* temp = NULL;
	
	temp = (char*)realloc(el->data, (MAX_NUM_LEN + data_len));
	if(NULL == el->data)
	{
		return REALLOC_ERROR;
	}
	el->data = temp;
	
	sprintf((char*)el->data+data_len, "%d", add_int);

	return SUCCESS;
	
	
}



/* Clean functions*/
static void CleanNotNeeded(element_t *el)
{
	(void)el;
}


static void CleanString(element_t *el)
{
	free(el->data);
	el->data = NULL;
}


funcs_t funcs_int = {&AddInt, &PrintInt, &CleanNotNeeded};
funcs_t funcs_float = {&AddFloat, &PrintFloat, &CleanNotNeeded};
funcs_t funcs_string = {&AddString, &PrintString, &CleanString};



/* Init functions */
void InitInt(int x, element_t *el)
{
	*(int*)&el->data = x; 
	el->funcs = &funcs_int;
}


void InitFloat(float f, element_t *el)
{
	*(float*)&el->data = f; 
	el->funcs = &funcs_float;
}


int InitString(char *s, element_t *el)
{
	int s_len = strlen(s) + 1;
	el->data = (char *)malloc((s_len * sizeof(char)) + 1);
        if (NULL == el->data)
        {
                return MALLOC_ERROR;
        }
        
        strcpy(el->data, s);
	
	el->funcs = &funcs_string;
	
	return SUCCESS;
}



/* User functions */
void PrintAll(element_t *arr, int num_of_elements)
{
	int i = 0;
	for ( ; i < num_of_elements; ++i)
	{
		arr->funcs->print(arr);
		++arr;
	}
}


int AddAll(element_t *arr, int num_of_elements, int to_add)
{
	int i = 0;
	enum status status = SUCCESS;
	for ( ; i < num_of_elements; ++i)
	{
		status = arr->funcs->add(arr, to_add);
		if (status != SUCCESS)
		{
			break;
		}
		++arr;
	}
	return status;
}


void CleanAll(element_t *arr, int num_of_elements)
{
	int i = 0;
	for ( ; i < num_of_elements; ++i)
	{
		arr->funcs->clean(arr);
		++arr;
	}
}











