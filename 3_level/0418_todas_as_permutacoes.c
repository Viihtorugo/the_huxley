#include <stdio.h>

void permutacao_bactracking(int res[], int n, int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", res[i]);
        
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int r = 1;

        for(int j = 0; j < n; j++)
        {
            if (res[j] == i + 1)
            {
                r = 0;
                break;
            }
        }

        if (r)
        {
            res[k] = i + 1;
            permutacao_bactracking(res, n, k + 1);
            res[k] = 0;
        }
    }
    
}

int main ()
{   
    int n;
    scanf("%d", &n);

    int res[n];

    for (int i = 0; i < n; i++)
        res[i] = 0;

    permutacao_bactracking(res, n, 0);

    return 0;
}