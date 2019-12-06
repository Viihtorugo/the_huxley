#include <stdio.h>
#include <stdlib.h>
#define NUM_MAX_NODES 20

struct node {
	int num;
	struct node *next;
};

struct node *add_node (struct node *head, int num)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	
	new_node->num = num;
	new_node->next = head;

	return new_node;
}

struct node *create_list(int i, struct node *head)
{
	if (i < NUM_MAX_NODES)
	{
		int num;
		scanf("%d", &num);

		head = add_node(head, num);
		return create_list(i + 1, head);
	}
	
	return head;
}

int equal_item_list_intersection(struct node *head, int num)
{
	while (head != NULL)
	{
		if (head->num == num)
			return 0;
		
		head = head->next;
	}

	return 1;
}

struct node *add_node_list_intersection(struct node *head, int num)
{	
	struct node *previous = NULL;
	struct node *current  = head;
	
	while(current != NULL && num > current->num)
	{
		previous = current;		
		current  = current->next;
	}
	
	if (previous == NULL)
	{
		head = add_node(head, num);
	}
	else
	{
		current = add_node(current, num);
		previous->next = current;
	}

	return head;
}

struct node *intersection (struct node *list1, struct node *list2)
{	
	struct node *r = NULL;

	while(list1 != NULL)
	{
		struct node *aux = list2;
		
		while(aux != NULL)
		{
			if(list1->num == aux->num)
			{
				if(equal_item_list_intersection(r, aux->num))
					r = add_node_list_intersection(r, aux->num);

				break;
			}
			
			aux = aux->next;
		}
		
		list1 = list1->next;
	}

	return r;
}

int main ()
{
	struct node *list1 = create_list(0, NULL);
	struct node *list2 = create_list(0, NULL);
	struct node *r     = intersection (list1, list2);
	
	if (r == NULL)
	{
		printf("VAZIO\n");
	}
	else
	{
		while (r != NULL)
		{
			printf("%d\n", r->num);
			r = r->next;
		}
	}

	return 0;
}
