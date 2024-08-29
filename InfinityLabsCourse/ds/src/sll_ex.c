#include <stdio.h> /* print */
#include <stdlib.h> /* malloc */

#include "sll_ex.h"


/* Push a node */
int insert(node_t** head, int new_data)
{
	node_t *new_node = (node_t*)malloc(sizeof(node_t));
	if (NULL == new_node)
	{
		return 1;
	}
	
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
	
	return 0;
}


/* Print list */
void printList(node_t* head)
{
	node_t* temp = head;
	while (temp != NULL) 
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


/* Reverse list */
void reverse(node_t **head_ref)
{
	node_t *prev = NULL;
	node_t *current = *head_ref;
	node_t *next = NULL;
	
	while (NULL != current)
	{
		/* Store next */
		next = current->next;
		
		/* Reverse current node's pointer */
		current->next = prev;
		
		/* Move pointers one position ahead. */
		prev = current;
		current = next;
	}
	
	*head_ref = prev;
}


/* Detect a loop */
int detectLoop(node_t *list)
{
	node_t *slow_ptr = list
	node_t *fast_ptr = list;
	
	while (NULL != slow_ptr && NULL != fast_ptr && NULL != fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		
		if (slow_ptr == fast_ptr)
		{
			return 1;
		}
	}
	
	return 0;
}


/* find intersection node */
node_t *GetIntersectionNode(node_t *head1, node_t *head2)
{
	node_t *list1 = head1;
	node_t *list2 = head2;
	
	/* Run on both lists till intersection point or NULL */
	while (list1 != list2)
	{
		/* Move p1 to next node */
		list1 = NULL != list1 ? list1->next : head2;
		
		/* Move p2 to next node */
		list2 = NULL != list2 ? list2->next : head1;
	}
	
	/* Return intersection node or NULL if no intersection */
	return list1;
}








