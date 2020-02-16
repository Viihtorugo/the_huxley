#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node {
    int age;
    char name[256];
    node *next;
};

int is_empty_list (node *list)
{
    return (list == NULL);
}

node *create_list ()
{
    return NULL;
}

node *create_node()
{
    node *node_data = (node *) malloc (sizeof(node));
    
    node_data->next = NULL;

    return node_data;
}

node *add (node *list, int age, char name[])
{
    node *new_node = create_node();

    strcpy(new_node->name, name);

    new_node->age = age;

    if (is_empty_list(list))
    {
        list = new_node;
    }
    else
    {
        node *current = list;

        while (current->next != NULL)
            current = current->next;
        
        current->next = new_node;
    }
    
    return list;
}

int search (node *list, int age)
{
    node *current = list;
    int friends = 1;

    while (current != NULL)
    {
        if (current->age == age)
        {
            friends = 0;
            printf("%s", current->name);
        }

        if (current->next == NULL && !friends)
        {
            printf("\n");
        }
        else if ((current->next != NULL) && (current->next->age == age) && !friends)
        {
            printf(" ");
        }

        current = current->next;
    }

    return friends;
}

void free_list (node *list)
{
    while (list != NULL)
    {
        node *current = list;

        list = list->next;

        free(current);
    }

    free(list);
}

void loop(node *list, int n)
{
    if (n > 0)
    {
        char name[256];
        int age;

        scanf("%s %d", name, &age);

        list = add(list, age, name);

        return loop(list, n - 1);
    }

    int age_search;

    scanf("%d", &age_search);

    if (search(list, age_search))
        printf("Eleven nao tem amigos com essa idade.\n");

    free_list(list);
}

int main ()
{
    node *list = create_list();

    int n;
    scanf("%d", &n);

    loop(list, n);

    return 0;
}