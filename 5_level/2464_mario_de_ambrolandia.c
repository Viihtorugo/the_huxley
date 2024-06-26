#include <stdio.h>
#include <limits.h>

int check(int map[], int n, int pulo)
{
    for (int i = 0; i < n; i++)
    {
        if (map[i])
        {
            i = i + pulo;
        }

        if (i < n && map[i])
            return 0;
    }

    return 1;
}

int min_pulo(int array[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (array[i])
        {
            int count = 1;
            i++;

            while (i < n && array[i])
            {
                count++;
                i++;
            }

            if (max < count)
                max = count;
        }
    }

    return max;
}

int main()
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

    int map[max + 2];

    for (int i = 0; i < max + 2; i++)
        map[i] = 0;

    for (int i = 0; i < n; i++)
        map[p[i]] = 1;

    for (int i = 0; i < max + 1; i++)
        printf("%d", map[i]);

    printf("\n");

    int min = min_pulo(map, max + 2);

    if (min != 1)
    {

        if (check(map, max + 1, min))
        {
            printf("Pulo minimo: %d\n", min);
        }
        else
        {
            int pulo;
            for (pulo = min; pulo < max + 1; pulo++)
            {
                int i;
                for (i = 0; i < max + 2 && !map[i]; i++)
                {
                    int pular = 0;

                    for (int j = i; i + pulo <= max + 1 && j < i + pulo && !pular; j++)
                        if (map[j])
                            pular = 1;

                    if (pular)
                        i = i + pulo;
                }

                printf("i = %d e pulo = %d\n", i, pulo);
                if (i > max + 1)
                    break;
            }

            printf("Pulo minimo: %d\n", pulo);
        }
    }
    else
    {
        printf("Pulo minimo: %d\n", min);
    }
}