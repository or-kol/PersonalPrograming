#include <string.h> /* strcmp */
#include <stdlib.h> /* enum */
#include <stdio.h> /* FILE */

#include "ws7.h"

#define PRINT_ARR_SIZE (10)
#define MAX_STR_SIZE (200)
#define MAX_COMM_SIZE (10)
#define STRUCT_ARR_SIZE (4)

/* CODE REVIEW BY DVIR */

typedef int (*chain)(const char file_name[], char user_input_arr[], FILE *fptr);

typedef struct print_num_t
{
	int number;
	void (*print_ptr)(int);
} print_num_t;

typedef struct chain_struct_t
{
	char command[MAX_COMM_SIZE];
	chain take;
	int (*pass_ptr)(char *user_input_ptr, char command_str[], size_t command_str_size);
} chain_struct_t;



static void PrintInt(int x)
{
	printf("%d\n", x);
}

void PrintStructArr()
{
	int i = 0;
	print_num_t print_arr[PRINT_ARR_SIZE];
	
	for ( ; i < PRINT_ARR_SIZE; ++i)
	{	
		print_arr[i].number = i;
		print_arr[i].print_ptr = PrintInt;
		
		print_arr[i].print_ptr(print_arr[i].number);
	}
}


static int Append(const char file_name[], char user_input_arr[], FILE *fptr)
{
	fptr = fopen(file_name, "a");
	if (NULL == fptr)
	{
		return OPEN_FAILED;
	}
		
	fputs(user_input_arr, fptr);
	
	if (0 != fclose(fptr))
	{
		return CLOSE_FAILED;
	}
	
	return SUCCESS;
}


static int RemoveFile(const char file_name[], char user_input_arr[], FILE *fptr)
{
	(void)fptr;
	(void)user_input_arr;
	
	if (0 != remove(file_name))
	{
		return REMOVE_FAILED;
	}
	return REMOVE;
}


static int Count_Rows(const char file_name[], char user_input_arr[], FILE *fptr)
{
	char c = 0;
	int lines = 0;
	
	(void)user_input_arr;
	
	fptr = fopen(file_name, "r");
	if (NULL == fptr)
	{
		return OPEN_FAILED;
	}
	
	while (c != EOF)
	{
		c = fgetc(fptr);
		if (c == '\n')
		{
			++lines;
		}
	}
	
	if (0 != fclose(fptr))
	{
		return CLOSE_FAILED;
	}
	
	printf("%d lines in the file", lines);
	
	return SUCCESS;
}



static void CopyToFile(FILE *fptrfrom, FILE *fptrto)
{
	char c = 0;
	
	rewind(fptrfrom);
	rewind(fptrto);
	
	while (c != EOF)
	{
		c = fgetc(fptrfrom);
		fputc(c, fptrto);
	}
}


static int AddAtBgin(const char file_name[], char user_input_arr[], FILE *fptr)
{
	FILE *fptrcopy;
	
	fptr = fopen(file_name, "r+");
	if (NULL == fptr)
	{
		return OPEN_FAILED;
	}
	
	fptrcopy = fopen("../../temp.txt", "a+");
	if (NULL == fptrcopy)
	{
		return OPEN_FAILED;
	}
	
	fputs(++user_input_arr, fptrcopy);
	
	CopyToFile(fptr, fptrcopy);
		
	CopyToFile(fptrcopy, fptr);
	
	if (0 != fclose(fptrcopy))
	{
		return CLOSE_FAILED;
	}
	
	if (0 != remove("../../temp.txt"))
	{
		return REMOVE_FAILED;
	}
	
	if (0 != fclose(fptr))
	{
		return CLOSE_FAILED;
	}
	
	return ADD_BEGINNING;
}


static int CompareFunc(char *user_input_ptr, char command_str[], size_t command_str_size)
{
	int i = 0;
	i = strncmp(user_input_ptr, command_str, command_str_size);
	return i;
}


static int Exit()
{
	return EXIT_OPERATION;
}


int Logger(const char file_name[])
{
	char user_input_arr[MAX_STR_SIZE];
	char command_str[MAX_COMM_SIZE];
	int status = 1;
	size_t i = 0, command_str_size = 0;
	
	static chain_struct_t arr[STRUCT_ARR_SIZE] = {
		{"-remove\n", &RemoveFile, &CompareFunc},
		{"-count\n", &Count_Rows, &CompareFunc},
		{"-exit\n", &Exit, &CompareFunc},
		{"<", &AddAtBgin, &CompareFunc}
	};
	
	FILE *fptr;
	
	while (0 < status)
	{
		fgets(user_input_arr, MAX_STR_SIZE, stdin);
		
		for (i = 0; i < STRUCT_ARR_SIZE; i++)
		{
			strcpy(command_str, arr[i].command);
			command_str_size = strlen(arr[i].command);
			if (0 == arr[i].pass_ptr(user_input_arr, command_str, command_str_size))
			{
				status = arr[i].take(file_name, user_input_arr, fptr);
				break;
			}
		}
		
		if (EXIT_OPERATION == status)
		{
			break;
		}
		
		if (STRUCT_ARR_SIZE == i)
		{
			status = Append(file_name, user_input_arr, fptr);
			printf("status: %d\n", status);
		}
	}
	
	return status;
}







