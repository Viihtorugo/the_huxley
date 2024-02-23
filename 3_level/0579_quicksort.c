#include <stdio.h>

void swap (int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int partition(int array[], int p, int r)
{
    if (p > r)
        return p - 1;

    int x = array[r];

    printf("Pivot: %d\n", x);

    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (array[j] <= x)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    
    i++;

    swap(&array[i], &array[r]);
    
    printf("Partition(A,%d,%d):", p + 1, r + 1);

    int v = 1;

    for (int j = p; j <= r; j++)
    {
        if (j + 1 != r && array[j] == x && array[j + 1] != x && v)
        {   
            if (j == r)
            {
                printf(" <= %d <\n", array[j]);
            }
            else
            {
                printf(" <= %d <", array[j]);
            }

            v = 0;
        }
        else
        {
            if (j == r)
            {
                printf(" %d\n", array[j]);
            }
            else
            {
                printf(" %d", array[j]);
            }
        }
    }
    
    return i;
}

void quicksort(int array[], int p, int r, int tam)
{
    if (p < r)
    {
        printf("\n");
        int q = partition(array, p, r);

        printf("Estado atual de A:");

        for (int i = 0; i < tam; i++)
        {
            if (i + 1 != tam)
            {
                printf(" %d |", array[i]);
            }
            else
            {
                printf(" %d\n", array[i]);
            }
        }

        quicksort(array, p, q - 1, tam);
        quicksort(array, q + 1, r, tam);
    }
}

int main ()
{
    int array[1000000];
    int tam = 0;

    while (scanf("%d", &array[tam]) != EOF) 
        tam++;

    printf("Estado inicial:");

    for (int i = 0; i < tam; i++)
    {
        if (i + 1 != tam)
        {
            printf(" %d |", array[i]);
        }
        else
        {
            printf(" %d\n", array[i]);
        }
    }

    quicksort(array, 0, tam - 1, tam);

    printf("\nResultado Final:");

    for (int i = 0; i < tam; i++)
    {
        if (i + 1 != tam)
        {
            printf(" %d |", array[i]);
        }
        else
        {
            printf(" %d\n", array[i]);
        }
    }

    return 0;
}