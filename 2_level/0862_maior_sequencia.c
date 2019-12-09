#include <stdio.h>
#include <stdlib.h>

struct node {
    char item;
    struct node *next;
};

void print_list(struct node *l)
{
    while(l != NULL)
    {
        if(l->next != NULL)
        {
            printf("%c", l->item);
        }
        else
        {
            printf("%c\n", l->item);
        }
        
        l = l->next;
    }
}

struct node *add_node (struct node *head, char item)
{
    
    struct node *new_node = (struct node *) malloc (sizeof(struct node));
    new_node->item = item;
    
    if(head == NULL)
    {
        new_node->next = head;
        return new_node;
    }
    else
    {
        struct node *current;
        
        for(current = head; current->next != NULL; current = current->next);
        
        current->next = new_node;
        
        return head;
    }
    
    
}

struct node *input (struct node *head)
{
    char string[250];
    scanf("%[^\n]s", string);
    getchar();
    
    int i = 0;
    
    while(string[i] != '\0')
    {
        head = add_node(head, string[i]);
        i += 1;
    }
    
    return head;
}

void position_of_seq_zero(struct node *l, int *i, int *e)
{
    int initial = 0, end = 0;
    
    while(l != NULL)
    {
        if (l->item == '0')
        {
            while (l->next != NULL && l->next->item == '0')
            {
                end += 1;
                l = l->next;
            }
        }
        
        if ((end - initial) > (*e - *i))
        {
            *i = initial;
            *e = end;
            
            initial = end;
        }
        
        initial += 1;
        end     += 1;
        l = l->next;
    }
}

void loop ()
{
    struct node *l = input(NULL);
    
    if (l->next == NULL && l->item == '0')
    {
        return;
    }
    else
    {
        int i = 0, e = 0;
        position_of_seq_zero(l, &i, &e);
        printf("%d %d\n", i, e);
        loop();
    }
    
}

int main() {
    loop();
	return 0;
}
