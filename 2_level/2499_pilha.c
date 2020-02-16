#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct stack stack;

struct node 
{
    int item;
    node *next;
};

struct stack
{
    node *head;
};

int is_empty_stack (stack *stack)
{
    return (stack->head == NULL); 
}

stack *create_stack ()
{
    stack *new_stack = (stack *) malloc (sizeof(stack));

    new_stack->head = NULL;

    return new_stack;
}

void push (stack *stack, int item)
{
    node *new_node = (node *) malloc(sizeof(node));
    
    new_node->item = item;
    new_node->next = stack->head;

    stack->head = new_node;
}

void pop (stack *stack)
{
    if (is_empty_stack(stack))
        return;

    node *aux = stack->head;

    stack->head = stack->head->next;

    free(aux);
}

void print_stack (stack *stack)
{
    node *current = stack->head;

    while (current != NULL)
    {
        if (current->next != NULL)
        {
            printf("%d ", current->item);
        }
        else
        {
            printf("%d\n", current->item);
        }
        
        current = current->next;
    }
}



void loop(stack *stack)
{
    char comant[20];
    scanf("%s", comant);

    if (comant[0] == 'E')
    {
        int item;
        scanf(" %d", &item);

        push(stack, item);

        loop(stack);
    }
    else if (comant[0] == 'D')
    {
        pop(stack);
        loop(stack);
    } 
    else if (comant[0] == 'I')
    {
        print_stack(stack);
        loop(stack);
    }
    
}

void free_stack (stack *stack)
{

    while (stack->head != NULL)
    {   
        node *current = stack->head;

        stack->head = stack->head->next;

        free(current);
    }

    free(stack);
}

int main ()
{
    stack *stack = create_stack();
    
    loop(stack);
    free_stack(stack);
    
    return 0;
}