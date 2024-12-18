#include <stdio.h>


#include "globvar.h"

int x = 10;



/*
gd -c globvar.c -fPIC
ar rcs lib_globvarstatic.a globvar.o

gd -c dynamic.c -fPIC
gd -c dynamic2.c -fPIC

gd dynamic.o -shared -o lib2_dynamic.so -fPIC -Wl,--whole-archive lib_globvarstatic.a -Wl,--no-whole-archive
gd dynamic2.o -shared -o lib2_dynamic2.so -fPIC -Wl,--whole-archive lib_globvarstatic.a -Wl,--no-whole-archive

gcc -o dynamic12.exe dynamic12_test.c -ldl


gd -o dynamic12.exe dynamic12_test.c -L/home/or-kol/multipleinstances lib2_dynamic.so lib2_dynamic2.so
*/
