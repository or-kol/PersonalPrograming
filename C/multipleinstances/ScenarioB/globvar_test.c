#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>

#include "globvar.h"



int main()
{
	void *handle1;
	void * sym1;
	
	
	
	handle1 = dlopen("./lib_globvar.so", RTLD_LAZY | RTLD_GLOBAL);
	if (NULL == handle1)
	{
		printf("handle1 error\n");
	}
	printf("%p\n", (void *)&x);
	sym1 = dlsym(handle1, "x");
	
	printf("%p\n", (void *)sym1);
	
	if (0 != dlclose(handle1))
	{
		printf("handle1 close error\n");
	}
	
	return 0;
}
