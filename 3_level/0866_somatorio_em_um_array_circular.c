#include <stdio.h>

int sum (int array[], int init, int i, int n, int size)
{
    if (i < n)
    {
        return array[(init + i) % size] + sum (array, init, i + 1, n, size);
    }

    return 0;
}


int main ()
{
    int n;
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    int init, num_sum;
    scanf("%d %d", &init, &num_sum);

    printf("%d\n", sum(array, init, 0, num_sum, n));

    return 0;
}