#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
	int n;
	struct list *next;
} List;

List *listSort (int n, List *list)
{
	if(n == 0)
		return list;
	
	if(list == NULL)
	{
		list = malloc(sizeof(List));
		
		if(list == NULL)
			exit(0);
		
		scanf("%d", &list->n);		
	}
	else
	{
		List *current = list;
		List *node = malloc(sizeof(List));
		
		if(node == NULL)
			exit(0);
		
		scanf("%d", &node->n);
		
		while(current->next != NULL)
		{
			if(node->n > current->n)
			{
				current = current->next;
			}
			else
			{
				List *aux 	= current;
				current 	= node;
				current->next 	= aux;
				break;
			}
		}
		
		if(current->next == NULL)
		{
			current->next = node;
		}
	}
	
	
	return listSort(--n, list);
}


void isNull (List *list)
{
	if(list == NULL)
	{
		free(list);
		exit(0);
	}
}

void addNode (int n, List *list)
{	
	isNull(list);
	
	if (n == 0)
	{
		free(list->next);
		return;
	}

	scanf("%d", &list->n);
	
	list->next = malloc(sizeof(List));
	
	addNode(n-1, list->next);
}

int main ()
{	
	List *list = malloc(sizeof(List));
	addNode(3, list);
	
	while(list != NULL)
	{
		printf("n = %d\n", list->n);
		list = list->next;
	}
	
	free(list);
	return 0;
}
