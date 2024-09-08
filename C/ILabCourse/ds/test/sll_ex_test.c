#include <stdio.h> /* print */

#include "sll_ex.h"

int main()
{
	node_t *head = NULL;
	node_t *head2 = NULL;
	
	insert(&head, 20);
	insert(&head, 4);
	insert(&head, 15);
	insert(&head, 85);
	
	printf("Original list\n");
	printList(head);
	
	reverse(&head);
	printf("Reversed list\n");
	printList(head);
	
	if (detectLoop(head))
	{
		printf("Loop found\n");
	}
	else
	{
		printf("No Loop\n");
	}
	
	head->next->next->next = head;
	
	if (detectLoop(head))
	{
		printf("Loop found\n");
	}
	else
	{
		printf("No Loop\n");
	}
	
	
	insert(&head2, 12);
	insert(&head2, 13);
	insert(&head2, 1);
	insert(&head2, 33);
	insert(&head2, 44);
	
	head->next->next->next = head2->next;
	
	if (33 == GetIntersectionNode(head, head2)->data)
	{
		printf("Intersection node found\n");
	}
	
	
	return 0;
}

