#include <stdio.h> /* print */

#include "ws12.h"


int main() {
	char str1[] = "Hello World, Hello World, Hello World, Hello World";
	
	char *str2 = "Etaoin shrdlu, Etaoin shrdlu";
	
	char str3[] = "Hello World, Hello World, Hello World, Hello World";
	
	char str4[] = "Hello World, Hello World, Hello World, Hello World";
	
	const char *str5 = "Etaoin shrdlu, Etaoin shrdlu";
	
	MemSet(str3, 'c', 20);
	printf("main1: %s\n", str3);
	
	MemCpy(str1, str2, 12);
	printf("main2: %s\n", str1);
	
	MemMove(str4, (str4 + 5), 12);
	printf("main3: %s\n", str4);
	
	return 0;
}
