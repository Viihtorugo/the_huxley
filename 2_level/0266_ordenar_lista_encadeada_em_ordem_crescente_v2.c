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

void print_list (struct node *l)
{
	while(l != NULL)
	{
		if (l->next != NULL)
		{
			printf("%d ", l->item);
		}
		else
		{
			printf("%d\n", l->item);
		}
		
		l = l->next;
	}
}

struct node *create_list (struct node *l)
{
	int item;
	
	if (scanf(" %d", &item) != EOF)
	{
		l = add_node(l, item);
		return create_list(l);
	}
	
	return l;
}

struct node *remove_node (struct node *head, int item)
{
	struct node *current  = head;
	struct node *previous = NULL;

	while (current != NULL && item != current->item)
	{
		previous = current;
		current = current->next;
	}
	
	if (previous != NULL)
	{
		previous->next = current->next;
	}
	else
	{
		head = current->next;
	}

	free(current);

	return head;
}

int biggest_item (struct node *current, int item)
{
	if (current != NULL)
	{
		if (current->item > item)
			item = current->item;
		
		return biggest_item(current->next, item);
	}
	
	return item;
}

struct node *current_next (struct node* head)
{
	struct node *aux = head;		
	
	int item = biggest_item(aux->next, aux->item);

	while(aux != NULL && aux->item < item)
		aux = aux->next;
	
	aux = aux->next;	

	if (aux != NULL && aux->item == item)
		while (aux != NULL && item == aux->item)
			aux = aux->next;

	return aux;
}

struct node *selection_sort (struct node *head)
{
	struct node *current = head;
	
	int item;
	
	item = biggest_item(current->next, current->item);
	
	while (current != NULL && item <= current->item)
			current = current->next;	


	while (current != NULL)
	{

		item = biggest_item(current->next, current->item);
		
		struct node *aux = head;
		
		if (aux->item == item)
		{
			while (aux != NULL && item == aux->item)
				aux = aux->next;
		}

		aux 	= remove_node(aux, item);
		head 	= add_node(head, item);
		
		current = current_next(head);
	}

	return head;
}

int main ()
{	
	struct node *l = create_list(NULL);
	
	l = selection_sort(l);
	
	print_list(l);
	
	return 0;
}

