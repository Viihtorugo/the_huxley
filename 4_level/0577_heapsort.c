#include <stdio.h>
#include <stdlib.h>

typedef struct heap heap;

struct heap
{
    int size;
    int *data;
};


int is_empty_heap (heap *h)
{
    return (h == NULL);
}

struct heap *create_heap ()
{
    heap *h = (struct heap *) malloc(sizeof(struct heap));
    
    if (is_empty_heap(h))
    {
        printf("Core Dump (Segmentation fault)\n");
        return NULL;
    }

    h->size = 0;
    h->data = (int *) malloc(sizeof(int));

    if (h->data == NULL)
    {
        printf("Core Dump (Segmentation fault)\n");
        h->data = NULL;
    }

    return h;
}

void realloc_data (heap *h)
{
    h->data = (int *) realloc(h->data, (h->size + 2) * sizeof(int));
}

int get_parent_index (int i)
{
    return i/2;
}

int get_left_index (int i)
{
    return i*2;
}

int get_right_index (int i)
{
    return (i*2) + 1;
}

void swap (int *n1, int *n2)
{
    int aux = *n1;
    *n1               = *n2;
    *n2               = aux;
}

void enqueue (heap *h, int item)
{
    h->data[++h->size] = item;
        
    int key_index = h->size;
    int parent_index = get_parent_index (h->size);

    while ((parent_index >= 1) && 
            (h->data[key_index] > h->data[parent_index]))
    {
        swap(&h->data[key_index], &h->data[parent_index]);

        key_index = parent_index;

        parent_index = get_parent_index(key_index);
    }
}

void max_heapify (struct heap *heap, int i)
{
    int largest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);

    if ((left_index <= heap->size) && 
        (heap->data[left_index] > heap->data[i]))
    {
        largest = left_index;
    }
    else
    {
        largest = i;
    }

    if ((right_index <= heap->size) && 
        (heap->data[right_index] > heap->data[largest]))
    {
        largest = right_index;
    }

    if (heap->data[i] != heap->data[largest] )
    {
        swap(&heap->data[i], &heap->data[largest]);
        max_heapify(heap, largest);
    }
} 

int dequeue (struct heap *heap)
{
    if (is_empty_heap(heap))
    {
        printf("Heap Underflow\n");
        return -1;
    }

    int dequeued = heap->data[1];

    heap->data[1] = heap->data[heap->size];
    heap->size -= 1;

    max_heapify (heap, 1);

    return dequeued;
}

void heapsort (heap *h)
{
    int i, j;

    for (i = h->size; i >= 1; i--)
    {
        printf("Estado Atual da Heap:");
        for (j = 1; j < h->size + 1; j++)
        {
            if (j + 1 != h->size + 1)
            {
                printf(" %d |", h->data[j]);
            }
            else
            {
            printf(" %d\n", h->data[j]);
            }   
        }

        if (i != 1)
        {
            printf("Maior elemento neste passo: %d\n", h->data[1]);
            swap(&h->data[1], &h->data[i]);
            h->size--;
            max_heapify(h, 1);
        }
    }
}

/*
void search_with_heap (heap *h, int item, int index, int* count)
{
    int index_left = get_left_index(index);
    int index_right = get_right_index(index);

 == h->data[index])
    {
        *count += 1;
        if (item == h->data[index])
        {
            // *count += 1;
            return;
        }
        else if ((*count += 1) == == h->data[index_)
        {
            // *count += 1;
            search_with_heap(h, , index_left, count);
        }
        else if ((*count += 1) == == h->data[index_r)
        {
            // *count += 1;
            search_with_heap(h, , index_right, count);
        }
        
    }

    if (index > h->size)
        return;

    *count += 1; > h->data[index_)
    {
        search_with_heap(h, , index_right, count);
    }
    else
    {
        *count += 1;
        search_with_heap(h, , index_left, count);
    }
}
*/

void loop (heap *h, int *array, int *n)
{
    int item;

    if (scanf("%d", &item) != EOF)
    {

        realloc_data(h);
        
        enqueue(h, item);
        array[*n] = item;
        *n += 1;

        loop(h, array, n);
    }
}

int main ()
{
    heap *h = create_heap();
    int array[10000], n = 0;

    loop(h, array, &n);


    int i;
    printf("Estado inicial:");
    for ( i = 0; i < n; i++)
    {
        if (i + 1 != n)
        {
            printf(" %d |", array[i]);
        }
        else
        {
            printf(" %d\n", array[i]);
        }
        
    }
    
    heapsort(h);
    
    printf("Resultado Final:");
    for ( i = 1; i < n + 1; i++)
    {
        if (i + 1 != n + 1)
        {
            printf(" %d |", h->data[i]);
        }
        else
        {
            printf(" %d\n", h->data[i]);
        }
        
    }
    
    free(h);
    return 0;
}