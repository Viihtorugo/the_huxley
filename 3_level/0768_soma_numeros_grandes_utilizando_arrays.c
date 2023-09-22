#include <stdio.h>

void print_sum (int a1[], int a2[], int i, int n, int m, int ac)
{
    int dif = n - m;

    if (dif >= 0)
    {
        dif = 0;
    }
    else
    {
        dif = dif * (-1);
    }

    if (i < n + dif)
    {
        int d = 0;

        if (i < n)
            d += a1[i];

        if (i < m)   
            d += a2[i];

        d += ac;
        ac = d / 10;

        print_sum(a1, a2, i + 1, n, m, ac);

        if (i + 1 == n + dif)
        {
            printf("%d", d);
        }
        else
        {
            printf("%d", d%10);
        }
    }
}

int main ()
{
    int n;
    scanf("%d", &n);

    int a1[n];

    for (int i = n - 1; i >= 0; i--)
        scanf("%d", &a1[i]);
    
    int m;
    scanf("%d", &m);

    int a2[m];

    for (int i = m - 1; i >= 0; i--)
        scanf("%d", &a2[i]);

    print_sum(a1, a2, 0, n, m, 0);
    printf("\n");

    return 0;
}