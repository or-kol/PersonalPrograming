

sll_iterator_t SLLFindNthFromLast(const sll_t *sll, size_t n)
{
	sll_iterator_t iter = SLLBegin(sll);
	sll_iterator_t arr[n];
	size_t i = 0, lst_size = 0;
	
	assert(NULL != sll);
	
	while (NULL != iter->next)
	{
		arr[i] = iter;
		iter = SLLNext(iter);
		++i;
		++lst_size;
		
		if (i == n)
		{
			i = 0;
		}
	}
	
	return arr[lst_size % n];
}

