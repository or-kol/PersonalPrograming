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