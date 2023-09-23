#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int elem;
    struct list *next;
} list;

typedef struct hash_table
{
    int size;
    list **elem_list;
} hash_table;

hash_table *create_hash_table (int size)
{
    hash_table *h = (hash_table *) malloc(sizeof(hash_table));

    h->elem_list = (list **) malloc(size * sizeof(list *));
    h->size = size;

    for (int i = 0; i < size; i++)
        h->elem_list[i] = NULL;

    return h;
}

list *add_list (list *head, int elem)
{
    list *new_node = (list *) malloc (sizeof(list));

    new_node->elem = elem;
    new_node->next = NULL;

    if (head == NULL)
        return new_node;

    list *aux = head;

    while (aux->next != NULL)
        aux = aux->next;
    
    aux->next = new_node;

    return head;
}

void add_hash_table (hash_table *h, int elem)
{
    int i = elem % h->size;

    h->elem_list[i] = add_list(h->elem_list[i], elem);
}

void print_hash_table (hash_table *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d", i);

        list *aux = h->elem_list[i];

        while (aux != NULL)
        {
            printf(" -> %d", aux->elem);
            aux = aux->next;
        }

        printf(" -> \\\n");
    }
    
    printf("\n");
}

void solved ()
{
    int n, m;
    scanf("%d %d", &n, &m);

    hash_table *h = create_hash_table(n);

    for (int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);

        add_hash_table(h, num);
    }
    
    print_hash_table(h);
}

int main ()
{
    int t;
    scanf("%d", &t);

    while (t--)
        solved();
    

    return 0;
}