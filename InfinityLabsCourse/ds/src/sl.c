/****************************************************
* FILE NAME : sl.c
*
* PURPOSE : Functions sorted list.
*
* MAINTAINER: Or Kol
*
* Reviewer: Raz
*
* LAST UPDATED : 18/07/2024
****************************************************/

#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */


#include "sl.h"
#include "dll.h"

struct sl
{
	dll_t* list;
	compare_func_t compare_func;
};

typedef struct sruct_find sruct_find_t;
	
struct sruct_find
{
	void* data;
	compare_func_t compare_func;
};


static sl_iterator_t ToSLStruct(dll_iterator_t dll_iter ,sl_t *sl);

static dll_iterator_t SortElement(void *data, sl_t *sl);

static int IsMatchStat(const void *val1, const void *val2);


sl_t *SLCreate(compare_func_t compare_func)
{
	sl_t *create_sl = (sl_t *)malloc(sizeof(sl_t));
	if (NULL == create_sl)
	{
		return NULL;
	}
	
	create_sl->list = DLLCreate();
	if (NULL == create_sl->list)
	{
		free(create_sl);
		return NULL;
	}
	
	create_sl->compare_func = compare_func;
	
	return create_sl;
}


void SLDestroy(sl_t *sl)
{
	assert(NULL != sl);
	
	DLLDestroy(sl->list);
	
	free(sl);
}


static dll_iterator_t SortElement(void *data, sl_t *sl)
{
	dll_iterator_t runner = DLLBegin(sl->list); 
	
	while (NULL != DLLNext(runner) && 0 > sl->compare_func(DLLGetData(runner), data))
	{
		runner = DLLNext(runner);
	}
	return runner;
}


sl_iterator_t SLInsert(const void *data, sl_t *sl)
{
	assert(NULL != data);
	assert(NULL != sl);
	
	return ToSLStruct(DLLInsert(SortElement((void *)data, sl), (void *)data, sl->list), sl);

}


sl_iterator_t SLRemove(sl_iterator_t iter, sl_t *sl)
{
	assert(NULL != sl);
	
	iter.dll_iter = DLLRemove(iter.dll_iter, sl->list);
	return iter;
	
}


void *SLGetData(const sl_iterator_t iter)
{	
	return DLLGetData(iter.dll_iter);
}


size_t SLSize(const sl_t *sl)
{
	assert(NULL != sl);
	return DLLSize(sl->list);
}


int SLIsEmpty(const sl_t *sl)
{
	assert(NULL != sl);
	return DLLIsEmpty(sl->list);
}


sl_iterator_t SLBegin(const sl_t *sl)
{
	assert(NULL != sl);
	return ToSLStruct(DLLBegin(sl->list), (sl_t *)sl);
}


sl_iterator_t SLEnd(const sl_t *sl)
{
	assert(NULL != sl);
	return ToSLStruct(DLLEnd(sl->list), (sl_t *)sl);
}


sl_iterator_t SLNext(sl_iterator_t iter)
{
	sl_iterator_t iter_temp = iter;
	iter_temp.dll_iter = DLLNext(iter.dll_iter);
	return iter_temp;
}


sl_iterator_t SLPrev(sl_iterator_t iter)
{
	sl_iterator_t iter_temp = iter;
	iter_temp.dll_iter = DLLPrev(iter.dll_iter);
	return iter_temp;
}


int SLIsEqual(const sl_iterator_t iter1, const sl_iterator_t iter2)
{
	return DLLIsEqual(iter1.dll_iter, iter2.dll_iter);
}


void *SLPopFront(sl_t *sl)
{
	void *data = NULL;
	sl_iterator_t iter = SLBegin(sl);
	
	assert(NULL != sl);
	
	data = SLGetData(iter);
	SLRemove(iter, sl);
	
	return data;
}


void * SLPopBack(sl_t *sl)
{
	void *data = NULL;
	sl_iterator_t iter = SLPrev(SLEnd(sl));
	
	assert(NULL != sl);
	
	data = SLGetData(iter);
	SLRemove(iter, sl);
	
	return data;
}


sl_iterator_t SLFind(sl_iterator_t from, const sl_iterator_t to, void *param, sl_t *sl)
{
	sl_iterator_t iter = from;
	
	sruct_find_t *sruct_find = (sruct_find_t *)malloc(sizeof(sruct_find_t));
	if (NULL == sruct_find)
	{
		return to;
	}
	
	assert(NULL != sl);
	assert(NULL != param);
	assert(from.sl == to.sl);
	
	sruct_find->data = param;
	sruct_find->compare_func = sl->compare_func;
	
	iter.dll_iter = DLLFind(from.dll_iter, to.dll_iter, IsMatchStat, sruct_find);
	
	free(sruct_find);
	
	return iter;
}


sl_iterator_t SLFindCustom(const sl_iterator_t from, const sl_iterator_t to, is_match_t is_match, void *param)
{
	sl_iterator_t iter = from;
	
	assert(NULL != param);
	assert(from.sl == to.sl);
	
	iter.dll_iter = DLLFind(from.dll_iter, to.dll_iter, is_match, param);
	
	return iter;
}


size_t SLForEach(sl_iterator_t from, const sl_iterator_t to, action_t action_func, const void *param)
{
	assert(NULL != param);
	assert(from.sl == to.sl);
	
	return DLLForEach(from.dll_iter, to.dll_iter, action_func, param);
}


sl_iterator_t SLMerge(sl_t *sl_source, sl_t *sl_dest)
{
	dll_iterator_t src = SLBegin(sl_source).dll_iter;
	dll_iterator_t dest = SLBegin(sl_dest).dll_iter;
	dll_iterator_t src_end = SLEnd(sl_source).dll_iter;
	dll_iterator_t dest_end = SLEnd(sl_dest).dll_iter;
	
	assert(NULL != sl_dest);
	assert(NULL != sl_source);
	
	while((src != src_end) && (dest != dest_end))
	{
		if (sl_source->compare_func(DLLGetData(src), DLLGetData(dest)) <= 0)
		{			
			dest = DLLSpliced(src, DLLNext(src), dest);			
			src = SLBegin(sl_source).dll_iter;
		}
		else
		{
			dest = DLLNext(dest);
		}		
	}
	if (src != src_end)
	{
		DLLSpliced(src, src_end, dest);
	}

	return SLBegin(sl_dest);;
}


static sl_iterator_t ToSLStruct(dll_iterator_t dll_iter ,sl_t *sl)
{
	sl_iterator_t iter;
	iter.dll_iter = dll_iter;
	#ifndef NDEBUG
	iter.sl = sl;
	#endif
	return iter;
}




static int IsMatchStat(const void *val, const void *param)
{
	return (0 <= ((sruct_find_t *)(param))->compare_func(val, ((sruct_find_t *)(param))->data));
}



