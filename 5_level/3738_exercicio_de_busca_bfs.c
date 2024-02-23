#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct list
{
    int n;
    int w;
    struct list *next;
} list;

typedef struct stack
{
    int v;
    struct stack *next;
} stack;

typedef struct graph
{
    list **adj_list;
} graph;

stack *push (stack *top, int v)
{
    stack *new_top = (stack *) malloc (sizeof(stack));
    
    new_top->v = v;
    new_top->next = top;

    return new_top;
}

int pop (stack **top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        int v = (*top)->v;

        stack *aux = *top;
        (*top) = (*top)->next;
        aux->next = NULL;
        free(aux);

        return v;
    }
}

void print_list(list *head)
{
    if (head == NULL)
        return;

    list *aux = head;
    
    if ((char)aux->n == 'F' || (char)aux->n == 'H')
    {
        while (aux != NULL)
        {
            printf("%c ", (char) aux->n);
            aux = aux->next;
        }

        printf("\n");
    }
    else
    {
        while (aux != NULL)
        {
            printf("%c", (char) aux->n);

            if (aux->next != NULL)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }

            aux = aux->next;
        }

    }

}

list *add_elem_list(list *head, int n, int w)
{
    list *new_node = (list *) malloc(sizeof(list));
    new_node->n = n;
    new_node->w = w;
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        list *current = head;

        while (current->next != NULL)
            current = current->next;

        current->next = new_node;

        return head;
    }
}

int remove_elem_list(list **head)
{
    if (*head == NULL)
    {
        return -1;
    }
    else
    {
        int v = (*head)->n;
        list *aux = *head;
        (*head) = (*head)->next;
        aux->next = NULL;
        free(aux);

        return v;
    }
}

void free_graph(graph *g)
{
    for (int i = 0; i < 256; i++)
    {
        list *current = g->adj_list[i];

        while (current != NULL)
        {
            list *aux = current;
            aux->next = NULL;

            current = current->next;
            
            free(aux);
        }
    }

    free(g);
}

void add_edge (int v1, int v2, int w, graph *g)
{
    g->adj_list[v1] = add_elem_list(g->adj_list[v1], v2, w);
    g->adj_list[v2] = add_elem_list(g->adj_list[v2], v1, w);
}

void bfs (graph *g, int o, int d)
{
    int dist[256];
    int parent[256];

    for (int i = 0; i < 256; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    

    list *head = NULL;
    head = add_elem_list(head, o, 0);
    dist[o] = 0;


    while (head != NULL)
    {
        print_list(head);
        int v = remove_elem_list(&head);
        
        if (v != -1)
        {
            list *aux = g->adj_list[v];

            while(aux != NULL)
            {
                if (dist[v] + aux->w < dist[aux->n])
                {
                    if (parent[aux->n] == -1)
                        head = add_elem_list(head, aux->n, aux->w);

                    dist[aux->n] = dist[v] + aux->w;
                    parent[aux->n] = v;
                }

                aux = aux->next;
            }
        }
    }

    int aux = d;
    stack *top = NULL;

    while (aux != -1 && parent[aux])
    {
        top = push(top, aux);
        aux = parent[aux];
    }

    printf("\n");
    while (top != NULL)
    {
        printf("%c", (char)pop(&top));

        if (top == NULL)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

}

int main ()
{
    char o, d;
    scanf("%c %c", &o, &d);
    int init = (int) o, end = (int) d;
    
    int w;
    graph *g = (graph *) malloc(sizeof(graph));
    
    g->adj_list = (list **) malloc(256 * sizeof(list *));

    for (int i = 0; i < 256; i++)
        g->adj_list[i] = NULL;

    while ( scanf(" %c->%c %d", &o, &d, &w) != EOF)
        add_edge((int)o, (int)d, w, g);
    
    bfs(g, init, end);

    return 0;
}