#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct hash_table hash_table;

struct node 
{
    int key;
    //int value;
    node *next;
};

struct hash_table
{
    node **table;
};

hash_table *create_hash_table (int m)
{
    hash_table *ht = (hash_table *) malloc(sizeof(hash_table));

    if (ht == NULL)
    {
        printf("Segment fault(Memory)\n");
        return NULL;
    }

    ht->table = (node **) malloc(m * sizeof(node *));

    if (ht->table == NULL)
    {
        printf("Segment fault(Memory)\n");
        free(ht);
        return NULL;
    }

    int i;
    for (i = 0; i < m; i++)
        ht->table[i] = NULL;
    
    return ht;
}

void put (hash_table *ht, int m, int key)
{
    node *new_node = (node *) malloc(sizeof(node));
    
    new_node->key = key;
    new_node->next = NULL;

    if (ht->table[key % m] == NULL)
    {
        ht->table[key % m] = new_node;
    }
    else
    {
        node *current = ht->table[key % m];

        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
    
}

node *get (hash_table *ht, int key, int m)
{
    return (ht->table[key % m]);
}

void remove_hash_table (hash_table *ht, int key, int m)
{
    node *current = ht->table[key % m];
    node *previous = NULL;

    while (current != NULL && current->key != key)
    {
        previous = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (previous == NULL)
        {
            previous = current;
            current = current->next;

            free(previous);
        }
        else
        {
            previous->next = current->next;
            free(current);
        }
    }
    else
    {
        printf("Essa key %d nao esta cadastrada\n", key);
    }
    
}

void print_list (node *list)
{
    node *current = list;

    while (current != NULL)
    {
            printf("%d -> ", current->key);
            current = current->next;
    }
}

void print_hash_table (hash_table *ht, int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        printf("%d -> ", i);
        print_list(ht->table[i]);
        printf("\\\n");
    }
}

void add_keys(hash_table *ht, int m, int c)
{
    if (c > 0)
    {
        int key;
        scanf("%d", &key);

        put(ht, m, key);

        add_keys(ht, m, c - 1);
    }
}

void free_node (node *list)
{

    while (list != NULL)
    {
        node *current = list;

        list = list->next;

        free(current);
    }

    free(list);
}

void free_hash_table (hash_table *ht, int m)
{
    int i;

    for (i = 0; i < m; i++)
        free_node(ht->table[i]);
    
    free(ht);
}

void loop (int n)
{
    if (n > 0)
    {
        int m, c;
        scanf("%d %d", &m, &c);

        hash_table *ht = create_hash_table(m);
        
        add_keys(ht, m, c);
        print_hash_table(ht, m);

        if (n - 1 != 0)
            printf("\n");
        
        loop(n - 1);
    }
}

int main ()
{
    int n;
    scanf("%d", &n);

    loop(n);

    return 0;
}