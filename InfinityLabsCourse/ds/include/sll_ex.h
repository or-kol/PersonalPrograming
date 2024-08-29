#ifndef __SLL_EX_H__
#define __SLL_EX_H__

typedef struct node node_t;

struct node
{
	int data;
	node_t *next;
};

int insert(node_t** head, int new_data);

void printList(node_t* head);

void reverse(node_t **head_ref);

int detectLoop(node_t *list);

node_t *GetIntersectionNode(node_t *head1, node_t *head2);

#endif /*__SLL_H__*/
