#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int elem;
    struct list *next;
} list;

typedef struct queue
{
    int elem;
    struct queue *next;
} queue;

typedef struct graph
{
    int size;
    int *visited;
    int *count;
    list **list_adj;
} graph;

list *add_node(int elem, list *l)
{
    list *new_node = (list *)malloc(sizeof(list));

    if (new_node == NULL)
        exit(1);

    new_node->elem = elem;

    if (l == NULL)
    {
        return new_node;
    }
    else
    {
        list *aux = l;
        list *prev = NULL;

        while (aux != NULL && elem >= aux->elem)
        {
            prev = aux;
            aux = aux->next;
        }

        if (prev == NULL)
        {
            new_node->next = aux;
            l = new_node;
        }
        else
        {
            prev->next = new_node;
            new_node->next = aux;
        }

        return l;
    }
}

queue *enqueue(int elem, queue *q)
{
    queue *new = (queue *)malloc(sizeof(queue));

    if (new == NULL)
        exit(1);

    new->elem = elem;

    if (q == NULL)
    {
        q = new;
    }
    else
    {
        queue *aux = q;

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = new;
    }

    return q;
}

int dequeue(queue **q)
{
    if ((*q) == NULL)
        return -1;

    int dequeued = (*q)->elem;

    queue *aux = *q;

    (*q) = (*q)->next;

    free(aux);

    return dequeued;
}

void print_graph(graph *g)
{
    for (int i = 0; i < g->size; i++)
    {
        list *aux = g->list_adj[i];
        printf("v%d:", i);

        while (aux != NULL)
        {
            if (aux->next != NULL)
            {
                printf(" v%d", aux->elem);
            }
            else
            {
                printf(" v%d", aux->elem);
            }

            aux = aux->next;
        }

        printf(" -> vizinhos\n");
    }
}

graph *create_graph(int size)
{
    if (size > 0)
    {
        graph *g = (graph *)malloc(sizeof(graph));

        if (g == NULL)
            exit(1);

        g->size = size;

        g->visited = (int *)malloc(g->size * sizeof(int));

        if (g->visited == NULL)
            exit(1);

        g->count = (int *)malloc(g->size * sizeof(int));

        if (g->count == NULL)
            exit(1);

        g->list_adj = (list **)malloc(g->size * sizeof(list *));

        if (g->list_adj == NULL)
            exit(1);

        for (int i = 0; i < size; i++)
        {
            g->visited[i] = -1;
            g->list_adj[i] = NULL;
        }

        return g;
    }

    return NULL;
}

void bfs(graph *g, int o)
{
    if (g == NULL)
        return;

    queue *q = NULL;
    q = enqueue(o, q);

    g->visited[o] = o;
    g->count[o] = 0;

    while (q != NULL)
    {
        int v = dequeue(&q);
        list *aux = NULL;
        
        if (v >= 0)
            aux = g->list_adj[v];

        printf("Iniciando busca em largura a partir de %d\n", v);

        while (aux != NULL)
        {
            if (g->visited[aux->elem] == -1)
            {
                g->visited[aux->elem] = v;
                g->count[aux->elem] = g->count[v] + 1;
                q = enqueue(aux->elem, q);
            }

            aux = aux->next;
        }
    }
}

void caminho(graph *g, int d, int o, int visited[])
{
    int count = 0;

    for (int i = 0; i < g->size; i++)
        if (visited[i])
            count += 1;

    if (d == -1 && count == g->size)
        return;

    if (g->visited[d] != o && g->visited[d] != d)
    {
        visited[d] = 1;
        caminho(g, g->visited[d], o, visited);
        printf(" %d =>", g->visited[d]);
    }
    else
    {
        printf(" %d =>", g->visited[d]);
    }
}

int main()
{
    int n, m, e;
    scanf("%d %d %d", &n, &m, &e);

    printf("--------\n");

    graph *g = create_graph(n);

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        if (g != NULL)
            g->list_adj[v1] = add_node(v2, g->list_adj[v1]);
    }

    // print_graph(g);

    for (int i = 0; i < e; i++)
    {
        int o, d;
        scanf("%d %d", &o, &d);
        printf("\nCaso de Teste #%d - BFS(%d)\n\n", i + 1, o);

        if (g != NULL)
        {
            for (int j = 0; j < g->size; j++)
            {
                g->visited[j] = -1;
                g->count[j] = -1;
            }
        }

        bfs(g, o);

        printf("\n");

        if (g != NULL)
        {
            for (int j = 0; j < g->size; j++)
            {
                printf("%d | ", j);

                if (g->count[j] != -1)
                {
                    printf("%d | ", g->count[j]);
                }
                else
                {
                    printf("- | ");
                }

                if (g->visited[j] != -1 && g->visited[j] != j)
                {
                    printf("%d\n", g->visited[j]);
                }
                else
                {
                    printf("-\n");
                }
            }

            printf("\n");
            if (g->visited[d] == -1)
            {
                printf("Sem caminho entre %d e %d\n", o, d);
            }
            else
            {
                printf("Caminho entre %d e %d:", o, d);

                if (o != d)
                {
                    int visited[n];

                    for (int i = 0; i < n; i++)
                        visited[i] = 0;

                    caminho(g, d, o, visited);
                }

                printf(" %d\n", d);
            }
        }
        else
        {
            printf("Sem caminho entre %d e %d\n", o, d);
        }

        printf("\n--------\n");
    }

    return 0;
}