#include <stdio.h> /* print */
#include <stdlib.h> /* stty */

#include "ws6.h"


int main() {
	
	typedef int NEWINT;
	typedef char NEWCHAR;
	typedef float NEWFLOAT;
	typedef double NEWDOUBLE;

	typedef int (*FuncRetInt)();
	
	typedef void (*FUNCPTR)();
	
	typedef void (*FUNCPTRARR[256])();
	
	typedef int (*INTARROFTEN)[10];
	
	
	void (*a_press_ptr)() = &APressed; 
	void (*t_press_ptr)() = &TPressed;
	void (*Null_press_ptr)() = &NullPressed;
	FUNCPTRARR press_func;
	int n = 0;
	
	
	system ("stty -icanon -echo");
	ATPressedIf();
	puts("If test is done\n");
	
	ATPressedSwitch();
	printf("Switch test is done\n");
	
	while(256 > n)
	{
		press_func[n] = Null_press_ptr;
		++n;
	}
	press_func[65] = a_press_ptr;
	press_func[97] = a_press_ptr;
	press_func[84] = t_press_ptr;
	press_func[116] = t_press_ptr;
	

	ATPressedLUT(press_func);
	printf("LUT test is done\n");
	
	system ("stty icanon echo");
	
	return 0;
}
