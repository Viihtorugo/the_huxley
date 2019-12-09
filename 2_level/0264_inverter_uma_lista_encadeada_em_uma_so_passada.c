#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node *next;
};

struct node *add_node (struct node *head, int item)
{
	if (head == NULL)
	{
		struct node *new_node = (struct node *) malloc(sizeof(struct node));
		new_node->item = item;
		new_node->next = head;

		return new_node;
	}
	else
	{
		struct node *current = head;

		while (current->next != NULL)
			current = current->next;
		
		struct node *new_node = (struct node *) malloc(sizeof(struct node));
		new_node->item = item;
		current->next = new_node;
	}

	return head;
}

struct node *create_list (struct node *l)
{
	int num;
	
	if(scanf("%d", &num) != EOF)
	{
		l = add_node(l, num);
		return create_list(l);
	}
	
	return l;
}

int reverse_print (struct node *l, int i)
{
	if (l != NULL)
	{
		reverse_print(l->next, i + 1);
		
		if (i)
		{
			printf("%d ", l->item);
		}
		else
		{
			printf("%d\n", l->item);
		}
	}
}

int main ()
{
	
	struct node *l = create_list(NULL);

	return reverse_print(l, 0);
}
