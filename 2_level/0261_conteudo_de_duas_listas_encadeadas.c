#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node *next;
};

struct node *add_node (struct node *head, int item)
{
	struct node *new_node = (struct node *) malloc (sizeof(struct node));
	new_node->item = item;
	new_node->next = head;

	return new_node;
}

struct node *add_node_list (int i, int n, struct node *list)
{
	if (i < n)
	{
		int item;
		scanf("%d", &item);
		
		list = add_node(list, item);
		
		return add_node_list(i + 1, n, list);
	}
	
	return list;
}

struct node *remove_node (struct node *head, int item)
{
	struct node *previous = NULL;
	struct node *current  = head;
	
	while (current != NULL && current->item != item)
	{
		previous = current;
		current = current->next;
	}
	
	if (current == NULL)
		return head;
	
	if (previous == NULL)
	{
		head = current->next;
	}
	else
	{
		previous->next = current->next;
	}

	free(current);
	
	return head;
}

int subset (struct node *l1, struct node *l2)
{
	
	while (l1 != NULL)
	{
		l2 = remove_node(l2, l1->item);
		
		if (l2 == NULL)
			break;

		l1 = l1->next;
	}

	return (l1 != NULL && l2 == NULL) ? 1: 0;
}

int main ()
{
	int n1, n2;

	scanf("%d", &n1);
	struct node *l1 = add_node_list(0, n1, NULL);
	
	scanf("%d", &n2);
	struct node *l2 = add_node_list(0, n2, NULL);
		
	printf("%d\n", subset(l1, l2));

	return 0;
}

