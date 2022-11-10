#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack stack;

typedef struct stack
{
    int elem;
    stack *next;
} stack;

int is_empty(stack *top)
{
    return (int)(top == NULL);
}

stack *push (stack *top, int elem)
{
    stack *new_top = (stack *)malloc(sizeof(stack));
    
    if (is_empty(new_top))
        exit(1);
    
    new_top->elem = elem;
    new_top->next = top;
    
    return new_top;
}

stack *pop (stack *top)
{
    stack *aux = top;
    
    top = top->next;
    
    aux->next = NULL;
    
    free(aux);
    
    return top;
}

void print_stack (stack *top)
{
    while (top != NULL)
    {
        if (top->next != NULL)
        {
            printf("%d ", top->elem);
        }
        else
        {
            printf("%d\n", top->elem);
        }
        
        top = top->next;
    }
}

int main() {
    
    char string[12];
    stack *top = NULL;
    
    while (1)
    {
        scanf("%s", string);
        
        if (strcmp(string, "Empilhar") == 0)
        {
            int elem;
            scanf(" %d", &elem);
            
            top = push(top, elem);
        }
        else if (strcmp(string, "Desempilhar") == 0)
        {
            top = pop(top);
        }
        else if (strcmp(string, "Imprimir") == 0)
        {
            print_stack(top);
        }
        else if (strcmp(string, "Finalizar") == 0)
        {
            break;
        }
    }
    
	return 0;
}