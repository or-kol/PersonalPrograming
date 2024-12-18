#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>

#include "globvar.h"

int main()
{
	void (*Foo)();
	void (*Foo2)();
	void *handle1;
	void *handle2;
	
	handle1 = dlopen("lib2_dynamic.so", RTLD_LAZY | RTLD_GLOBAL);
	if (NULL == handle1)
	{
		printf("handle1 error\n");
	}
	
	handle2 = dlopen("lib2_dynamic2.so", RTLD_LAZY);
	if (NULL == handle2)
	{
		printf("handle2 error\n");
	}
	
	Foo = (void (*)())dlsym(handle1, "Foo");
	Foo2 = (void (*)())dlsym(handle2, "Foo2");
	
	Foo();
	Foo2();
	
	if (0 != dlclose(handle1))
	{
		printf("handle1 close error\n");
	}
	
	if (0 != dlclose(handle2))
	{
		printf("handle2 close error\n");
	}
	
	return 0;
}


