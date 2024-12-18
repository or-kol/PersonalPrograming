#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>

#include "globvar.h"



int main()
{
	void *handle1;
	void * sym1;
	void *handle2;
	void * sym2;
	
	printf("%p\n", (void *)&x);
	
	handle1 = dlopen("./lib_globvarB.so", RTLD_LAZY);
	if (NULL == handle1)
	{
		printf("handle1 error\n");
	}
	
	sym1 = dlsym(handle1, "x");
	
	printf("%p\n", (void *)sym1);
	
	if (0 != dlclose(handle1))
	{
		printf("handle1 close error\n");
	}
	
	handle2 = dlopen("./lib_globvarA.so", RTLD_LAZY);
	if (NULL == handle2)
	{
		printf("handle1 error\n");
	}
	
	sym2 = dlsym(handle2, "x");
	
	printf("%p\n", (void *)sym2);
	
	if (0 != dlclose(handle2))
	{
		printf("handle1 close error\n");
	}
	
	return 0;
}
