#include <stdio.h>
#include <limits.h>

int count (int array[], int n, int *i)
{
    int count = 0;

    while (*i < n && array[*i])
    {
        count++;
        *i += 1;
    }
    
    return count;
}

int main ()
{
    int n, max = 1;
    scanf("%d", &n);

    int p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);

        if (p[i] > max)
            max = p[i];
    }
    
    int map[max + 1];
    
    for (int i = 0; i < max + 1; i++)
        map[i] = 0;

    for (int i = 0; i < n; i++)
        map[p[i]] = 1;
    
    for (int i = 0; i < max + 1; i++)
        printf("%d", map[i]);
    
    printf("\n");
    
    int min = INT_MIN;

    for (int i = 0; i < max + 1; i++)
    {
        if (map[i])
        {
            int aux = count(map, max + 1, &i);

            if (aux > min)
                min = aux;
        }
    }
    
    printf("Pulo minimo: %d\n", min);
}