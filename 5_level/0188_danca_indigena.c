#include <stdio.h>

int equal(int array[], int init[], int n)
{
    n -= 1;

    while (n >= 0)
    {
        int elem_init = init[n];
        int elem_array = init[n];

        if (elem_init < 0)
            elem_init *= (-1);

        if (elem_array < 0)
            elem_array *= (-1);

        if (elem_array != elem_init)
            return 0;

        n -= 1;
    }

    return 1;
}

int next (int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] != 0)
            return i;
    }
    
    return 0;
}

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);

    int array[n], init[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
        init[i] = 0;
    }

    while (e > 0)
    {
        int index, m;
        scanf("%d %d", &index, &m);

        array[index - 1] = m;
        init[index - 1] = m;

        e--;
    }

    int count = 0;


    printf("Array antes: ");
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
        {
            printf("%d\n", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }

    do
    {
        int sum = next(array, n);
        for (int i = 0 + sum; i < n + sum; i++)
        {
            if (array[i % n] == 1 || array[i % n] == 2)
            {
                if (array[(i + 1) % n] == 0)
                {
                    array[i % n] -= 1;
                    array[(i + 1) % n] += 1;
                }
                else if (array[(i + 1) % n] == 1)
                {
                    array[i % n] -= 1;
                    array[(i + 1) % n] += 1;
                }
            }

            printf("Array durante: ");
            for (int k = 0; k < n; k++)
            {
                if (k + 1 == n)
                {
                    printf("%d\n", array[k]);
                }
                else
                {
                    printf("%d ", array[k]);
                }
            }
        }

        printf("Array depois: ");
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == n)
            {
                printf("%d\n", array[i]);
            }
            else
            {
                printf("%d ", array[i]);
            }
        }

        break;
        count += 1;
    } while (equal(array, init, n));

    printf("%d\n", count);

    return 0;
}