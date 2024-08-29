
int detectLoop(node_t *list, node_t *looped)
{
	node_t *slow_ptr = list
	node_t *fast_ptr = list;
	
	while (NULL != slow_ptr && NULL != fast_ptr && NULL != fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		
		if (slow_ptr == fast_ptr)
		{
			looped = slow_ptr;
			return 1;
		}
	}
	
	return 0;
}


void RemoveSLLLoop(node * head, node *looped)
{
	int count = 0, i = 0;
	
	node *node1 = looped;
	node *node2 = looped;
	
	while (node1 != node2)
	{
		node1 = node1->next;
		++count;
	}
	
	node1 = head;
	
	while (node1 != node2)
	{
		node1 = node1->next;
		node2 = mode2->next;
	}
	
	while (node2->next != node1)
	{
		node2 = node2->next;
	}
	
	node2->next = NULL;
	
	
	
}
