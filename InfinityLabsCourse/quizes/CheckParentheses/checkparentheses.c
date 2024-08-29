#include <string.h>
#include <stdio.h>

#include "stack.h"

int ParenthesesBalanced(char* expression, stack_t *stack)
{
	int i = 0;
	
	for ( ; (size_t)i < strlen(expression); i++)
	{
		char current = expression[i];
		
		switch (current)
		{
			case '(':
			case '[':
			case '{':
				StackPush((void *)current, stack);
				break;
			case ')':
				if (StackIsEmpty(stack) || *(char *)StackPeek(stack) != '(')
				{
					return 0;
				}
				StackPop(stack);
				break;
			case ']':
				if (StackIsEmpty(stack) || *(char *)StackPeek(stack) != '[')
				{
					return 0;
				}
				StackPop(stack);
				break;
			case '}':
				if (StackIsEmpty(stack) || *(char *)StackPeek(stack) != '{')
				{
					return 0;
				}
				StackPop(stack);
				break;
		}
	}
	
	return StackIsEmpty(stack);
}


int main()
{
	char *par1 = "(({{}}))[()]";
	char *par2 = "(({{}})[()]";
	
	stack_t *stack = StackCreate(20, 1);
	
	if (1 == ParenthesesBalanced(par1, stack) && 0 == ParenthesesBalanced(par2, stack))
	{
		printf("Success");
	}
	
	StackDestroy(stack);
}

