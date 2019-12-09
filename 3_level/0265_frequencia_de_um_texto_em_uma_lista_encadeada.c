#include <stdio.h>
#include <stdlib.h>

struct node {
	char c;
	int count;
	struct node *next;
};

struct node *add_node (struct node *head, char c, int count)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->c = c;
	new_node->count = count;
	new_node->next = head;

	return new_node;
}

struct node *create_list (struct node *head)
{
	char string[257];
	scanf("%[^\n]s", string);
	
	int i;
	
	for (i = 0; i < 256; i++)
	{
		int j = 0, count = 0;
		
		while(string[j] != '\0')
		{
			if (i == (int) string[j])
				count += 1;
			
			j += 1;	
		}
		
		if (count)
		{
			head = add_node(head, (char)i, count);
		}
	}

	return head;
}

void print_list (struct node *l)
{
	while(l != NULL)
	{
		printf("%c %d\n", l->c, l->count);
		l = l->next;
	}
}

int main ()
{
	struct node *l = create_list(NULL);
	
	print_list(l);

	return 0;
}
