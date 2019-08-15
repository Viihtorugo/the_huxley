#include <stdio.h>

typedef struct list list;

struct list {
	int n;
	list *next;
};

void add_nodes (list *l, int i)
{
	if (i > 0)
	{
		list node;

		scanf("%d", &node.n);
		
		l->next = &node;
		add_nodes(l->next, i - 1);
	}

	l = NULL;
}

void print_list (list *l)
{
	if (l != NULL)
	{
		printf("test\n");
		printf("%d\n", l->n);
		print_list(l->next);
	}
}

int main ()
{	
	list l;
	
	add_nodes(&l, 10);
	print_list(&l);

	return 0;
}
