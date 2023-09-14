#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list list;
typedef struct list_names list_names;
typedef struct graph graph;

typedef struct list_names{
    int index;
    char name[16];
    list_names *next;
} list_names;

typedef struct list{
    int elem;
    list *next;
} list;

typedef struct graph{
    int size;
    int *visited;
    list **list_adj;
} graph;

graph *create_graph()
{
    graph *g = (graph *) malloc(sizeof(graph));
    g->size = 100;
    g->list_adj = (list **) malloc(g->size * sizeof(list *));
    g->visited = (int *) malloc(g->size * sizeof(int));

    for (int i = 0; i < g->size; i++)
    {
        g->list_adj[i]  = NULL;
        g->visited[i]   = 1;
    }
    
    return g;
}

int size_graph(graph *g)
{
    int count = 0;

    for (int i = 0; i < 100; i++)
        if (g->list_adj[i] != NULL)
            count++;
    
    return count;
}

void print_list (list *head, list_names *names)
{
    list *aux = head;

    while (aux != NULL)
    {
        printf("%d ", aux->elem);
        aux = aux->next;
    }
}

void print_list_names (list_names *head)
{
    list_names *aux = head;

    while (aux != NULL)
    {
        printf("%s\n", aux->name);
        aux = aux->next;
    }
}

list *add_node (list *head, int elem)
{
    list *new_node = (list *) malloc(sizeof(list));
    
    new_node->elem = elem;
    new_node->next = head;

    return new_node;
}

int verificar (char *name1, char *name2)
{
    int i = 0;

    while (name1[i] != '\0' && name2[i] != '\0')
    {
        if ((int)name1[i] > (int)name2[i])
        {
            return 0;
        }
        else if ((int) name1[i] < name2[i])
        {
            return 1;
        }

        i++;
    }

    if (name1[i] == '\0')
        return 0;

    return 1;
}

list_names *add_node_name (list_names *head, char name[16], int elem)
{
    list_names *new_node = (list_names *) malloc(sizeof(list_names));
    
    new_node->index = elem;
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        list_names *current = head;
        list_names *prev = NULL;

        while(current != NULL && verificar(current->name, name))
        {
            prev = current;
            current = current->next;
        }

        if (prev == NULL)
        {
            new_node->next = current;
            head = new_node;
        }
        else
        {
            prev->next = new_node;
            new_node->next = current;
        }

        return head; 
    }
}

list *remove_node (list *head, int elem)
{
    if (head == NULL)
        return head;

    list *current   = head;
    list *prev      = NULL;

    while (current != NULL && current->elem != elem)
    {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL)
        return head;

    if (prev == NULL)
    {
        head = head->next;
        current->next = NULL;
    }
    else
    {
        prev->next = current->next;
        current->next = NULL;
    }

    free(current);

    return head;
}

list_names *remove_node_names (list_names *head, int elem)
{
    if (head == NULL)
        return head;

    list_names *current   = head;
    list_names *prev      = NULL;

    while (current != NULL && current->index != elem)
    {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL)
        return head;

    if (prev == NULL)
    {
        head = head->next;
        current->next = NULL;
    }
    else
    {
        prev->next = current->next;
        current->next = NULL;
    }

    free(current);

    return head;
}

int index_names (list_names *head, char name[])
{
    list_names *aux = head;

    while (aux != NULL && (strcmp(aux->name, name) != 0))
        aux = aux->next;
    
    if (aux != NULL)
        return aux->index;
    
    return -1;
}

void remove_edge (graph *g, int tam, int index)
{
    for (int i = 0; i < tam; i++)
    {
        g->list_adj[i] = remove_node(g->list_adj[i], index);
    }
    
}

void dfs (graph *g, list_names *in, int tam)
{
    while (in != NULL)
    {
        list_names *aux = in;
        list_names *out = NULL;

        while (aux != NULL)
        {
            int index = index_names(in, aux->name);

            if (g->list_adj[index] == NULL)
            {
                out = add_node_name(out, aux->name, index);
            }

            aux = aux->next;
        }
        
        print_list_names(out);

        aux = out;

        while (aux != NULL)
        {
            remove_edge(g, tam, aux->index);
            in = remove_node_names(in, aux->index);
            aux = aux->next;
        }
        
    }
}

void add_edge(graph *g, int v, int u)
{
    g->list_adj[v] = add_node(g->list_adj[v], u);
}

void print_graph(graph *g)
{
    for (int i = 0; i < g->size; i++)
    {
        printf("%d: ", i);

        list *aux = g->list_adj[i];

        while (aux != NULL)
        {
            printf("%d ", aux->elem);
            aux = aux->next;
        }

        printf("\n");
    }
    
}

void solve ()
{
    int n, tam = 0;

    if (scanf("%d", &n) == EOF)
        return;
    
    graph *g = create_graph();
    list *list = NULL;
    list_names *list_names = NULL;
    char s1[16], s2[16];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", s1, s2);

        int index1 = index_names(list_names, s1);

        if (index1 == -1)
        {
            list_names = add_node_name(list_names, s1, tam);
            index1 = tam;
            tam++;
        }

        int index2 = index_names(list_names, s2);

        if (index2 == -1)
        {
            list_names = add_node_name(list_names, s2, tam);
            index2 = tam;
            tam++;
        }

        //print_list_names(list_names);

        add_edge(g, index1, index2);       
    }

    //print_graph(g);
    
    dfs(g, list_names, tam);

    //print_graph(g);
    //print_list_names(list_names);
    
    solve();
}

int main ()
{
    solve();
    return 0;
}