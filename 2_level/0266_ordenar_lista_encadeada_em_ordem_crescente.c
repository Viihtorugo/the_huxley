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
		
		while(current != NULL)
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
	}

	return listSort(--n, list);
}

int main ()
{	
	List *list = NULL;

	list = listSort(3, list);
	
	while(list != NULL)
	{
		printf("n = %d\n", list->n);
		list = list->next;
	}

	return 0;
}
