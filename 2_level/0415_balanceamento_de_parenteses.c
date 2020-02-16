#include <stdio.h>
#include <stdlib.h>

struct stack {
	char item;
	struct stack *next;
};

struct stack *push (struct stack *top, char item)
{
	struct stack *new_top = (struct stack *) malloc (sizeof(struct stack));
	new_top->item = item;
	new_top->next  = top;
	
	return new_top;
}

struct stack *pop (struct stack *top)
{
	struct stack *new_top = top->next;	
	top->next = NULL;

	free(top);
	
	return new_top;
}

short balancing (struct stack *top1, struct stack *top2)
{
	char string[500];
	int i = 0;

	scanf("%[^\n]s", string);
	
	while (string[i] != '\0')
	{
		if (string[i] == '(')
		{
			top1 = push(top1, string[i]);
		}
		else if (string[i] == '[')
		{
			top2 = push(top2, string[i]);
		}
		else if (string[i] == ')')
		{
			if (top1 == NULL)
				return 0;

			top1 = pop(top1);
		} 
		else if (string[i] == ']')
		{
			if (top2 == NULL)
				return 0;

			top2 = pop(top2);
		}
		
		i += 1;
	}

	if (top1 == NULL)
		if(top2 == NULL)
			return 1;

	return 0;
}

void loop (int n)
{
	if (n > 0)
	{
		getchar();
		if (balancing(NULL, NULL))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		
		loop(n - 1);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);

	loop(n);

	return 0;
}
