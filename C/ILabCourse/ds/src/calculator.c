#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "calculator.h"
#include "stack.h"

#define MAX_SIZE 100

typedef struct handler handler_t;
/*typedef enum state state_t;*/
typedef struct stacks_struct stacks_t;
/*
enum state {
    INVALID,
    STATE_EXPECT_OPERAND,
    STATE_EXPECT_OPERATOR
};
*/
typedef status_t (*operator_func)(double a, double b, double *res);
typedef status_t (*get_operator_func)(stacks_t stacks, char *math_exp);
typedef handler_t *(*handler_func)(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr);

static status_t Add(double a, double b, double *res);
static status_t Subtract(double a, double b, double *res);
static status_t Multiply(double a, double b, double *res);
static status_t Divide(double a, double b, double *res);
static status_t Power(double a, double b, double *res);
static int precedence(char op);
static void InitOperationLUT();
static void InitOperatorLUT();
static status_t FillStacks(char *math_exp, stacks_t stacks);
static status_t OpenParentheses(stacks_t stacks, char *math_exp);
static status_t ClosedParentheses(stacks_t stacks, char *math_exp);
static status_t Operator(stacks_t stacks, char *math_exp);

handler_t *GetOperand(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr);
handler_t *GetOperator(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr);
handler_t *Invalid(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr);


struct handler
{
    const char *name;
    handler_func event;
};

struct stacks_struct {
    stack_t *operand_stack;
    stack_t *operator_stack;
};

handler_t get_operand = {"Get Operand", GetOperand};
handler_t get_operator = {"Get Operator", GetOperator};
handler_t invalid = {"Invalid", Invalid};

operator_func operationLUT[256];

get_operator_func operatorLUT[256];

static void InitOperationLUT()
{
    operationLUT['+'] = Add;
    operationLUT['-'] = Subtract;
    operationLUT['*'] = Multiply;
    operationLUT['/'] = Divide;
    operationLUT['^'] = Power;
}

static void InitOperatorLUT()
{
    operatorLUT['+'] = Operator;
    operatorLUT['-'] = Operator;
    operatorLUT['*'] = Operator;
    operatorLUT['/'] = Operator;
    operatorLUT['^'] = Operator;
    operatorLUT['('] = OpenParentheses;
    operatorLUT[')'] = ClosedParentheses;
}

handler_t *GetOperand(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr)
{
    double num = 0;
    if (1 == isdigit(*math_exp) || *math_exp == '-')
	{
        num = strtod(math_exp, &ptr);
        StackPush((char *)&num, stacks.operand_stack);
		math_exp = ptr;
        return &get_operator;
	}
    else if('(' == *math_exp)
    {
        return &get_operator;
    }
    else
    {
        return &invalid;
    }
}


static status_t OpenParentheses(stacks_t stacks, char *math_exp)
{
    char operator = *math_exp;
    StackPush((char *)&operator, stacks.operand_stack);
    return SUCCESS;
}


static status_t ClosedParentheses(stacks_t stacks, char *math_exp)
{
    return SUCCESS;
}


static status_t Operator(stacks_t stacks, char *math_exp)
{
    char operator = *math_exp;
    char operator2 = '\0';
    if (precedence(*(char *)StackPeek(stacks.operator_stack)) <= precedence(*math_exp))
    {
        StackPush(&operator, stacks.operator_stack);
        ++math_exp;
        return SUCCESS;
    }
    else 
    {
        while (precedence(*(char *)StackPeek(stacks.operator_stack)) > precedence(*math_exp))
        {
            operator = *(char *)StackPeek(stacks.operator_stack);
            StackPush(StackPeek(stacks.operator_stack), stacks.operand_stack);
            StackPop(stacks.operator_stack);
        }
        StackPush((char *)&operator, stacks.operand_stack);        
        ++math_exp;
        return SUCCESS;
    }
}


handler_t *GetOperator(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr)
{
    if (0 == isdigit(*math_exp))
	{
		int operator = *math_exp;

        operatorLUT[operator](stacks, (char *)&operator);

        if (operator == ')')
        {
            return &get_operator;
        }
        else
        {
            return &get_operand;
        }
    }   
    else
    {
        return &invalid;
    }
}   


handler_t *Invalid(handler_t *handler, stacks_t stacks, char *math_exp, char *ptr)
{
	return &invalid;
}


static status_t Add(double a, double b, double *res)
{
    *res = a + b;
    return SUCCESS;
}


static status_t Subtract(double a, double b, double *res)
{
    *res = a - b;
    return SUCCESS;
}


static status_t Multiply(double a, double b, double *res)
{
    *res = a * b;
    return SUCCESS;
}


static status_t Divide(double a, double b, double *res)
{
    if (0 == b)
    {
        return DIV_ZERO;
    }

    *res = a / b;

    return SUCCESS;
}


static status_t Power(double a, double b, double *res)
{
    *res = pow(a, b);
    return SUCCESS;
}


static int precedence(char op)
{
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : (op == '^') ? 3 : 0;
}


static status_t FillStacks(char *math_exp, stacks_t stacks)
{
    char *ptr = NULL;
    handler_t *handler = &get_operand;

    while ('\0' != *math_exp && handler != &invalid)
    {
		if (1 == isspace(*math_exp))
		{
			++math_exp;
			continue;
		}
        
        if (*math_exp == '(')
        {
            handler = &get_operator;
        }

        handler = handler->event(handler, stacks, math_exp, ptr);
    }

    return handler == &invalid ? INVALID_INPUT : SUCCESS;
}


status_t Calculator(const char *math_exp, double *result)
{
    stacks_t stacks;
    double a = 0, b = 0 , res = 0;
    int operator = '\0';
    status_t status;

    stacks.operand_stack = StackCreate(MAX_SIZE, sizeof(double));
    stacks.operator_stack = StackCreate(MAX_SIZE, sizeof(char));
    

    if(NULL == stacks.operand_stack)
    {
        return ALLOC_FAIL;
    }
    
    if(NULL == stacks.operator_stack)
    {
        return ALLOC_FAIL;
    }

    InitOperationLUT();
    InitOperatorLUT();
    
    FillStacks((char *)math_exp, stacks);

    while (0 != StackSize(stacks.operand_stack))
    {
        StackPush(StackPeek(stacks.operand_stack), stacks.operator_stack);
        StackPop(stacks.operand_stack);
    }

    while (0 == StackIsEmpty(stacks.operator_stack) && status == SUCCESS)
    {
        
        if (0 == isdigit(*(char *)StackPeek(stacks.operator_stack)))
        {
            operator = *(char *)StackPeek(stacks.operator_stack);
            StackPop(stacks.operator_stack);

            b = *(double *)StackPeek(stacks.operand_stack);
            StackPop(stacks.operand_stack);

            a = *(double *)StackPeek(stacks.operand_stack);
            StackPop(stacks.operand_stack);

            status = operationLUT[operator](a, b, &res);
            StackPush(&res, stacks.operand_stack);
        }
        else
        {
            StackPush(StackPeek(stacks.operator_stack), stacks.operand_stack);
            StackPop(stacks.operator_stack);
        }
    }

    *result = *(double *)StackPeek(stacks.operand_stack);

    return status;
}


/*
typedef enum status {
    SUCCESS,
    INVALID_INPUT,
    DIV_ZERO,
    DOUBLE_OVERFLOW,
    ALLOC_FAIL
    } status_t;
*/