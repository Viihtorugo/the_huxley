#include <stdio.h>
#include <stdlib.h>

typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct queue queue;

struct adj_list 
{
    int item;
    adj_list *next;
};

struct queue 
{
    adj_list *head;
};

struct graph 
{
    adj_list **vertices;
    short *visited;
};

int is_empty_queue(queue *q)
{
    return (q->head == NULL);
}

graph *create_graph (int n)
{
    graph *g = (graph *) malloc(sizeof(graph));

    if (g == NULL)
    {
        printf("Segment fault (memory)\n");
        free(g);
        return NULL;
    }

    g->vertices = (adj_list **) malloc(n * sizeof(adj_list *));
    g->visited = (short *) malloc (n * sizeof(short));

    if (g->vertices == NULL || g->visited == NULL)
    {
        printf("Segment fault (memory)\n");
        free(g->vertices);
        free(g->visited);
        free(g);
        return NULL;
    }

    int i;

    for (i = 0; i < n; i++)
    {
        g->vertices = NULL;
        g->visited[i] = 0;
    }

    return g;
}

adj_list *create_adj_list(int item)
{
    adj_list *new_adj_list = (adj_list *) malloc (sizeof(adj_list));

    if (new_adj_list == NULL)
    {
        printf("Segment fault (memory)\n");
        return NULL;
    }

    new_adj_list->item = item;
    new_adj_list->next = NULL;

    return new_adj_list;
}

queue *create_queue()
{
    queue *q = (queue *) malloc(sizeof(queue));

    if (q == NULL)
    {
        printf("Segment fault (memory)\n");
        return NULL;
    }

    q->head = NULL;

    return q;
}

void enqueue (queue *q, int source)
{
    adj_list *new_adj_list = create_adj_list(source);

    adj_list *current = q->head;

    if (is_empty_queue(q))
    {
        q->head = new_adj_list;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;

        current->next = new_adj_list;
    }
}

int dequeue (queue *q)
{
    adj_list *current = q->head;
    int dequeued = q->head->item;

    q->head = q->head->next;

    free(current);

    return dequeued;
}

void add_edge (graph *graph, int vertex1, int vertex2)
{
    adj_list *vertex = create_adj_list(vertex2);
    vertex->next = graph->vertices[vertex1];
    graph->vertices[vertex1] = vertex;

    vertex = create_adj_list(vertex1);
    vertex->next = graph->vertices[vertex2];
    graph->vertices[vertex2] = vertex;
}

void dfs (graph *graph, int source)
{
    graph->visited[source] = 1;
    printf("%d\n", source);

    adj_list *adj_list = graph->vertices[source];

    while (adj_list != NULL)
    {
        if (!graph->visited[adj_list->item])
        {
            dfs(graph, adj_list->item);
        }

        adj_list = adj_list->next;
    }
}

void bfs (graph *graph, int source)
{
    queue *queue = create_queue();
    int dequeued;
    adj_list *adj_list = graph->vertices[source];
    graph->visited[source] = 1;
    enqueue(queue, source);

    while (!is_empty_queue(queue))
    {
        dequeued = dequeue(queue);
        adj_list = graph->vertices[dequeued];
        while (adj_list != NULL)
        {
            printf("%d\n", adj_list->item);
            graph->visited[adj_list->item] = 1;
            enqueue (queue, adj_list->item);
        }
        adj_list = adj_list->next;
    }
    
}

void loop(int c)
{
    if (c > 0)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        
        graph *graph = create_graph(m);

        loop(c - 1);
    }
}

int main ()
{
    int c;
    scanf("%d", &c);

    loop(c);

    return 0;
}