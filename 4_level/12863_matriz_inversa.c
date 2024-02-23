#include <stdio.h>

int check(long long int n, long long int m[][n], long long int t[][n])
{
    long long int I[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            I[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                I[i][j] += m[i][k] * t[k][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lld", I[i][j]);

            if (j + 1 == n)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }

    long long int sum_zeros = 0, sum_d = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (I[i][j] == 0)
                sum_zeros++;
    
    for (int i = 0; i < n; i++)
        if(I[i][i] == 1)
            sum_d++;
    
    if (sum_zeros + n == n * n && sum_d == n)
        return 1;

    return 0;
}

int main ()
{
    int n;
    scanf("%d", &n);

    long long int m[n][n];
    long long int t[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lld", &m[i][j]);
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lld", &t[i][j]);
    
    if (check(n, m, t))
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }

    return 0;
}