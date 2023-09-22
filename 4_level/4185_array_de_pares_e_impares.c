#include <stdio.h>

void set_arrays(int i, int n, int p[], int im[], int *m1, int *m2)
{
    if (i < n)
    {
        int num;
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            p[*m1] = num;
            *m1 = *m1 + 1;
        }
        else
        {
            im[*m2] = num;
            *m2 = *m2 + 1;
        }

        set_arrays(i + 1, n, p, im, m1, m2);
    }
}

int main ()
{
    int n, m1 = 0, m2 = 0;
    scanf("%d", &n);

    int p[n], im[n];

    set_arrays(0, n, p, im, &m1, &m2);

    for (int i = 0; i < m1; i++)
        printf("pares[%d] = %d\n", i, p[i]);
    
    for (int i = 0; i < m2; i++)
        printf("impares[%d] = %d\n", i, im[i]);

    return 0;
}