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
    int num_elem;
    list **elem_list;
} hash_table;

hash_table *create_hash_table (int size)
{
    hash_table *h = (hash_table *) malloc(sizeof(hash_table));

    h->size = size;
    h->num_elem = 0;

    h->elem_list = (list **) malloc (size * sizeof(list *));

    for (int i = 0; i < size; i++)
        h->elem_list[i] = NULL;
    
    return h;
}

list *add_list (list *head, int elem)
{
    list *new_node = (list *) malloc(sizeof(list));

    new_node->elem = elem;

    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        list *current = head;
        list *prev = NULL;

        while (current != NULL && elem > current->elem)
        {
            prev = current;
            current = current->next;
        }

        if (prev == NULL)
        {
            new_node->next = head;
            return new_node;
        }
        else
        {
            new_node->next = current;
            prev->next = new_node;
            return head;
        }
    }
}

list * rm_list (list *head, int elem)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        list *current = head;
        list *prev = NULL;

        while (current != NULL && elem != current->elem)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
            return head;

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

int search_list (list *head, int elem, int *count)
{
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

void print_hash_table (hash_table *h)
{
    printf("imprimindo tabela hash:\n");

    for (int i = 0; i < h->size; i++)
    {
        printf("[%d]:", i);

        if(h->elem_list[i] == NULL)
        {
            printf("Lista vazia!\n");
        }
        else
        {
            list *aux = h->elem_list[i];

            while (aux != NULL)
            {
                printf("%d=>", aux->elem);
                aux = aux->next;
            }
            
            printf("\n");
        }
    }
}

void search_hash_table (hash_table *h, int elem)
{
    int count = 0;
    
    printf("BUSCA POR %d\n", elem);
    printf("numero de elementos da tabela hash: %d\n", h->num_elem);
    
    if (search_list(h->elem_list[elem % h->size], elem, &count))
    {
        printf("elemento %d encontrado!\n", elem);
    }
    else
    {
        printf("elemento nao encontrado!\n");
    }
    
    printf("numero de elementos acessados na tabela hash: %d\n", count);
}

void add_hash_table (hash_table *h, int elem)
{
    int index = elem % h->size;

    h->elem_list[index] = add_list(h->elem_list[index], elem);
    h->num_elem++;
}

void rm_hash_table (hash_table *h, int elem)
{
    int index = elem % h->size;
    int count = 0;

    if (search_list(h->elem_list[index], elem, &count))
    {
        h->elem_list[index] = rm_list(h->elem_list[index], elem);
        h->num_elem--;
    }
}

int main ()
{
    int m;
    scanf("%d", &m);

    hash_table *h = create_hash_table(m);

    char c;

    while (1)
    {
        scanf(" %c", &c);

        if (c == 'f')
        {
            return 0;
        }
        else if (c == 'p')
        {
            int num;
            scanf("%d", &num);

            search_hash_table(h, num);
        }
        else if (c == 'a')
        {
            int num;
            scanf("%d", &num);

            add_hash_table(h, num);
        }
        else if (c == 'r')
        {
            int num;
            scanf("%d", &num);

            rm_hash_table(h, num);
        }
        else if (c == 'i')
        {
            print_hash_table(h);
        }
    }
}