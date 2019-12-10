#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node *next;
};

struct stack {
	struct node *list;
	struct stack *next;
};

struct node *add_node (struct node *head, int item)
{
	struct node *new_node = (struct node *) malloc (sizeof(struct node));
	new_node->item = item;	

	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		struct node *current = head;
		
		while(current->next != NULL)
			current = current->next;
		
		current->next = new_node;
	}

	return head;
}


struct node *create_list (struct node *head)
{
	int item;
	char c;

	scanf("%d%c", &item, &c);	
	
	head = add_node(head, item);
	
	if (c == ' ')	
		return create_list(head);
	
	return head;
}

struct stack *push (struct stack *top, struct node *list)
{
	struct stack *new_top = (struct stack *) malloc(sizeof(struct stack));
	
	new_top->list = list;
	new_top->next = top;
	
	return new_top;
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

struct stack *pop (struct stack *new_top)
{
	if (new_top == NULL)
	{
		printf("EMPTY STACK\n");
		return NULL;
	}
	
	struct stack *top = new_top;
	new_top = new_top->next;
	top->next = NULL;

	print_list(top->list);

	free(top);

	return new_top;
}

void loop (struct stack *top)
{
	char string[5];

	if (scanf("%s", string) != EOF)
	{
		struct node *l;

		if (string[1] == 'O')
		{
			top = pop(top);
		}
		else if (string[1] == 'U')
		{
	
			l = create_list(NULL);
			top = push(top, l);
		}
		
		loop(top);
	}
}

int main ()
{
	loop (NULL);
	return 0;
}
