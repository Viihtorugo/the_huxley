#include <stdio.h>

void fat(int f[], int m)
{
    f[0] = 1;

    for (int i = 1; i <= m; i++)
        f[i] = f[i - 1] * i;
    
}

void solve (int m, int n1, int n2, int n3)
{
    int f[m + 1];

    fat(f, m);

    printf("%d\n", f[n1] + f[n2] + f[n3]);
}

int main ()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int maior;

    if (n1 > n2)
    {
        if (n1 > n3)
        {
            maior = n1;
        }
        else
        {
            maior = n3;
        }
    }
    else
    {
        if (n2 > n3)
        {
            maior = n2;
        }
        else
        {
            maior = n3;
        }
    }

    solve(maior, n1, n2, n3);

    return 0;
}