#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int elem;
    struct node *next;
} node;

node *add_node (int elem, node *head)
{
    node *new_node = (node *) malloc(sizeof(node));

    if (new_node == NULL)
        exit(1);

    new_node->elem = elem;
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        node *aux = head;

        while (aux->next != NULL)
            aux = aux->next;
        
        aux->next = new_node;

        return head;
    }
}

node *remove_node (int elem, node *head)
{
    node *current = head;
    node *previous = NULL;

    while (current != NULL && current->elem != elem)
    {
        previous = current;
        current = current->next;
    }

    if (previous != NULL)
    {
        previous->next = current->next;
    }
    else
    {
        head = head->next;
    }

    free(current);

    return head;
}

int count_elem_node (node *head)
{
    return (head != NULL) ? 1 + count_elem_node(head->next): 0;   
}

void print_list (node *head)
{
    node *aux = head;

    while (aux != NULL)
    {
        if (aux->next == NULL)
        {
            printf("%d\n", aux->elem);
        }
        else
        {
            printf("%d ", aux->elem);
        }

        aux = aux->next;
    }
    
}


node *merge (node *head, int init, int final)
{
    if (head == NULL)
        return NULL;
    
    if (init <= final)
    {
        node *menor = NULL;

        while (init <= final/2 && head != NULL)
        {
            node *aux = head->next;
            int swap = head->elem;

            while (aux != NULL)
            {
                if (aux->elem < swap)
                    swap = aux->elem;

                aux = aux->next;
            }
            
            menor = add_node(swap, menor);
            head = remove_node(swap, head);

            init += 1;
        }

        node *aux = menor;

        while (aux->next != NULL)
            aux = aux->next;
        
        aux->next = merge(head, 0, final/2);

        return menor;
    }
}

node *loop (node *head)
{
    int num;

    while (scanf(" %d", &num) != EOF)
    {
        head = add_node(num, head);
    }
    
    return head;
}

int main ()
{
    node *head = NULL;

    head = loop(head);

    head = merge(head, 0, count_elem_node(head));
    print_list(head);

    return 0;
}