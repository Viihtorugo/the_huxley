#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct queue queue;
typedef struct priority_queue priority_queue;

struct node {
    int item;
    node *next;
};

struct queue {
    node *head;
};

struct priority_queue
{
    node *head;
};


int is_empty_queue(queue *queue)
{
    return (queue->head == NULL);
}

int is_empty_priority_queue(priority_queue *pq)
{
    return (pq->head == NULL);
}

queue *create_queue ()
{
    queue *q = (queue *) malloc(sizeof(queue));

    if (q == NULL)
    {
        printf("Segment fault (memory);\n");
        return NULL;
    }

    q->head = NULL;

    return q;
}

priority_queue *create_priority_queue ()
{
    priority_queue *pq = (priority_queue *) malloc(sizeof(queue));

    if (pq == NULL)
    {
        printf("Segment fault (memory);\n");
        return NULL;
    }

    pq->head = NULL;

    return pq;
}

void enqueue_queue (queue *q, int item)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->item = item;
    new_node->next = NULL;

    if (is_empty_queue(q))
    {
        q->head = new_node;
    }
    else
    {
        node *current = q->head;
        
        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
    
}

void enqueue_priority_queue (priority_queue *pq, int item)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->item = item;
    new_node->next = NULL;

    if (is_empty_priority_queue(pq) || item > pq->head->item)
    {
        new_node->next = pq->head;
        pq->head = new_node;
    }
    else
    {
        node *current = pq->head;
        node *previous;

        while (current != NULL && current->item >= item)
        {
            previous = current;
            current = current->next;
        }

        new_node->next = current;
        previous->next = new_node;
    }
    
}

int count (node *pq, node *q)
{
    if (pq != NULL && q != NULL)
    {
        if (pq->item == q->item)
            return 1 + count(pq->next, q->next);
        
        return count(pq->next, q->next);
    }

    return 0;
}

void free_queue(queue *q)
{

    while (q->head != NULL)
    {
        node *current = q->head;

        q->head = q->head->next;

        free(current);
    }

    free(q);
}

void free_priority_queue(priority_queue *pq)
{

    while (pq->head != NULL)
    {
        node *current = pq->head;

        pq->head = pq->head->next;

        free(current);
    }

    free(pq);
}

void print_queue (queue *q)
{
    node *current = q->head;

    while (current != NULL)
    {
        if (current->next != NULL)
        {
            printf("%d ", current->item);
        }
        else
        {
            printf("%d\n", current->item);
        }

        current = current->next;
    }
}

void print_priority_queue (priority_queue *pq)
{
    node *current = pq->head;

    while (current != NULL)
    {
        if (current->next != NULL)
        {
            printf("%d ", current->item);
        }
        else
        {
            printf("%d\n", current->item);
        }

        current = current->next;
    }
}

void loop(int n)
{
    if (n > 0)
    {
        int n_items, i;
        scanf("%d", &n_items);

        queue *q = create_queue();
        priority_queue *pq = create_priority_queue();

        for (i = 0; i < n_items; i++)
        {
            int item;
            scanf("%d", &item);

            enqueue_queue(q, item);
            enqueue_priority_queue(pq, item);
        }

        //print_priority_queue(pq);
        //print_queue(q);

        printf("%d\n", count(pq->head, q->head));

        free_queue(q);
        free_priority_queue(pq);

        return loop(n - 1);
    }
}

int main ()
{

    int n;
    scanf("%d", &n);

    loop(n);

    return 0;
}