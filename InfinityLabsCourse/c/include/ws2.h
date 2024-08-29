#ifndef __WS2_H__
#define __WS2_H__
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void *calloc(size_t nitems, size_t size);

void SwapInt(int *a, int *b);

void CopyIntArray(int *arr_num, int *copied_arr, size_t n);

void PrintVarAddress();

void SwapTwoSize_t(size_t *ptr1, size_t *ptr2);

void SwapTwoPointers(size_t **ptr1, size_t **ptr2);

size_t StrLen(const char * str);

int StrCmp(const char* s1, const char* s2);

#endif 
__WS2_H__

