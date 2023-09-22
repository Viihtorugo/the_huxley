#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int elem;
    struct list *next;
} list;

typedef struct hash_table {
    int size;
    int num_elem;
    list **list_elem;
} hash_table;

hash_table *create_hash_table (int size)
{
    hash_table *hash = (hash_table *) malloc(sizeof(hash));

    hash->size = size;
    hash->num_elem = 0;
    hash->list_elem = (list **) malloc(size * sizeof(list *));

    for (int i = 0; i < size; i++)
        hash->list_elem[i] = NULL;

    return hash;
}

int search_list (list *head, int elem, int *count)
{
    if (head == NULL)
        return 0;

    list *aux = head;

    while (aux != NULL && aux->elem != elem)
    {
        *count = *count + 1;
        aux = aux->next;
    }

    if (aux != NULL)
        *count = *count + 1;

    return (aux == NULL) ? 0: 1;
}

list *add_list (list *head, int elem)
{
    list *new_head = (list *) malloc(sizeof(list));
    
    new_head->elem = elem;
    new_head->next = head; 

    return new_head;   
}

list *rm_list (list *head, int elem)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        list *current = head;
        list *prev = NULL;

        while (current != NULL && current->elem != elem)
        {
            prev = current;
            current = current->next;
        }
        
        if (prev == NULL)
        {
            head = current->next;
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
}

void print_hash (hash_table *h)
{
    printf("\n");
    for (int i = 0; i < h->size; i++)
    {
        list *aux = h->list_elem[i];

        printf("%d:", i);

        while (aux != NULL)
        {
            printf(" %d ->", aux->elem);
            aux = aux->next;
        }

        printf(" NULL\n");
    }

    printf("test\n");
}

hash_table *rehasting (hash_table *h)
{
    hash_table *new_h = create_hash_table((h->size * 2) - 1);

    for (int i = 0; i < h->size; i++)
    {
        list *aux = h->list_elem[i];

        while (aux != NULL)
        {
            int index = aux->elem % new_h->size;

            new_h->list_elem[index] = add_list(new_h->list_elem[index], aux->elem);
            new_h->num_elem++;

            aux = aux->next;
        }
    }
    
    return new_h;
}

hash_table *add_hast_table (hash_table *h, int elem, int i)
{
    int index = elem % h->size;
    int count = 0;
    int op;

    if (search_list(h->list_elem[index], elem, &count))
    {
        op = 0;
    }
    else
    {
        h->list_elem[index] = add_list(h->list_elem[index], elem);
        h->num_elem++;
        op = 1;
    }

    printf("%d %d %d\n", i, op, count);

    if (((double) h->num_elem) / ((double) h->size) < 0.75)
    {
        return h;
    }
    else
    {
        return rehasting (h);
    }
}

void rm_hast_table (hash_table *h, int elem, int i)
{
    int index = elem % h->size;
    int count = 0;
    int op;

    if (search_list(h->list_elem[index], elem, &count))
    {
        h->list_elem[index] = rm_list(h->list_elem[index], elem);
        h->num_elem--;
        op = 1;
    }
    else
    {
        op = 0;
    }

    printf("%d %d %d\n", i, op, count);
}

void search_hast_table (hash_table *h, int elem, int i)
{
    int index = elem % h->size;
    int count = 0;
    int op = search_list(h->list_elem[index], elem, &count);

    printf("%d %d %d\n", i, op, count);
}

void print (hash_table *h, int i)
{
    int qtd_list = 0;

    for (int i = 0; i < h->size; i++)
    {
        int count = 0;

        list *aux = h->list_elem[i];

        while (aux != NULL)
        {
            count++;
            aux = aux->next;
        }

        if (qtd_list < count)
            qtd_list = count;
    }
    

    printf("%d %d %d %d\n", i, h->size, h->num_elem, qtd_list);
}

int main ()
{
    char op[4];

    hash_table *h = create_hash_table(7);
    int i = 0;

    while (scanf(" %s", op) != EOF)
    {
        if (op[0] == 'A')
        {
            int num;
            scanf("%d", &num);

            h = add_hast_table(h, num, i);
        }
        else if (op[0] == 'D')
        {
            int num;
            scanf("%d", &num);

            rm_hast_table(h, num, i);
        }
        else if (op[0] == 'H')
        {
            int num;
            scanf("%d", &num);

            search_hast_table(h, num, i);
        }
        else if (op[0] == 'P')
        {
            print(h, i);
        }

        //print_hash(h);

        i++;
    }

    return 0;
}