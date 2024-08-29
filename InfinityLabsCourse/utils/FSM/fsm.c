#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct State State_t;
typedef State_t *(*StateEventHandler)(State_t *state, char c);


struct State
{
    const char *name;
    StateEventHandler event;
};


State_t *S1(State_t *state, char input);
State_t *S2(State_t *state, char input);
State_t *Invalid(State_t *state, char input);


State_t locked = {"Locked", S1};
State_t unlocked = {"Unlocked", S2};
State_t invalid = {"Invalid", Invalid};


State_t *S1(State_t *state, char input)
{
	if ('0' == input)
	{
		return &unlocked;
	}
	else
	{
		return &invalid;
	}
}


State_t *S2(State_t *state, char input)
{
	if ('0' == input)
	{
		return &unlocked;
	}
	else if ('1' == input)
	{
		return &unlocked;
	}
	else
	{
		return &invalid;
	}
}


State_t *Invalid(State_t *state, char input)
{
	return &invalid;
}


int IsAccepted(char *input)
{
	State_t *current_state = &locked;
	int i = 0, length = 0;
	char digit = 0;
	
	for ( ; input[i] != '\0'; ++i)
	{
		digit = input[i];
		current_state = current_state->event(current_state, digit);
		length++;
	}
	
	if (current_state == &unlocked && length >= 2 && input[0] == '0' && input[length - 1] == '0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	char *test_strings[] = {"00", "01110", "0101010", "0", "01", "10001", "101010", NULL};

	int i = 0;

	for ( ; test_strings[i] != NULL; ++i)
	{
		if (1 == IsAccepted(test_strings[i]))
		{
			printf("The string \"%s\" is accepted.\n", test_strings[i]);
		}
		else
		{
			printf("The string \"%s\" is NOT accepted.\n", test_strings[i]);
		}
	}
	
	return 0;
}

