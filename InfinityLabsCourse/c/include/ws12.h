#ifndef __WS12_H__
#define __WS12_H__

#include <stdio.h>

void *MemSet(void *dest, int c, size_t n);

void *MemCpy(void *dest, void *src, size_t size);

void *MemMove(void *dest, const void *src, size_t n);

#endif 
/*__WS12_H__*/
