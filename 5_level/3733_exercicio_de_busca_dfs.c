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

stack *push(stack *top, int v)
{
    stack *new_top = (stack *)malloc(sizeof(stack));

    new_top->v = v;
    new_top->next = top;

    return new_top;
}

int pop(stack **top)
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

    while (aux != NULL)
    {
        printf("%c", (char)aux->n);

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

list *add_elem_list(list *head, int n, int w)
{
    list *new_node = (list *)malloc(sizeof(list));
    new_node->n = n;
    new_node->w = w;
    new_node->next = head;

    return new_node;
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

void add_edge(int v1, int v2, int w, graph *g)
{
    g->adj_list[v1] = add_elem_list(g->adj_list[v1], v2, w);
}

void print_stack(stack *s)
{
    stack *aux = s;
    while (aux != NULL)
    {
        printf("%c", aux->v);

        if (aux->next == NULL)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }

        aux = aux->next;
    }
}

void dfs(graph *g, int o, int d, int visited[])
{

    stack *s = NULL;
    stack *state = NULL;
    s = push(s, o);
    printf("%c\n", (char)o);

    while (s != NULL)
    {
        int v = pop(&s);
        visited[v] = 1;

        if (visited[d] == 1)
            return;

        list *aux = g->adj_list[v];

        int flag = 0;

        while (aux != NULL)
        {
            if (visited[aux->n] == 0)
            {
                visited[aux->n] = 1;
                s = push(s, aux->n);
                state = push(state, aux->n);
                flag = 1;
            }

            aux = aux->next;
        }

        if (flag)
            print_stack(state);
    }
}

int main()
{
    char o, d;
    scanf("%c %c", &o, &d);
    int init = (int)o, end = (int)d;

    int w;
    graph *g = (graph *)malloc(sizeof(graph));

    g->adj_list = (list **)malloc(256 * sizeof(list *));

    for (int i = 0; i < 256; i++)
        g->adj_list[i] = NULL;

    while (scanf(" %c->%c %d", &o, &d, &w) != EOF)
        add_edge((int)o, (int)d, w, g);

    int visited[256] = {0};

    dfs(g, init, end, visited);

    free_graph(g);

    return 0;
}