#include <stddef.h> /* NULL */
#include <stdio.h> /* print */
#include <ctype.h> /* tolower */

#include "ws6.h"

/* Reviewed by Raz*/


void ATPressedIf()
{
	char esc = 0;
	
	while (27 != esc)
	{	
		esc = getc(stdin);
		
		if ('a' == tolower(esc))
		{
			printf("A-pressed\n");
		}
		else if ('t' == tolower(esc))
		{
			printf("T-pressed\n");
		}
	}
}


void ATPressedSwitch()
{
	char esc = 0;
	
	while (27 != esc)
	{	
		esc = getc(stdin);
		switch (tolower(esc)) {
			case 'a':
				printf("A-pressed\n");
				break;
			case 't':
				printf("T-pressed\n");
				break;
			case 27:
				break;
			default:
				continue;				
		}
	}
}



void ATPressedLUT(FUNCPTR press_func[])
{
	char esc = 0;
	
	while (27 != esc)
	{	
		esc = getc(stdin);
		press_func[(int)esc]();
	}
}

void APressed()
{
	printf("A-pressed\n");
}

void TPressed()
{
	printf("T-pressed\n");
}

void NullPressed()
{
	return;
}






