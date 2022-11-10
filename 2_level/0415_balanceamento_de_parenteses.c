#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
typedef struct stack stack;

struct node
{
    char elem;
    node *next;
};

struct stack
{
    node *top;
};

stack *create_stack ()
{
    stack *new_stack = (stack *) malloc(sizeof(stack));
    
    if (new_stack == NULL)
        exit(1);
        
    return new_stack;
}

void push (stack *s, char elem)
{
    node *new_top = (node *) malloc(sizeof(node));
    
    if (new_top == NULL)
        exit(1);
    
    new_top->elem = elem;
    new_top->next = s->top;
    
    s->top = new_top;
}

char pop (stack *s)
{
    if (s->top == NULL)
        return 'N';
    
    node *aux = s->top;
    s->top = s->top->next;
    
    char elem = aux->elem;
    
    aux->next = NULL;
    
    return elem;
}

void print_stack (stack *s)
{
    node *aux = s->top;
    
    while (aux != NULL)
    {
        if (aux->next != NULL)
        {
            printf("%c ", aux->elem);
        }
        else
        {
            printf("%c\n", aux->elem);
        }
        
        aux = aux->next;
    }
}

int check_string (char string[], stack *s)
{
    int i = 0;
    
    while (string[i] != '\0')
    {
        if (string[i] == '(')
        {
            push(s, string[i]);
        }
        else if (string[i] == ')')
        {
            if (pop(s) != '(')
                return 0;
        }
        else if (string[i] == '[')
        {
            push(s, string[i]);
        }
        else if (string[i] == ']')
        {
            if (pop(s) != '[')
                return 0;
        }
        
        i += 1;
    }
    
    return 1;
}

void loop(int n)
{
    if (n > 0)
    {
        char string[255];
        fgets(string, 255, stdin);
        stack *s = create_stack();
        
        if (check_string(string, s))
        {
            if (s->top == NULL)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            printf("No\n");
        }
        
        loop(n - 1);
    }
}

int main() 
{
    int n;
    scanf("%d ", &n);
    
    loop(n);
    
	return 0;
}