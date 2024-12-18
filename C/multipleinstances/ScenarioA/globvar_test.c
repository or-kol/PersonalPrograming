#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>

#include "globvar.h"

int x = 30;

int main()
{
	void *handle1;
	void * sym;
	handle1 = dlopen("./lib_globvar.so", RTLD_LAZY | RTLD_GLOBAL);
	if (NULL == handle1)
	{
		printf("handle1 error\n");
	}
	
	sym = dlsym(handle1, "x");
	
	printf("%d\n", *(int *)sym);
	printf("%p\n", (void *)sym);
	
	printf("%d\n", x);
	printf("%p\n", (void *)&x);
	
	if (0 != dlclose(handle1))
	{
		printf("handle1 close error\n");
	}
	
	return 0;
}
