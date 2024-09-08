#include <assert.h> /* assert */

#include "ws12.h"


#define WORD_SIZE (sizeof(size_t))


static int WordAllign(char *pdest);
static void PassCharPerByte(char *pdest, int c, int loops);
static void PassPerByte(char *pdest, char *psrc, int loops);
static void PassPerWordSet(char *pdest, char *psrc, int loops);
static void PassPerWordCpy(char *pdest, char *psrc, int loops);
static void PassPerByteRev(char *pdest, const char *psrc, int loops);
static void PassPerWordRev(char *pdest, const char *psrc, int loops);



void *MemSet(void *dest, int c, size_t n)
{
	int allignment = WordAllign(dest), words = ((n - allignment)/ WORD_SIZE), 
		words_rest = (n % WORD_SIZE) - allignment;
	size_t i = 0;
	char *pdest = dest;
	char word[WORD_SIZE] = {0};
	
	assert(NULL != dest);
	
	if (allignment != 0)
	{
		PassCharPerByte(pdest, c, (WORD_SIZE - allignment));
		pdest += (WORD_SIZE - allignment);
	}
	
	if (0 < words)
	{
		for (i = 0; i < WORD_SIZE; ++i)
		{
			word[i] = c;
		}
	}
	
	PassPerWordSet(pdest, word, words);
	pdest += WORD_SIZE * words;
	
	PassCharPerByte(pdest, c, words_rest);
	
	return dest;
}


void *MemCpy(void* dest, void* src, size_t size)
{
	char *pdest = dest;
	char *psrc = src;
	int allignment = WordAllign(dest), words = ((size - allignment)/ WORD_SIZE), 
		words_rest = (size % WORD_SIZE) - allignment;
	
	assert(NULL != dest);
	assert(NULL != src);
	
	if (allignment != 0)
	{
		PassPerByte(pdest, psrc, allignment);
		pdest += allignment;
		psrc += allignment;
	}
	
	PassPerWordCpy(pdest, psrc, words);
	pdest += WORD_SIZE * words;
	psrc += WORD_SIZE * words;
	
	PassPerByte(pdest, psrc, words_rest);
	
	return dest;
}


void *MemMove(void *dest, const void *src, size_t n)
{
	char *pdest = dest;
	char *psrc = (char *)src;
	int allignment = WordAllign(pdest), words = ((n - allignment)/ WORD_SIZE), 
		words_rest = ((n % WORD_SIZE) - allignment);
	
	assert(NULL != dest);
	assert(NULL != src);
	
	if (pdest < psrc)
	{
		MemCpy(pdest, psrc, n);
	}
	else
	{	
		pdest += n-1;
		psrc += n-1;
		
		PassPerByteRev(pdest, psrc, (words_rest - allignment));
		pdest -= (words_rest - allignment) -1;
		psrc -= (words_rest - allignment) -1;
		
		PassPerWordRev(pdest, psrc, words);
		pdest -= WORD_SIZE * words;
		psrc -= WORD_SIZE * words;
		
		if (allignment != WORD_SIZE)
		{
			PassPerByteRev(pdest, psrc, allignment);
		}
		
	}
	
	return dest;
}



static int WordAllign(char *pdest)
{
	unsigned long int ulpdest = (unsigned long int)pdest;
	return ulpdest % WORD_SIZE;
}


static void PassCharPerByte(char *pdest, int c, int loops)
{
	int i = 0;
	
	for (i = 0; i < loops; ++i)
	{
		*pdest = c;
		++pdest;
	}
}


static void PassPerByte(char *pdest, char *psrc, int loops)
{
	int i = 0;
	
	for (i = 0; i < loops; ++i)
	{
		*pdest = *psrc;
		++pdest;
		++psrc;
	}
}


static void PassPerWordSet(char *pdest, char *psrc, int loops)
{
	int i = 0;
	
	for(i = 0; i < loops; ++i)
	{
		*(size_t*)pdest = *(size_t*)psrc;
		pdest += WORD_SIZE;	
	}
}


static void PassPerWordCpy(char *pdest, char *psrc, int loops)
{
	int i = 0;
	
	for(i = 0; i < loops; ++i)
	{
		*(size_t*)pdest = *(size_t*)psrc;
		pdest += WORD_SIZE;
		psrc += WORD_SIZE;	
	}
}


static void PassPerByteRev(char *pdest, const char *psrc, int loops)
{
	int i = 0;
	
	for (i = loops; i > 0; --i)
	{
		*pdest = *psrc;
		--pdest;
		--psrc;	
	}
}


static void PassPerWordRev(char *pdest, const char *psrc, int loops)
{
	int i = 0;
	
	for(i = loops; i > 0; --i)
	{
		pdest -= WORD_SIZE;
		psrc -= WORD_SIZE;
		*(size_t*)pdest = *(size_t*)psrc;	
	}
}










